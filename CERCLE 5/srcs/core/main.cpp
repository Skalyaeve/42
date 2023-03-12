#include "../../includes/header.hpp"

// Singleton Singleton Singleton-ton-ton
t_data *data(void)
{
	static t_data global;
	return &global;
}

// Setup un socket
bool setup(t_serv &serv)
{
	// Init le socket
	serv.sock_addr.push_back(std::pair< std::size_t, t_sockaddr_in >(socket(AF_INET, SOCK_STREAM, 0), t_sockaddr_in()));
	if (serv.sock_addr[0].first == -1)
	{
		std::cerr << "[ ERROR ] Can't create server socket" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}

	// Setup l'adresse
	serv.sock_addr[0].second.sin_family = AF_INET;
	serv.sock_addr[0].second.sin_addr.s_addr = htonl(0);
	serv.sock_addr[0].second.sin_port = htons(serv.ip_port[0].second);

	// Bind le socket à l'adresse
	std::cout << "Server socket created : " << serv.sock_addr[0].first << std::endl;
	if (bind(serv.sock_addr[0].first, reinterpret_cast< t_sockaddr * >(&(serv.sock_addr[0].second)), sizeof(serv.sock_addr[0].second)) < 0)
	{
		std::cerr << "[ ERROR ] Can't bind server socket on " << serv.sock_addr[0].first << std::endl;
		std::cerr << ntohl(serv.sock_addr[0].second.sin_addr.s_addr) << ":" << ntohs(serv.sock_addr[0].second.sin_port) << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(serv.sock_addr[0].first);
		return false;
	}

	// Run le socket
	if (listen(serv.sock_addr[0].first, MAX_CONNECTION) < 0)
	{
		std::cerr << "[ ERROR ] Can't listen on server socket " << serv.sock_addr[0].first << std::endl;
		std::cerr << " ( " << ntohl(serv.sock_addr[0].second.sin_addr.s_addr) << ":" << ntohs(serv.sock_addr[0].second.sin_port) << " )" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		close(serv.sock_addr[0].first);
		return false;
	}
	std::cout << "Listenin : " << ntohl(serv.sock_addr[0].second.sin_addr.s_addr) << ":" << ntohs(serv.sock_addr[0].second.sin_port) << std::endl;
	std::cout << "--------------------->>" << std::endl;

	return true;
}

// Let's goow
int main(int ac, char **av)
{
	// Init webServ
	if (ac != 2)
	{
		std::cerr << "[ ERROR ] Usage : ./webserv [configuration file]" << std::endl;
		return EXIT_FAILURE;
	}
	// Ouvre la config
	std::ifstream config;
	config.open(av[1], std::ios_base::in);
	if (!config)
		return configError("[ ERROR ] Can't open config", EXIT_FAILURE, 0);
	if (!init(config))
	{
		config.close();
		return EXIT_FAILURE;
	}
	config.close();
	printData();
	return 0;
/*	// Setup les sockets
	// for (std::size_t x = 0; x < data()->servList.size(); x++)
	if (!setup(data()->servList[0]))
		return EXIT_FAILURE;

	// Start le service
	return (serv() ? EXIT_SUCCESS : EXIT_FAILURE);*/
}
