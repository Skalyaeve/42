#include "../../includes/header.hpp"

void diplayRaw( const std::string& s1, const std::string& s2, const std::string& s3, const std::string& s4 )
{
	if ( s1.size() > 10 )
		std::cout << s1.substr( 0, 9 ) << '.' << '|';
	else
		std::cout << std::setw( 10 ) << s1 << '|';
	if ( s2.size() > 10 )
		std::cout << s2.substr( 0, 9 ) << '.' << '|';
	else
		std::cout << std::setw( 10 ) << s2 << '|';
	if ( s3.size() > 10 )
		std::cout << s3.substr( 0, 9 ) << '.' << '|';
	else
		std::cout << std::setw( 10 ) << s3 << '|';
	if ( s4.size() > 10 )
		std::cout << s3.substr( 0, 9 ) << '.' << std::endl;
	else
		std::cout << std::setw( 10 ) << s4 << std::endl;
}

void displayInfos( PhoneBook& depo, const int &index )
{
	std::cout << "[ Contact #" << index << " ]" << std::endl;
	std::cout << "FIRST NAME\t: " << depo.getMember( index - 1 ).getValue( 1 ) << std::endl;
	std::cout << "LAST NAME\t: " << depo.getMember( index - 1 ).getValue( 2 ) << std::endl;
	std::cout << "NICKNAME\t: " << depo.getMember( index - 1 ).getValue( 3 ) << std::endl;
	std::cout << "PHONE NUMBER\t: " << depo.getMember( index - 1 ).getValue( 4 ) << std::endl;
	std::cout << "DARKEST SECRET\t: " << depo.getMember( index - 1 ).getValue( 5 ) << std::endl;
}

void getMoreInfos( PhoneBook& depo )
{
	int			index;
	std::string	input;

	std::cout << std::endl << "Enter contact INDEX to show more infos." << std::endl;
	std::cout << std::endl << "\t> ";
	while ( std::getline( std::cin, input ) )
	{
		if ( input.size() > 1 || input[ 0 ] < '1' || input[ 0 ] > '8' )
		{
			std::cout << "INDEX should be a number between 1 and 8." << std::endl;
			std::cout << std::endl << "\t> ";
			continue ;
		}
		index = input[ 0 ] - 48;
		if ( index > depo.showCount() )
		{
			std::cout << "[ Contact #" << index << " ] not registered yet." << std::endl;
			std::cout << std::endl << "\t> ";
			continue ;
		}
		displayInfos( depo, index );
		break ;
	}
	if ( std::cin )
		std::cout << "[ GOING BACK TO MAIN MENU ]" << std::endl << std::endl;
	else
		std::cout << std::endl << "[ GOING BACK TO MAIN MENU ]" << std::endl;
}

void searchContact( PhoneBook& depo )
{
	int			index = 0;
	std::string	contactIndex;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;

	std::cout << std::endl << "[ CONTACT LIST ]" << std::endl;
	diplayRaw( "INDEX", "FIRST NAME", "LAST NAME", "NICKNAME" );
	while ( index < depo.showCount() && index < 8 )
	{
		contactIndex = "CONTACT #";
		contactIndex += static_cast< char >( index + 1 + 48 );
		firstName = depo.getMember( index ).getValue( 1 );
		lastName = depo.getMember( index ).getValue( 2 );
		nickname = depo.getMember( index ).getValue( 3 );
		diplayRaw( contactIndex, firstName, lastName, nickname );
		++index;
	}
	getMoreInfos( depo );
}