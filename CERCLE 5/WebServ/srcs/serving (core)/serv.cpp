#include "../../includes/header.hpp"

// Check les autorisations d'une location pour une methode
bool checkMethodAuth(t_location &loca, const std::string &method, const uint32_t hostIP)
{
	for (std::size_t x = 0; x < loca.limitExcept[method].size(); x++)
		if (loca.limitExcept[method][x].first == 0 || loca.limitExcept[method][x].first == hostIP)
			return (loca.limitExcept[method][x].second == true ? true : false);
	return true;
}

// Réponds à la requête en cours
bool answ2request(t_serv &serv, std::string &answ, const int &socket)
{

	// Index de la location a utiliser
	std::size_t locaIndex;
	if (!locaIndexFromURI(data()->request["URI"], serv, locaIndex))
		locaIndexFromURI("/", serv, locaIndex);

	// Nom d'hote de la requete
	const uint32_t hostIP = strToID(data()->request["Host"], true);

	// check du serverName ??

	// Redirection vers la fonction correspondante apres check des limitExcept
	if (data()->request["Method"] == "GET")
	{
		if (!checkMethodAuth(serv.locations[locaIndex], "GET", hostIP))
			return sendError(ERR_UNALW_METHOD, "Method Not Allowed", socket, serv, serv.locations[locaIndex]);
		return ftGet(serv, serv.locations[locaIndex], answ);
	}
	if (data()->request["Method"] == "POST")
	{
		if (!checkMethodAuth(serv.locations[locaIndex], "POST", hostIP))
			return sendError(ERR_UNALW_METHOD, "Method Not Allowed", socket, serv, serv.locations[locaIndex]);
		return ftPost(serv, serv.locations[locaIndex], answ);
	}
	if (data()->request["Method"] == "DELETE")
	{
		if (!checkMethodAuth(serv.locations[locaIndex], "DELETE", hostIP))
			return sendError(ERR_UNALW_METHOD, "Method Not Allowed", socket, serv, serv.locations[locaIndex]);
		return ftDelete(serv, serv.locations[locaIndex], answ);
	}
	return sendError(ERR_INTERN, "Internal Server Error", socket, serv, serv.locations[locaIndex]);
}

// Service du serveur
bool serv(void)
{
	int newSocket;
	int addrlen = sizeof(data()->servList[0].sock_addr[0].second);
	while (true)
	{
		std::string request;
		std::string answ;
		if ((newSocket = accept(data()->servList[0].sock_addr[0].first, reinterpret_cast<t_sockaddr *>(&data()->servList[0].sock_addr[0].second), reinterpret_cast<socklen_t *>(&addrlen))) < 0)
		{
			std::cerr << "[ ERROR ] accept() failed for " << data()->servList[0].sock_addr[0].first << " from ";
			std::cerr << ntohl(data()->servList[0].sock_addr[0].second.sin_addr.s_addr) << ":" << ntohs(data()->servList[0].sock_addr[0].second.sin_port) << std::endl;
			std::cerr << std::strerror(errno) << std::endl;
		}
		//fcntl(newSocket, F_SETFL, O_NONBLOCK);
		std::string answ;
		if (!read2socket(newSocket, request, data()->servList[0])
			|| !answ2request(data()->servList[0], answ, newSocket))
		{
			close(newSocket);
			continue;
		}
		if (send(newSocket, answ.c_str(), answ.size(), 0) < 0)
			std::cerr << "[ ERROR ] send() failed to " << newSocket << std::endl;
		close(newSocket);
	}
	close(data()->servList[0].sock_addr[0].first);
	return true;
}
