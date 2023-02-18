#include "../includes/header.hpp"

std::string getFinalString( const std::string& content, const std::string& toRemove, const std::string& toAdd )
{
	std::string	finalStr;
	std::size_t	found;
	std::size_t	offset = 0;

	if ( !toRemove.size() )
		return content;
	while ( ( found = content.find( toRemove, offset ) ) != std::string::npos )
	{
		finalStr += content.substr( offset, found - offset );
		finalStr += toAdd;
		offset = found + toRemove.size();
	}
	finalStr += content.substr( offset, found - offset );
	return finalStr;
}

int openFile( const char* filename, std::string& content )
{
	std::ifstream	fd( filename );
	char			c;

	if ( !fd.is_open() )
	{
		std::cout << "Couldn't open file [ "<< filename << " ]." << std::endl;
		return -1;
	}
	c = fd.get();
	while ( fd )
	{
		content += c;
		c = fd.get();
	}
	fd.close();
	return 0;
}

int main( int ac, char **av )
{
	if ( ac == 4 )
	{
		std::string	content;

		if ( openFile( av[ 1 ], content ) )
		{
			std::cerr << "[ ERROR ] Can't open file." << std::endl;
			return -1;
		}
		std::string	name = av[ 1 ];
		name += ".replace";
		std::ofstream fd( name.c_str() );
		fd << getFinalString( content, av[ 2 ], av[ 3 ] );
	}
	else	
		std::cout << std::endl << "[ SedIsForLosers ]" << std::endl
			<< "Usage : ./SedIsForLosers [ Infile ] [ toRemove ] [ toAdd ]" << std::endl
			<< "Replace each occurence of [ toRemove ] by [ toAdd ] in [ Infile ]." << std::endl << std::endl;
	return 0;
}
