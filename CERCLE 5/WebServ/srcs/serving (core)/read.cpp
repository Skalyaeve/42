#include "../../includes/header.hpp"

// Assigne a une variable l'locaIndex d'une location
bool locaIndexFromURI(const std::string& name, t_serv& serv, std::size_t& locaIndex)
{
	for (locaIndex = 0; locaIndex < serv.locations.size(); locaIndex++)
	{
		const std::string subStr(name.substr(0, serv.locations[locaIndex].name.size()));
		if (subStr == serv.locations[locaIndex].name)
			return true;
	}
	return false;
}

// Remplis les infos de la premiere ligne de la requete en cours
unsigned short read1stLine(std::istringstream& stream, std::string* retMsg)
{
	std::string line;
	if (std::getline(stream, line))
	{
		std::istringstream streamBis(line);
		std::string word;

		// Méthode
		if (!(streamBis >> word))
		{
			*retMsg = "Bad Request";
			return ERR_BAD_REQ;
		}
		const std::string method = word;
		if (method != "GET" && method != "POST" && method != "DELETE")
		{
			*retMsg = "Not Implemented";
			return ERR_UNKN_METHOD;
		}

		// URI
		if (!(streamBis >> word))
		{
			*retMsg = "Bad Request";
			return ERR_BAD_REQ;
		}
		const std::string uri = word;

		// Protocole
		if (!(streamBis >> word))
		{
			*retMsg = "Bad Request";
			return ERR_BAD_REQ;
		}
		if (word != "HTTP/1.1")
		{
			*retMsg = "HTTP Version Not Supported";
			return ERR_HTTP_VERSION;
		}
		
		data()->request["Method"] = method;
		data()->request["URI"] = uri;
		// std::cout << "New [key: value] -> " << "Method: " << method << std::endl;
		// std::cout << "New [key: value] -> " << "URI: " << uri << std::endl;
    }
	return 0;
}

// Remplis les infos de la requete en cours
bool read2request(const std::string &request, t_serv& serv, const int &newSocket)
{
	// On initialise une nouvelle requete
	data()->request = std::map< std::string, std::string >();

	std::istringstream stream(request);
	std::string retMsg;
	const unsigned short ret = read1stLine(stream, &retMsg);

	std::size_t locaIndex;
	if (!locaIndexFromURI(data()->request["URI"], serv, locaIndex))
		locaIndexFromURI("/", serv, locaIndex);
    if (ret)
		return sendError(ret, retMsg, newSocket, serv, serv.locations[locaIndex]);
	
	// Pour chaque en-tete, une nouvelle valeur pour notre map
	bool bodyInc = false;
	std::string line;
	while (!bodyInc && std::getline(stream, line))
	{
		std::istringstream streamBis(line);
		std::string key;
		std::string value;
	
		if (line == "\r")
			bodyInc = true;
	
		streamBis >> key;
		streamBis >> value;
		if (!key.size() || !value.size())
			return sendError(ERR_BAD_REQ, "Bad Request", newSocket, serv, serv.locations[locaIndex]);

		if (key[key.size() - 1] != ':')
			return sendError(ERR_BAD_REQ, "Bad Request", newSocket, serv, serv.locations[locaIndex]);
		key.erase(key.size() - 1);
		data()->request[key] = value;
		// std::cout << "New [key: value]-> " << key << ": " << value << std::endl;
	}
	// Saut de line obligatoire
	if (!bodyInc)
		return sendError(ERR_BAD_REQ, "Bad Request", newSocket, serv, serv.locations[locaIndex]);

	// On read le body pour une methode POST
	if (data()->request["Method"] == "POST")
	{
		data()->request["Body"] = std::string();
		while (std::getline(stream, line))
			data()->request["Body"] += line + '\n';
		// std::cout << "New [key: value] -> " << "Body: " << std::endl << data()->request["Body"] << std::endl;
	}
	return true;
}

bool findBody(const std::string &buffer, std::size_t &bodySize)
{
	const std::string marker = "\n\n\r\n";
    const std::size_t pos = buffer.find(marker);

    if (pos == std::string::npos)
        return false;

    bodySize = buffer.size() - (pos + marker.size());
    return true;
}

// Lit depuis un socket
bool read2socket(const int &newSocket, std::string &request, t_serv& serv)
{
	char buffer[BUFFER_SIZE];
	ssize_t readed = BUFFER_SIZE;
	std::size_t bodySize = 0;
	bool bodyInc = false;

	// On read depuis la socket
	while (readed == BUFFER_SIZE && bodySize < static_cast< std::size_t >(serv.maxBodySize * ONE_MO))
	{
		ft::memset(buffer, 0, BUFFER_SIZE);
    	readed = recv(newSocket, buffer, BUFFER_SIZE, 0);
    	if (readed < 0)
		{
			std::cerr << "[ ERROR ] recv() failed for " << newSocket << std::endl;
			return false;
		}
		else if (readed == 0)
    	    break;
		request += buffer;
		if (bodyInc)
    		bodySize += readed;
		else
			bodyInc = findBody(buffer, bodySize);
	}

	// Erreur si le body de la requete > clientMaxBodySize
	if (bodySize > static_cast< std::size_t >(serv.maxBodySize * ONE_MO))
	{
		// On cherche depuis quel root de location chercher la page d'erreur
		data()->request = std::map< std::string, std::string >();
		std::istringstream stream(request);
		read1stLine(stream, NULL);

		std::size_t locaIndex;
		std::string uri;
		if (data()->request.find("URI") == data()->request.end())
			uri = "/";
		else
			uri = data()->request["URI"];
		
		if (!locaIndexFromURI(uri, serv, locaIndex))
		{
			uri = "/";
			locaIndexFromURI(uri, serv, locaIndex);
		}
		return sendError(ERR_BODY_2LARG, "Payload Too Large", newSocket, serv, serv.locations[locaIndex]);
	}

	std::cout << request << std::endl;
	std::cout << "-----------------------" << std::endl;
	return read2request(request, serv, newSocket);
}
