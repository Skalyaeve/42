#include "../includes/header.hpp"

// Remplie une combinaison IP:PORT
bool getIpPort(const std::string& value, std::pair<uint32_t, uint16_t>& ref)
{
    // Remplie ref
    return true;
}

// Parse un bloc serveur
bool parseServ(std::ifstream& config)
{
	// Nouveau bloc serveur
    t_serv serv;

    // configKeywords
    std::string wordList[] = {"listen", "serverName", "errorPage", "location"};
  	std::vector<std::string> keys(wordList, wordList + wordList->size());

    // Parse le bloc serveur
	std::string line;
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
                    // Parse les IP:PORT d'ecoute du serveur
                    if (!(stream >> word))
                        return configError("[ ERROR ] Invalid input for listen directive");
                    while (!stream.fail())
                    {
                        std::pair<uint32_t, uint16_t> ip_port;
                        if (!getIpPort(word, ip_port))
                            return false;
                        serv.ip_port.push_back(ip_port);
                        stream >> word;
                    }
                    break;
                case (1):
                    // Parse les noms de domaines du serveur
                    if (!(stream >> word))
                        return configError("[ ERROR ] Invalid input for serverName");
                    while (!stream.fail())
                    {
                        serv.serverName.push_back(word);
                        stream >> word;
                    }
                    break;
                case (2):
                    // Parse les pages d'erreur du serveur
                    if (!(stream >> word))
                        return configError("[ ERROR ] Invalid input for errorPage");
                    while (!stream.fail())
                    {
                        serv.errorPages.push_back(word);
                        stream >> word;
                    }
                    break;
                case (3):
                    if (!setupLoca(config, stream, &serv, NULL))
                        return false;
                    break;
                default:
                    return configError("[ ERROR ] Invalid input for a server block");
            }
		}
	}
    data()->servList.push_back(serv);
	return true;
}
