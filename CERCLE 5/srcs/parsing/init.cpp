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
long long getmaxBodySize(std::string &size)
{
	// Check le dernier caractère
	if (size[size.length() - 1] == 'm')
		size.erase(size.end() - 1);

	// Str to short
	long long ret;
	if (!(ret = std::atoi(size.c_str())) || ret < 0)
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
	short maxBodySize = -1;
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
				if (maxBodySize != -1)
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				if (!(stream >> word))
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
                if ((maxBodySize = getmaxBodySize(word)) < 0)
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
                if (stream >> word)
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
                break;
			case (2):
				// Bloc serveur
				if (!(stream >> word))
                    return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
                if (word != "{")
					return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_NO_BRK, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[2] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				if (!parseServ(config, configLine))
					return false;
				break;
			default:
				return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
			}
		}
	}
	if (maxBodySize < 0)
		maxBodySize = 10;

	// Remplis les maxBodySize unset
	for (std::size_t x = 0; x < data()->servList.size(); x++)
		if (data()->servList[x].maxBodySize == -1)
			data()->servList[x].maxBodySize = maxBodySize;
	return true;
}
