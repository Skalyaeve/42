#include "../../includes/header.hpp"

// Print un message puis return false
int configError(const std::string &msg, const bool &useErrno, const short &ret)
{
	std::cerr << msg << std::endl;
	if (useErrno)
		std::cerr << std::strerror(errno) << std::endl;
	return ret;
}

// Return un maxBodySize
short getmaxBodySize(std::string &size, const std::size_t &configLine)
{
	std::ostringstream lineIndex;
	lineIndex << configLine;

	// Check le dernier caractère
	if (size[size.length() - 1] != 'm')
		return -1;
	size.erase(size.end() - 1);

	// Str to short
	short ret;
	if (!(ret = std::atoi(size.c_str())) || ret < 0 || ret > 4)
		return -1;
	return ret;
}

// Setup de webServ
bool init(std::ifstream& config)
{
	data();

	// Keywords
	const std::string keywords[] = {"#", "clientMaxBodySize", "server"};
	const std::vector< std::string > keys(keywords, keywords + sizeof(keywords) / sizeof(std::string));

	// Parse la config
	std::string line;
	short maxBodySize = 4;
	std::size_t configLine = 0;
	while (std::getline(config, line))
	{
		std::ostringstream lineIndex;
		std::istringstream stream(line);
		std::string word;

		configLine++;
		lineIndex << configLine;
		// Parse une ligne
		bool stop = false;
		while (!stop && !stream.fail() && (stream >> word))
		{
			switch (std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
			{
			case (0):
				stop = true;
				break;
			case (1):
				// clientMaxBodySize
				if (!(stream >> word))
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_NO_VAL, false, -1);
                if ((maxBodySize = getmaxBodySize(word, configLine)) < 0)
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_BAD_VAL, false, -1);
                if (stream >> word)
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_TM_VAL, false, -1);
                break;
			case (2):
				// Bloc serveur
				if (!(stream >> word))
                    return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_NO_VAL, false, -1);
                if (word != "{")
					return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_NO_BRK, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				if (!parseServ(config, maxBodySize, configLine))
					return false;
				break;
			default:
				return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
			}
		}
	}
	return true;
}
