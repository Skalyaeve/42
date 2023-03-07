#include "../includes/header.hpp"

// Parse un bloc location
bool parseLoca(std::ifstream& config, const std::string& name, t_location& ref)
{
    ref.name = name;
    // configKeywords
    std::string wordList[] = {"return", "autoIndex", "limitExcept", "root", "index", "location"};
  	std::vector<std::string> keys(wordList, wordList + wordList->size());

    // Parse le bloc
	std::string line;
	std::size_t count = 0;
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
                    // Parsing d'une redirection HTTP
                    if (!(stream >> ref.redirect.first())) // TODO
			    	    return configError("[ ERROR ] Invalid input for HTTP redirection");
                    if (!(stream >> ref.redirect.second())) // TODO
			    	    return configError("[ ERROR ] Invalid input for HTTP redirection");
                    if (stream >> word)
			    	    return configError("[ ERROR ] Invalid input for HTTP redirection");
                    break;
                case (1):
                    // Parse l'autoindex
                    if (!(stream >> word))
			    	    return configError("[ ERROR ] Invalid input for autoindex");
					if (word != "on" || word != "off")
			    	    return configError("[ ERROR ] Invalid input for autoindex");
					ref.autoIndex = (word == "on" ? true : false);
                    if (stream >> word)
			    	    return configError("[ ERROR ] Invalid input for autoindex");
					break;
                case (2):
                    // Parse limitExcept
                    while (stream >> word)
                    {
                        if (word != "GET" || word != "POST" || word != "DELETE")
			    	        return configError("[ ERROR ] Invalid input for a location limitExcept");
                        // TO DO
                    }
					break;
                case (3):
                    // Parse du repertoire de root
                    if (!(stream >> ref.root))
			    	    return configError("[ ERROR ] Invalid input for root directory");
                    if (stream >> word)
			    	    return configError("[ ERROR ] Invalid input for autoindex");
                    break;
                case (4):
                    // Parse des index par defaut
                    if (!(stream >> word))
                        return configError("[ ERROR ] Invalid input for default index");
                    while (!stream.fail())
                    {
                        ref.indexPages.push_back(word);
                        stream >> word;
                    }
                    break;
                case (5):
                    if (!setupLoca(config, stream, NULL, &ref))
                        return false;
                    break;
                default:
			    	return configError("[ ERROR ] Invalid input for a location block");
            }
        }
	}
	return true;
}

// Initialise et assigne un bloc location
bool setupLoca(std::ifstream& config, std::istringstream& stream, t_serv* servPtr, t_location* locaPtr)
{
    std::string name;
    std::string word;
    if (stream >> word)
        name = word;
    else
	    return configError("[ ERROR ] Invalid input for a location");
    stream >> word;
    if (stream.fail() || word != "{")
	    return configError("[ ERROR ] Invalid input for a location");
    if (stream >> word)
	    return configError("[ ERROR ] Invalid input for a location");

	t_location location;
    if (!parseLoca(config, name, location))
        return false;
    if (servPtr)
        (*servPtr).locations.push_back(location);
    else
        (*locaPtr).locations.push_back(location);
    return true;
}
