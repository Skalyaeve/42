#include "../../includes/header.hpp"

// Remplis une zone mémoire de num fois value
void *ft::memset(void *ptr, const short &value, const std::size_t &num)
{
	char *p = static_cast< char * >(ptr);
	for (std::size_t i = 0; i < num; ++i)
		p[i] = static_cast< char >(value);
	return ptr;
}

void printData(void)
{
	
}