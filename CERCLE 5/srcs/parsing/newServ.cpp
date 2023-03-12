#include "../../includes/header.hpp"

// Convertis une ip ou un int string en uint32_t
long strToID(const std::string &str)
{
	t_addrinfo hints;
	t_addrinfo *results;
	ft::memset(&hints, 0, sizeof(hints));

	// Convertis la string en uint32_t network
	hints.ai_family = AF_INET;
	if (getaddrinfo(str.c_str(), NULL, &hints, &results) != 0)
		return -1;

	// Convertis le uint32_t network en uint32_t host
	uint32_t id = ntohl(((t_sockaddr_in *)results->ai_addr)->sin_addr.s_addr);
	freeaddrinfo(results);
	return id;
}

// Remplie une combinaison IP:PORT
bool getIpPort(std::string &value, std::vector< std::pair< uint32_t, uint16_t > > &ref)
{
	long tmp;
	uint32_t ip;
	uint16_t port;

	// Check de l'IP
	if (value.find_first_not_of(".0123456789:") != std::string::npos)
		return false;
	if (value.find_first_of(":") != std::string::npos)
	{
		if (std::count(value.begin(), value.end(), ':') > 1)
			return false;
		std::string ipChunk(value.substr(0, value.find_first_of(":")));
		if ((tmp = strToID(ipChunk)) == -1)
			return false;
		ip = static_cast< uint32_t >(tmp);
		value = value.substr(value.find_first_of(":") + 1, value.size());
	}

	// Check du port
	if (value.find_first_not_of("0123456789") != std::string::npos)
		return false;
	tmp = strToID(value);
	if (tmp <= 0 || tmp > 65535)
		return false;
	port = tmp;

	// On vérifie les doublons
	for (std::size_t x = 0; x < ref.size(); x++)
		if (ref[x].first == ip && ref[x].second == port)
			return false;

	ref.push_back(std::pair< uint32_t, uint16_t >(ip, port));
	return true;
}

// Remplis une struct de bloc serveur avec des valeurs par défaut
void fillServ(t_serv &ref)
{
	std::string ip_port = "0.0.0.0";
	if (!ref.ip_port.size())
		getIpPort(ip_port, ref.ip_port);
	for (std::size_t x = 0; x < ref.locations.size(); x++)
		if (ref.locations[x].name == "/")
			return;
	ref.locations.push_back(initLoca("/"));
}

// Parse un bloc serveur
bool parseServ(std::ifstream &config, std::size_t &configLine)
{
	t_serv serv;

	// Keywords
	const std::string keywords[] = {"listen", "serverName", "errorPage", "location", "}", "#", "clientMaxBodySize"};
	const std::vector< std::string > keys(keywords, keywords + sizeof(keywords) / sizeof(std::string));

	// Parse le bloc
	std::string line;
	bool stop = false;
	short maxBodySize = -1;
	while (!stop && std::getline(config, line))
	{
		std::ostringstream lineIndex;
		std::istringstream stream(line);
		std::string word;

		configLine++;
		lineIndex << configLine;
		// Parse une ligne
		bool stopBis = false;
		while (!stopBis && !stream.fail() && (stream >> word))
		{
			switch (std::ptrdiff_t dist = std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
			{
			case (0):
				 // IP:PORT d'écoute
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				if (!getIpPort(word, serv.ip_port))
					return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (1):
				// Nom de serveur
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				while (!stream.fail())
				{
					serv.serverName.push_back(word);
					stream >> word;
				}
				break;
			case (2):
				// Page d'erreur
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				while (!stream.fail())
				{
					serv.errorPages.push_back(word);
					stream >> word;
				}
				break;
			case (3):
				// Bloc location
				if (!setupLoca(config, stream, &serv, NULL, configLine))
					return false;
				break;
			case (4):
				// Fin de bloc
				stop = true;
				break;
			case (5):
				// Commentaire
				stopBis = true;
				break;
			case (6):
				// clientMaxBodySize
				if (maxBodySize != -1)
                    return configError("[ ERROR ] " + keywords[6] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[6] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				if ((maxBodySize = getmaxBodySize(word)) >= 0)
					break;
				else
					return configError("[ ERROR ] " + keywords[6] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[6] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
			default:
				return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
			}
		}
	}
	std::ostringstream lineIndex;
	lineIndex << configLine;
	if (!stop)
		return configError("[ ERROR ] server: " + lineIndex.str() + ERR_NO_BRK, false, 0);

	// Remplis les valeurs unset du bloc
	serv.maxBodySize = maxBodySize;
	fillServ(serv);

	data()->servList.push_back(serv);
	return true;
}
