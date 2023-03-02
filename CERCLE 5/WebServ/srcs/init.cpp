#include "../includes/header.hpp"

bool init(int* serverFd, t_sockaddr_in* address)
{
	*serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (*serverFd == -1)
	{
		std::cerr << "[ ERROR ] Can't create server socket" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}
	(*address).sin_family = AF_INET;
	(*address).sin_addr.s_addr = htonl(IP);
	(*address).sin_port = htons(PORT);

	std::cout << "Server socket created : " << *serverFd << std::endl;
	if (bind(*serverFd, reinterpret_cast<t_sockaddr*>(address), sizeof(*address)) < 0)
	{
		std::cerr << "[ ERROR ] Can't bind server socket on " << *serverFd;
		std::cerr << ntohl((*address).sin_addr.s_addr) << ":" << ntohs((*address).sin_port) << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(*serverFd);
		return false;
	}
	if (listen(*serverFd, MAX_CONNECTION) < 0)
	{
		std::cerr << "[ ERROR ] Can't listen on server socket " << *serverFd;
		std::cerr << " ( " << ntohl((*address).sin_addr.s_addr) << ":" << ntohs((*address).sin_port) << " )" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(*serverFd);
		return false;
	}
	std::cout << "Listenin : " << ntohl((*address).sin_addr.s_addr) << ":" << ntohs((*address).sin_port) << std::endl;
	std::cout << "--------------------->> " << std::endl;
	return true;
}

bool setup(char* path)
{
	std::ifstream config(path);
	if (!config)
	{
		std::cerr << "[ ERROR ] Can't open config file" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}
	config.close();
	return true;
}

int main(int ac, char** av)
{
	int serverFd;
	t_sockaddr_in address;

	if (ac != 2)
	{
		std::cerr << "[ ERROR ] Usage : ./webserv [configuration file]" << std::endl;
		return EXIT_FAILURE;
	}
	if (!setup(av[1]))
		return EXIT_FAILURE;
	if (!init(&serverFd, &address))
		return EXIT_FAILURE;
	if (!serv(&serverFd, &address))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
