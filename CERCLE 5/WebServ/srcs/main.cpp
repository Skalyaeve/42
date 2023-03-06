#include "../includes/header.hpp"

// Singleton Singleton Singleton-ton-ton
t_data* data(void)
{
	static t_data global;
	return &global;
}

// Delete un bloc location
void deleteLocation(const t_location* location)
{
	delete location->indexPages;
	for (std::size_t z = 0; z < location->locaCount; z++)
		deleteLocation(location->locations[z]);
	delete location;
}

// Exit le programme
int exitPlease(const short code)
{
	// Delete les serveurs
	for (std::size_t x = 0; x < data()->servCount; x++)
	{
		// Delete les pages d'erreur des serveurs
		delete data()->servList[x]->errorPages;
	
		// Delete les blocs location des serveurs
		for (std::size_t y = 0; y < data()->servList[x]->locaCount; y++)
			deleteLocation(data()->servList[x]->locations[y]);

		delete data()->servList[x];
	}
	if (data()->servCount)
		delete[] data()->servList;

	return code;
}

// Setup un socket
bool setup(const unsigned short index)
{
	// Init le socket
	data()->servList[index]->serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (data()->servList[index]->serverFd == -1)
	{
		std::cerr << "[ ERROR ] Can't create server socket" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}

	// Setup l'addresse
	data()->servList[index]->address.sin_family = AF_INET;
	data()->servList[index]->address.sin_addr.s_addr = htonl(IP);
	data()->servList[index]->address.sin_port = htons(data()->servList[index]->port);

	// Bind le socket a l'addresse
	std::cout << "Server socket created : " << data()->servList[index]->serverFd << std::endl;
	if (bind(data()->servList[index]->serverFd, reinterpret_cast<t_sockaddr*>(&(data()->servList[index]->address)), sizeof(data()->servList[index]->address)) < 0)
	{
		std::cerr << "[ ERROR ] Can't bind server socket on " << data()->servList[index]->serverFd;
		std::cerr << ntohl(data()->servList[index]->address.sin_addr.s_addr) << ":" << ntohs(data()->servList[index]->address.sin_port) << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(data()->servList[index]->serverFd);
		return false;
	}

	// Run le socket
	if (listen(data()->servList[index]->serverFd, MAX_CONNECTION) < 0)
	{
		std::cerr << "[ ERROR ] Can't listen on server socket " << data()->servList[index]->serverFd;
		std::cerr << " ( " << ntohl(data()->servList[index]->address.sin_addr.s_addr) << ":" << ntohs(data()->servList[index]->address.sin_port) << " )" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(data()->servList[index]->serverFd);
		return false;
	}
	std::cout << "Listenin : " << ntohl(data()->servList[index]->address.sin_addr.s_addr) << ":" << ntohs(data()->servList[index]->address.sin_port) << std::endl;
	std::cout << "--------------------->> " << std::endl;

	return true;
}

// Let's goow
int main(int ac, char** av)
{
	// Init webServ
	if (ac != 2)
	{
		std::cerr << "[ ERROR ] Usage : ./webserv [configuration file]" << std::endl;
		return exitPlease(EXIT_FAILURE);
	}
	if (!init(av[1]))
		return exitPlease(EXIT_FAILURE);

	// Setup les sockets
	for (std::size_t x = 0; x < data()->servCount; x++)
		if (!setup(x))
			return exitPlease(EXIT_FAILURE);

	// Start le service
	return (serv() ? exitPlease(EXIT_SUCCESS) : exitPlease(EXIT_FAILURE));
}
