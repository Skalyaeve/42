#include "../../includes/header.hpp"

int main( int ac, char **av )
{
	Harl	Harl;

	if (ac == 2)
		Harl.complain( av[ 1 ], 0 );
	else
	{
		std::cout << "Usage: ./harlFilter [ CMD ]" << std::endl;
		std::cout << "available commands : \"DEBUG\" - \"INFO\" - \"WARNING\" - \"ERROR\"" << std::endl;
	}
	return 0;
}
