#include "../../includes/header.hpp"

#define	SIZE	20000

void perform( Span sp )
{
	long long tab[ SIZE ];
	tab[ 0 ] = -41;
	for ( int i = 1; i < SIZE; i++ )
		tab[ i ] = i;
	
	std::cout << "Adding numbers to Span" << std::endl;
	try
	{ sp.addNumbers( tab, SIZE ); }
	catch ( const std::exception& e )
	{ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << "Span min span is ";
	try
	{ std::cout << sp.shortestSpan(); }
	catch ( const std::exception& e )
	{ std::cerr << e.what(); }
	std::cout << std::endl;

	std::cout << "Span max span is ";
	try
	{ std::cout << sp.longestSpan(); }
	catch ( const std::exception& e )
	{ std::cerr << e.what(); }
	std::cout << std::endl;

	std::cout << std::endl << "Adding number 1000000 to Span" << std::endl;
	try
	{ sp.addNumber( 1000000 ); }
	catch ( const std::exception& e )
	{ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << "Span min span is ";
	try
	{ std::cout << sp.shortestSpan(); }
	catch ( const std::exception& e )
	{ std::cerr << e.what(); }
	std::cout << std::endl;

	std::cout << "Span max span is ";
	try
	{ std::cout << sp.longestSpan(); }
	catch ( const std::exception& e )
	{ std::cerr << e.what(); }
	std::cout << std::endl;
}

int main( void )
{
	Span sp1( SIZE );
	Span sp2( SIZE + 1 );
	Span sp3( SIZE - 1 );
	Span sp4( 0 );
	Span sp5( sp1 );

	std::cout << "Performing on sp1" << std::endl << "--------------" << std::endl;
	perform( sp1 );
	std::cout << "--------------" << std::endl << std::endl;
	std::cout << "Performing on sp2" << std::endl << "--------------" << std::endl;
	perform( sp2 );
	std::cout << "--------------" << std::endl << std::endl;
	std::cout << "Performing on sp3" << std::endl << "--------------" << std::endl;
	perform( sp3 );
	std::cout << "--------------" << std::endl << std::endl;
	std::cout << "Performing on sp4" << std::endl << "--------------" << std::endl;
	perform( sp4 );
	std::cout << "--------------" << std::endl << std::endl;
	std::cout << "Performing on sp5" << std::endl << "--------------" << std::endl;
	perform( sp5 );
	std::cout << "--------------" << std::endl;

	return 0;
}
