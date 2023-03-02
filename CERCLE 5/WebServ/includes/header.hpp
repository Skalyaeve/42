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

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;

bool serv(int* serverFd, t_sockaddr_in* address);
