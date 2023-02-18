#include "../../includes/header.hpp"

#define TO_FIND	-1

int main( void )
{
	int					nbrs[] = { 1, 2, 3, 4 };
	std::vector< int >	iVector( nbrs, nbrs + sizeof( nbrs ) / sizeof( int ) );
	std::list< int >	iList( nbrs, nbrs + sizeof( nbrs ) / sizeof( int ) );
	std::deque< int >	iDeque( nbrs, nbrs + sizeof( nbrs ) / sizeof( int ) );

	easyfind( iVector, TO_FIND );
	easyfind( iList, TO_FIND );
	easyfind( iDeque, TO_FIND );

	return 0;
}
