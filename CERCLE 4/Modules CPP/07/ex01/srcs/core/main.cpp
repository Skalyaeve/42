#include "../../includes/header.hpp"

int main( void )
{
	const int		iTab[ 1 ] = { 42 };
	const double	fTab[ 3 ] = { 4.4, 2.2, 0.0001 };
	const char		charTab[ 2 ] = { 'O', 'K' };
	const char*		strTab[ 2 ] = { "Sam", "Dean" };
	const void*		voidPtrTab1[ 2 ] = { &strTab[ 0 ], &strTab[ 1 ] };

	::iter( iTab, 1, &printValue );
	std::cout << std::endl;
	::iter( fTab, 3, &printValue );
	std::cout << std::endl;
	::iter( charTab, 2, &printValue );
	std::cout << std::endl;
	::iter( strTab, 2, &printValue );
	std::cout << std::endl;
	::iter( voidPtrTab1, 2, &printValue );

	return 0;
}