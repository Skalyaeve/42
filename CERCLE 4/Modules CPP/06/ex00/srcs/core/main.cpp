#include "../../includes/header.hpp"

bool is_charset( const char& c, const char* charset )
{
	for ( short i = 0; charset[ i ]; i++ )
		if ( charset[ i ] == c )
			return 1;
	return 0;
}

int	input_error( void )
{
	std::cerr << "[ ERROR ] : wrong input, supported values -> char, int, float, double" << std::endl;
	return 0;
}

int check_input( const char* input )
{
	if ( !input[ 0 ] )
		return input_error();
	if ( !input[ 1 ] )
		return 1;

	const std::string str = input;
	if ( !str.compare( "nan" ) || !str.compare( "nanf" )
		|| !str.compare( "inf" ) || !str.compare( "inff" )
		|| !str.compare( "-inf" ) || !str.compare( "-inff" )
		|| !str.compare( "+inf" ) || !str.compare( "+inff" ) )
		return 1;
	
	unsigned short	dot = 0;
	for ( int i = 0; input[ i ]; i++ )
	{
		if ( input[ i ] == '.' )
			dot++;
		if ( dot > 1 || !is_charset( input[ i ], "+-.0123456789f" )
			|| ( is_charset( input[ i ], "+-" ) && i != 0 )
			|| ( input[ i ] == 'f' && input[ i + 1 ] ) )
			return input_error();
	}
	return 1;
}

void printInteger( const std::string& integer )
{
	double	d;

	sscanf( integer.c_str(), "%lf", &d );
	std::ostringstream stream;
	stream << d;
	if ( !stream.str().compare( "nan" ) )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	if ( d < std::numeric_limits< char >::min() || d > std::numeric_limits< char >::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( d < ' ' )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast< char >( d )  << "'" << std::endl;
	
	if ( d < std::numeric_limits< int >::min() || d > std::numeric_limits< int >::max() )
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast< int >( d ) << std::endl;
}

void printFloating( const std::string& floating )
{
	float	f;
	double	d;

	sscanf( floating.c_str(), "%f", &f );
	std::cout << "float: " << f;
	if ( f - static_cast< long long >( f ) == 0 )
		std::cout << ".0";
	std::cout << "f" << std::endl;

	sscanf( floating.c_str(), "%lf", &d );
	std::cout << "double: " << d;
	if ( f - static_cast< long long >( f ) == 0 )
		std::cout << ".0";
	std::cout << std::endl;
}

int main( int ac, char **av )
{
	if ( ac == 2 )
	{
		if ( !check_input( av[ 1 ] ) )
			return 0;
		std::string	input = av[ 1 ];
		if ( !av[ 1 ][ 1 ] && !is_charset( av[ 1 ][ 0 ], "0123456789" ) )
		{
			const short value = static_cast< int >( input.c_str()[ 0 ] );
			std::ostringstream stream;
			stream << value;
			input = stream.str();
		}
        printInteger( input );
        printFloating( input );
	}
	else
		std::cout << "-> ./conversionScalaire [ nbr ]" << std::endl;
	return 0;
}
