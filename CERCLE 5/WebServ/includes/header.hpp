#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define IP					INADDR_ANY
#define PORT				8080
#define MAX_CONNECTION		30000
#define BUFFER_SIZE			30000
#define ERR_BAD_REQ			400 // La requête n'est pas correctement formulée.
#define ERR_UNAUTHORIZED	401 // L'utilisateur n'est pas authentifié.
#define ERR_FORBIDDEN		403 // L'accès à la ressource est interdit.
#define ERR_NOT_FOUND		404 // La ressource demandée n'existe pas.
#define ERR_METHOD_NOT_ALW	405 // La méthode HTTP utilisée n'est pas autorisée.
#define ERR_REQ_TIMEOUT		408 // Le délai d'attente pour la réponse a expiré.
#define ERR_BODY_2LONG		413 // Body de la requête trop lourd.
#define ERR_URI_2LONG		414 // L'URI de la requête est trop long.
#define ERR_UNSUP_M_TYPE	415 // Le type de contenu de la requête n'est pas supporté.
#define ERR_2MANY_REQ		429 // Le nombre de requêtes envoyées est trop important.
#define ERR_SERV_INTERN		500 // Une erreur interne du serveur est survenue.
#define ERR_BAD_GATW		502 // Le serveur a reçu une réponse invalide de la part du service.
#define ERR_UNAVAILABLE		503 // Le service est temporairement indisponible.
#define ERR_GATW_TIMEOUT	504 // Le serveur n'a pas reçu de réponse du service à temps.

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;

bool serv(int* serverFd, t_sockaddr_in* address);
