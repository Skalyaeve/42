#include "../includes/header.hpp"

std::string answ2request(std::string request)
{
	std::string answ = "Hell oh :3";
	std::size_t eol = request.find_first_of("\r\n");
	if (eol != std::string::npos)
	{
		std::string firstLine = request.substr(0, eol);
		std::string getMethod = "GET /";
		std::size_t eoMethod = firstLine.find(getMethod);
		if (eoMethod != std::string::npos)
		{
			std::size_t eoValue = firstLine.find(' ', eoMethod + getMethod.length());
			std::string value = firstLine.substr(eoMethod + getMethod.length(), eoValue - eoMethod - getMethod.length());
			std::ifstream file(value.c_str());
			if (!file)
			{
				std::cerr << "[ ERROR ] Can't open asked ressource(s)" << std::endl;
				std::cerr << std::strerror(errno) << std::endl;
				return "Fluteu";
			}
			std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
			file.close();
			std::stringstream ss;
			ss << content.length();
			std::string header = "HTTP/1.1 200 OK\n";
			header += "Content-Type: text/html\n";
			header += "Content-Length: " + ss.str() + '\n';
			header += "Connection: keep-alive\n";
			header += "Cache-Control: max-age=0\n";
			answ = header + '\n' + content;
		}
	}
	return answ;
}

bool serv(int* serverFd, t_sockaddr_in* address)
{
	int newSocket;
	char buffer[BUFFER_SIZE];
	int addrlen = sizeof(*address);
	std::string answ;
	while (true)
	{
		if ((newSocket = accept(*serverFd, reinterpret_cast<t_sockaddr*>(address), reinterpret_cast<socklen_t*>(&addrlen))) < 0)
		{
			std::cerr << "[ ERROR ] Can't accept inc connection ";
			std::cerr << ntohl((*address).sin_addr.s_addr) << ":" << ntohs((*address).sin_port) << std::endl;
			std::cerr << std::strerror(errno) << std::endl;
		}
		if (recv(newSocket, &buffer, BUFFER_SIZE, 0) < 0)
		{
			std::cerr << "[ ERROR ] Can't read buffer from " << newSocket << std::endl;
			std::cerr << std::strerror(errno) << std::endl;
		}
		std::cout << buffer << std::endl;
		answ = answ2request(buffer);
		if (send(newSocket, answ.c_str(), answ.size(), 0) < 0)
		{
			std::cerr << "[ ERROR ] Can't answ to " << newSocket << std::endl;
			std::cerr << std::strerror(errno) << std::endl;
		}
		close(newSocket);
	}
	close(*serverFd);
	return true;
}
