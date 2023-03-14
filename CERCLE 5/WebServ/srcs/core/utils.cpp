#include "../../includes/header.hpp"

// Remplis une zone mémoire de num fois value
void *ft::memset(void *ptr, const short &value, const std::size_t &num)
{
	char *p = static_cast< char * >(ptr);
	for (std::size_t x = 0; x < num; ++x)
		p[x] = static_cast< char >(value);
	return ptr;
}

std::vector< std::string > ft::split(std::string &str, const char delim)
{
	std::istringstream stream(str);
	std::string word;
	std::vector< std::string > vec;
	while (std::getline(stream, word, delim))
		vec.push_back(word);
	return (vec);
}

void printLocation(t_location& ref)
{
	std::cout << "- name: " << ref.name << std::endl;
	std::cout << "- root: " << ref.root << std::endl;
	std::cout << "- redirect: [ " << ref.redirect.first << " ] " << ref.redirect.second << std::endl;

	std::cout << "- GET: " << std::endl;
	for (std::size_t a = 0; a < ref.limitExcept["GET"].size(); a++)
		std::cout << "\t" << ref.limitExcept["GET"][a].first << " -> "
		<< ref.limitExcept["GET"][a].second << std::endl;

	std::cout << "- POST: " << std::endl;
	for (std::size_t b = 0; b < ref.limitExcept["POST"].size(); b++)
		std::cout << "\t" << ref.limitExcept["POST"][b].first << " -> "
		<< ref.limitExcept["POST"][b].second << std::endl;

	std::cout << "- DELETE: " << std::endl;
	for (std::size_t c = 0; c < ref.limitExcept["DELETE"].size(); c++)
		std::cout << "\t" << ref.limitExcept["DELETE"][c].first << " -> "
		<< ref.limitExcept["DELETE"][c].second << std::endl;

	std::cout << "- autoIndex: " << ref.autoIndex << std::endl;
	std::cout << "- indexPage:" << std::endl;
	for (std::size_t d = 0; d < ref.indexPage.size(); d++)
		std::cout << "\t" << ref.indexPage[d] << std::endl;
	if (ref.locations.size())
	{
		for (std::size_t e = 0; e < ref.locations.size(); e++)
		{
			std::cout << "- [ Locations #" << e + 1 << " ]" << std::endl;
			printLocation(ref.locations[e]);
		}
	}
	std::cout << std::endl;
}

void printConfig(void)
{
	for (std::size_t a = 0; a < data()->servList.size(); a++)
	{
		std::cout << "[ Server #" << a + 1 << " ]"<< std::endl;
		std::cout << "maxBodySize:" << data()->servList[a].maxBodySize << std::endl;
		std::cout << "listen:" << std::endl;
		for (std::size_t b = 0; b < data()->servList[a].ip_port.size(); b++)
			std::cout << "\t" << data()->servList[a].ip_port[b].first << ":" << data()->servList[a].ip_port[b].second << std::endl;
		std::cout << "serverName:" << std::endl;
		for (std::size_t c = 0; c < data()->servList[a].serverName.size(); c++)
			std::cout << "\t" << data()->servList[a].serverName[c] << std::endl;
		std::cout << "errorPage:" << std::endl;
		for (std::size_t d = 0; d < data()->servList[a].errorPages.size(); d++)
			std::cout << "\t" << data()->servList[a].errorPages[d] << std::endl;
		for (std::size_t e = 0; e < data()->servList[a].locations.size(); e++)
		{
			std::cout << "[ Locations #" << e + 1 << " ]" << std::endl;
			printLocation(data()->servList[a].locations[e]);
		}
		std::cout << std::endl << "-------------------------------------" << std::endl;
	}
	std::cout << "(end)" << std::endl;
}
