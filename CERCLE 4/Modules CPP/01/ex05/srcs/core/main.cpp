#include "../../includes/header.hpp"

int main( void )
{
	Harl		newHarl;
	std::string	input;
	
	std::cout << "[ Harl 2.0 ]" << std::endl << "available commands : \"DEBUG\" - \"INFO\" - \"WARNING\" - \"ERROR\"" << std::endl;
	std::cout << "ctrl + d to exit." << std::endl;
	std::cout << "\t> ";
	while ( std::getline( std::cin, input ) )
	{
		newHarl.complain( input );
		std::cout << "\t> ";
	}
	std::cout << "Entry port closed, exiting." << std::endl;

	return 0;
}
