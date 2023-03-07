#include "../includes/header.hpp"

// Print un message puis return false
bool configError(const std::string msg, bool useErrno = false)
{
	std::cerr << msg << std::endl;
    if (useErrno)
		std::cerr << std::strerror(errno) << std::endl;
	return false;
}

// Return un maxBodySize
short getmaxBodySize(std::string size)
{
    if (size[size.length() - 1] != 'm')
    {
        std::cerr << "[ ERROR ] Invalid input for clientMaxBodySize" << std::endl;
        return -1;
    }
    size.erase(size.end() - 1);

	short ret;
    try
    {
        ret = std::stoi(size);
        if (ret > 4095)
            throw std::out_of_range("Value is " + std::to_string(ret));
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "[ ERROR ] Invalid input for clientMaxBodySize" << std::endl;
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "[ ERROR ] Max clientMaxBodySize is 4095" << std::endl;
        std::cerr << e.what() << std::endl;
        return -1;
    }
	return ret;
}

// Setup de webServ
bool init(const char* path)
{
	// Init la singleton
	data();

    // Config keywords
    std::string wordList[] = {"#", "clientMaxBodySize", "server"};
  	std::vector<std::string> keys(wordList, wordList + wordList->size());

	// Ouvre la config
	std::ifstream config;
	if (!config.open(path, std::ios_base::in))
		return configError("[ ERROR ] Invalid input for config", true);

	// Parse la config
	std::string line;
	unsigned short maxBodySize = 10;
	while (std::getline(config, line))
	{
		std::istringstream stream(line);
		std::string word;

		// Parse une ligne
		while (!stream.fail() && (stream >> word))
		{
            switch (std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
			{
                case (0):
                    break;
                case (1):
		            // Parse clientMaxBodySize
				    if (stream >> word)
                        if ((maxBodySize = getmaxBodySize(word)) >= 0)
                            if (!(stream >> word))
                                break;
				    return configError("[ ERROR ] Invalid input for clientMaxBodySize");
                case (2):
		            // Parse un bloc serveur
                    stream >> word;
                    if (!word || word != "{")
				        return configError("[ ERROR ] Invalid input for a server block");
                    if (stream >> word)
				        return configError("[ ERROR ] Invalid input for a server block");
                    if (!parseServ(config))
				    	return false;
                default:
				    return configError("[ ERROR ] Invalid input for config");
            }
		}
	}
	config.close();
	return true;
}
