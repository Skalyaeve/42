#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string>

void *ft_memset(void *ptr, const short &value, const std::size_t &num)
{
	char *p = static_cast< char * >(ptr);
	for (std::size_t i = 0; i < num; ++i)
		p[i] = static_cast< char >(value);
	return ptr;
}

long strToID(const std::string& str)
{
    struct addrinfo     hints;
    struct addrinfo*    results;
    ft_memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    int status = getaddrinfo(str.c_str(), NULL, &hints, &results);
    if (status != 0)
        return -1;
    uint32_t ip_addr = ntohl(((struct sockaddr_in*) results->ai_addr)->sin_addr.s_addr);
    freeaddrinfo(results);
    return ip_addr;
}

int main() 
{
  int fd1 = socket(AF_INET, SOCK_STREAM, 0);
  // use fd1...
  int fd2 = socket(AF_INET, SOCK_STREAM, 0);
  dup2(fd2, fd1); // release fd1
  // use fd2...
  close(fd2); // release fd2
    return 0;
}
