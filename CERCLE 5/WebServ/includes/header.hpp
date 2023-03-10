#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <sys/stat.h>

// Valeur en octet d'un mega-octet
#define ONE_MO 1048576
// Read requests buffer size
#define BUFFER_SIZE 8192
// Nombre maximum de connexions en attente avant que le serveur ne commence à les refuser
#define MAX_CONNECTION 42

// Codes erreur
#define ERR_BAD_REQ 400		   // La requête n'est pas correctement formulée.
#define ERR_UNAUTHORIZED 401   // L'utilisateur n'est pas authentifié.
#define ERR_FORBIDDEN 403	   // L'accès à la ressource est interdit.
#define ERR_NOT_FOUND 404	   // La ressource demandée n'existe pas.
#define ERR_METHOD_NOT_ALW 405 // La méthode HTTP utilisée n'est pas autorisée.
#define ERR_REQ_TIMEOUT 408	   // Le délai d'attente pour la réponse a expiré.
#define ERR_BODY_2LONG 413	   // Body de la requête trop lourd.
#define ERR_URI_2LONG 414	   // L'URI de la requête est trop long.
#define ERR_UNSUP_M_TYPE 415   // Le type de contenu de la requête n'est pas supporté.
#define ERR_2MANY_REQ 429	   // Le nombre de requêtes envoyées est trop important.
#define ERR_SERV_INTERN 500	   // Une erreur interne du serveur est survenue.
#define ERR_BAD_GATW 502	   // Le serveur a reçu une réponse invalide de la part du service.
#define ERR_UNAVAILABLE 503	   // Le service est temporairement indisponible.
#define ERR_GATW_TIMEOUT 504   // Le serveur n'a pas reçu de réponse du service à temps.

// Messages erreur
#define ERR_NO_VAL ": No value found"
#define ERR_TM_VAL ": Too many values found"
#define ERR_BAD_VAL ": Invalid value found"
#define ERR_NO_BRK ": Missing brackets"

// ???
typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr t_sockaddr;
typedef struct addrinfo t_addrinfo;

// Donnees d'un bloc location
typedef struct s_location
{
	// From parsing
	std::map< std::string, std::vector< std::pair< uint32_t, bool > > > limitExcept;
	std::string name;
	std::string root;
	bool autoIndex;
	short maxBodySize;
	std::pair< unsigned short, std::string > redirect;
	std::vector< std::string > indexPages;
	std::vector< struct s_location > locations;
} t_location;

// Donnees d'un bloc serveur
typedef struct s_serv
{
	// From setup
	std::vector< std::pair< int, t_sockaddr_in >  > sock_addr;

	// From parsing
	std::vector< std::pair< uint32_t, uint16_t > > ip_port;
	std::vector< std::string > serverName;
	std::vector< std::string > errorPages;
	std::vector< t_location > locations;
	short maxBodySize;
} t_serv;

// Singleton Singleton Singleton-ton-ton
typedef struct s_data
{
	std::vector< t_serv > servList;
} t_data;

// Namespace
namespace ft
{
	void *memset(void *ptr, const short &value, const std::size_t &num);
}

// Liens
t_data *data(void);
bool init(std::ifstream& config);
int configError(const std::string &msg, const bool &useErrno, const short &ret);
bool parseServ(std::ifstream &config, short &maxBodySize, std::size_t &configLine);
bool setupLoca(std::ifstream &config, std::istringstream &stream, t_serv *servPtr, t_location *locaPtr, std::size_t &configLine);
t_location initLoca(const std::string &name);
short getmaxBodySize(std::string &size, const std::size_t &configLine);
bool checkFilename(std::string &ref);
long strToID(const std::string &str);
bool serv(void);

#endif
