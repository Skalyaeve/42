#include "../../includes/header.hpp"

// Check si la redirection HTTP est correcte
bool checkRedir(const std::string &ref)
{
	const std::string keywords[] = {"$scheme://", "$request_uri"};

	if (ref.substr(0, keywords[0].length()) != keywords[0])
		return false;

	if (ref.substr(ref.length() - keywords[1].length()) != keywords[1])
		return false;

	return true;
}

// Check le répertoire de root
bool checkRootDir(const std::string &ref)
{
	struct stat infoStruc;
	if (stat(ref.c_str(), &infoStruc) != 0)
		return configError("[ ERROR ] Unable to access path " + ref, false, 0);
	return S_ISDIR(infoStruc.st_mode);
}

// Parse un bloc limitExcept
bool newLimit(std::ifstream &config, std::istringstream &stream, t_location &ref, std::size_t &configLine)
{
	// Keywords
	std::string word;
	const std::string keywords[] = {"GET", "POST", "DELETE", "{", "allow", "deny", "}", "#"};
	const std::vector< std::string > keys(keywords, keywords + sizeof(keywords) / sizeof(std::string));

	// Parse le bloc
	std::vector< std::pair< uint32_t, bool > > inputs;
	std::string line;
	bool stop = false;
	while (!stop && std::getline(config, line))
	{
		// Parse une ligne
        std::ostringstream lineIndex;
		std::istringstream streamBis(line);
        configLine++;
        lineIndex << configLine;
		bool stopBis = false;
		while (!stopBis && !streamBis.fail() && (streamBis >> word))
		{
			long ip;
			switch (std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
			{
			case (4):
				if (!(streamBis >> word))
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				ip = (word == "all" ? 0 : strToID(word));
				if (ip < 0)
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				inputs.push_back(std::pair< uint32_t, bool >(ip, true));
                if (streamBis >> word)
                    return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (5):
				if (!(streamBis >> word))
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				ip = (word == "all" ? 0 : strToID(word));
				if (ip < 0)
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				inputs.push_back(std::pair< uint32_t, bool >(ip, false));
                if (streamBis >> word)
                    return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (6):
				stop = true;
				break;
			case (7):
				stopBis = true;
				break;
			default:
				return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
			}
		}
	}
    std::ostringstream lineIndex;
    lineIndex << configLine;
	if (!stop)
		return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_NO_BRK, false, 0);

	// Init de la map
	ref.limitExcept["GET"] = std::vector< std::pair< uint32_t, bool > >();
	ref.limitExcept["POST"] = std::vector< std::pair< uint32_t, bool > >();
	ref.limitExcept["DELETE"] = std::vector< std::pair< uint32_t, bool > >();

	// Ajoute les inputs aux méthodes concernées
	bool openned = false;
	while (stream >> word)
	{
		switch (std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
		{
		case (0):
			ref.limitExcept["GET"] = inputs;
			break;
		case (1):
			ref.limitExcept["POST"] = inputs;
			break;
		case (2):
			ref.limitExcept["DELETE"] = inputs;
			break;
		case (3):
			openned = true;
			break;
		default:
			return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
		}
	}
	if (!openned)
		return configError("[ ERROR ] limitExcept: " + lineIndex.str() + ERR_NO_BRK, false, 0);
	return true;
}

// Init un bloc location
t_location initLoca(const std::string &name)
{
	t_location loca;
	loca.name = name;
	loca.root = "/www/";
	loca.autoIndex = false;
	loca.maxBodySize = 4;
	return loca;
}

// Parse un bloc location
bool parseLoca(std::ifstream &config, const std::string &name, t_location &ref, std::size_t &configLine)
{
	// Init le bloc
	ref = initLoca(name);

	// Keywords
	const std::string keywords[] = {"return", "autoIndex", "limitExcept", "root", "index", "location", "}", "#"};
	const std::vector< std::string > keys(keywords, keywords + sizeof(keywords) / sizeof(std::string));

	// Parse le bloc
	std::string line;
	bool stop = false;
	while (!stop && std::getline(config, line))
	{
		// Parse une ligne
		std::ostringstream lineIndex;
		std::istringstream stream(line);
		std::string word;
		configLine++;
		lineIndex << configLine;
		bool stopBis = false;
		while (!stopBis && !stream.fail() && (stream >> word))
		{
			switch (std::distance(keys.begin(), std::find(keys.begin(), keys.end(), word)))
			{
			case (0):
				// Redirection HTTP
				if (!(stream >> ref.redirect.first))
                    return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
                if (ref.redirect.first != 301)
                    return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
                if (!(stream >> ref.redirect.second))
                    return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
                if (!checkRedir(ref.redirect.second))
					return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[0] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (1):
				// Autoindex
				if (!(stream >> word))
                    return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
                if (word != "on" && word != "off")
					return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				ref.autoIndex = (word == "on" ? true : false);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[1] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (2):
				// LimitExcept
				if (!newLimit(config, stream, ref, configLine))
					return false;
				break;
			case (3):
				// Répertoire de root
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[3] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				ref.root = "." + word;
				if (!checkRootDir(ref.root))
					return configError("[ ERROR ] " + keywords[3] + ": " + lineIndex.str() + ERR_BAD_VAL, false, 0);
				if (stream >> word)
					return configError("[ ERROR ] " + keywords[3] + ": " + lineIndex.str() + ERR_TM_VAL, false, 0);
				break;
			case (4):
				// Index par défaut
				if (!(stream >> word))
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);

				bool anotherOne;
				while (!stream.fail())
				{
					anotherOne = checkFilename(word);
					ref.indexPages.push_back(word);
					stream >> word;
				}
				if (anotherOne)
					return configError("[ ERROR ] " + keywords[4] + ": " + lineIndex.str() + ERR_NO_VAL, false, 0);
				break;
			case (5):
				// Bloc location
				if (!setupLoca(config, stream, NULL, &ref, configLine))
					return false;
				break;
			case (6):
				// Fin de bloc
				stop = true;
				break;
			case (7):
				// Commentaire
				stopBis = true;
				break;
			default:
				return configError("[ ERROR ] Unknown keyword: " + lineIndex.str() + ": " + word, false, 0);
			}
		}
	}
    std::ostringstream lineIndex;
    lineIndex << configLine;
	if (!stop)
		return configError("[ ERROR ] server: " + lineIndex.str() + ERR_NO_BRK, false, 0);
	return true;
}

// Initialise et assigne un bloc location
bool setupLoca(std::ifstream &config, std::istringstream &stream, t_serv *servPtr, t_location *locaPtr, std::size_t &configLine)
{
	// Termine de check la ligne en cours
	std::ostringstream lineIndex;
	std::string name;
	std::string word;

	lineIndex << configLine;
	if (stream >> word)
		name = word;
	else
		return configError("[ ERROR ] location:" + lineIndex.str() + ERR_NO_VAL, false, 0);
	if (!(stream >> word))
        return configError("[ ERROR ] location:" + lineIndex.str() + ERR_NO_VAL, false, 0);
    if (word != "{")
		return configError("[ ERROR ] location:" + lineIndex.str() + ERR_NO_BRK, false, 0);
	if (stream >> word)
		return configError("[ ERROR ] location:" + lineIndex.str() + ERR_TM_VAL, false, 0);

	// Parse le reste du bloc location
	t_location location;
	if (!parseLoca(config, name, location, configLine))
		return false;
	if (servPtr)
		(*servPtr).locations.push_back(location);
	else
		(*locaPtr).locations.push_back(location);
	return true;
}
