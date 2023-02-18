#include "../../includes/header.hpp"

int main( void )
{
	PhoneBook	repo;
	std::string	input;

	std::cout << "[ 8Besties - Secure contact manager ]" << std::endl;
	std::cout << "\t> ";
	while ( std::getline( std::cin, input ) )
	{
		if ( !input.compare( "EXIT" ) )
			break ;
		if ( !input.compare( "ADD" ) )
			addContact( repo );
		if ( !input.compare( "SEARCH" ) )
			searchContact( repo );
		if ( std::cin )
			std::cout << "\t> ";
	}
	if ( !std::cin )
		std::cout << std::endl << "Entry port has been closed." << std::endl;
	std::cout << "[ EXITING ]" << std::endl;
	return 0;
}