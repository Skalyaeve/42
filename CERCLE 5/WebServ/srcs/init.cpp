#include "../includes/header.hpp"

// Print un message puis return false
bool configError(const std::string msg)
{
	std::cerr << msg << std::endl;
	return false;
}

// Return un maxBodySize
unsigned short getmaxBodySize(const std::string size)
{
	unsigned short ret;
	return ret;
}

// Compte le nombre de bloc serveur
std::size_t countServ(std::ifstream& config)
{
	return true;
}

// Parse un bloc serveur
bool parseServ(const std::size_t count, std::ifstream& config)
{
	return true;
}

// Setup de webServ
bool init(const char* path)
{
	// Init la singleton
	data();

	// Ouvre la config
	std::ifstream config(path);
	if (!config)
	{
		std::cerr << "[ ERROR ] Can't open config file" << std::endl;
		std::cerr << std::strerror(errno) << std::endl;
		return false;
	}

	// Init les blocs serveur
	if ((data()->servCount = countServ(config)) <= 0)
		return false;
	data()->servList = new t_serv*[data()->servCount];

	// Parse la config
	std::string line;
	std::size_t count = 0;
	unsigned short maxBodySize = 10;
	while (std::getline(config, line))
	{
		std::istringstream stream(line);
		std::string word;

		// Parse une ligne
		while (stream >> word)
		{
			if (word == "#")
				break;
			if (word == "clientMaxBodySize")
			{
				if (stream >> word)
					maxBodySize = getmaxBodySize(word);
				else
					return configError("[ ERROR ] Incorrect input for clientMaxBodySize");
			}
			else if (word == "server")
			{
				stream >> word;
				if (!parseServ(count, config))
					return false;
				count++;
			}
			else
				return configError("[ ERROR ] Unknow input in config");
		}
	}
	config.close();

	return true;
}