#include "../../includes/header.hpp"

int	fillContactInfo( PhoneBook& repo, const std::string& field, const int& index, const int& offset )
{
	std::string	input;

	if ( std::cin )
	{
		std::cout << field;
		while ( std::getline( std::cin, input ) && input.empty() )
			std::cout << field;
		repo.getMember( repo.showCount() - offset ).setValue( index, input );
	}
	else
		return 1;
	return 0;
}

void backToMenu( PhoneBook& repo, const int& ret )
{
	if ( std::cin )
	{
		if ( !ret )
		{
			repo.updateCount();
			std::cout << "[ NEW CONTACT ADDED ]" << std::endl;
		}
		std::cout << "[ GOING BACK TO MAIN MENU ]" << std::endl << std::endl;
	}
	else
		std::cout << std::endl << "[ GOING BACK TO MAIN MENU ]" << std::endl;
}

void addContact( PhoneBook& repo )
{
	int			ret = 0;
	int			index = -1;
	const int	offset = ( repo.showCount() == 8 ? 1 : 0 );

	if ( repo.showCount() == 8 )
	{
		std::cout << "Warning : Missing storage capacity, older contact will be removed.";
		while ( ++index < 7 )
			repo.getMember( index ) = repo.getMember( index + 1 );
	}
	std::cout << std::endl << "[ CREATING NEW CONTACT ]" << std::endl;
	std::cout << "\t[ CONTACT #" << repo.showCount() + 1 - offset << " ]" << std::endl;
	if ( !ret )
		ret += fillContactInfo( repo, "\tFIRST NAME : ", 1, offset );
	if ( !ret )
		ret += fillContactInfo( repo, "\tLAST NAME : ", 2, offset );
	if ( !ret )
		ret += fillContactInfo( repo, "\tNICKNAME : ", 3, offset );
	if ( !ret )
		ret += fillContactInfo( repo, "\tPHONE NUMBER : ", 4, offset );
	if ( !ret )
		ret += fillContactInfo( repo, "\tDARKEST SECRET : ", 5, offset );
	backToMenu( repo, ret );
}