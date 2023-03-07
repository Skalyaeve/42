#include "../includes/header.hpp"

// Singleton Singleton Singleton-ton-ton
t_data* data(void)
{
	static t_data global;
	return &global;
}

// Setup un socket
bool setup(t_serv& serv)
{
	// Init le socket
	serv.serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (serv.serverFd == -1)
	{
		std::cerr << "[ ERROR ] Can't create server socket" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}

	// Setup l'addresse
	serv.address.sin_family = AF_INET;
	serv.address.sin_addr.s_addr = serv.ip;
    for (std::size_t x = 0; x < serv.port.size(); x++)
		serv.address.sin_port = htons(serv.port[x]);

	// Bind le socket a l'addresse
	std::cout << "Server socket created : " << serv.serverFd << std::endl;
	if (bind(serv.serverFd, reinterpret_cast<t_sockaddr*>(&(serv.address)), sizeof(serv.address)) < 0)
	{
		std::cerr << "[ ERROR ] Can't bind server socket on " << serv.serverFd;
		std::cerr << ntohl(serv.address.sin_addr.s_addr) << ":" << ntohs(serv.address.sin_port) << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(serv.serverFd);
		return false;
	}

	// Run le socket
	if (listen(serv.serverFd, MAX_CONNECTION) < 0)
	{
		std::cerr << "[ ERROR ] Can't listen on server socket " << serv.serverFd;
		std::cerr << " ( " << ntohl(serv.address.sin_addr.s_addr) << ":" << ntohs(serv.address.sin_port) << " )" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(serv.serverFd);
		return false;
	}
	std::cout << "Listenin : " << ntohl(serv.address.sin_addr.s_addr) << ":" << ntohs(serv.address.sin_port) << std::endl;
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
		return EXIT_FAILURE;
	}
	if (!init(av[1]))
		return EXIT_FAILURE;

	// Setup les sockets
	for (std::size_t x = 0; x < data()->servList.size(); x++)
		if (!setup(data()->servList[x]))
			return EXIT_FAILURE;

	// Start le service
	return (serv() ? EXIT_SUCCESS : EXIT_FAILURE);
}
