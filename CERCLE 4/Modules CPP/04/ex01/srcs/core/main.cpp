#include "../../includes/header.hpp"

#define	NBR_OF_ANIMALS	4

int main( void )
{
	Animal*	Animals[ NBR_OF_ANIMALS ];

	for ( short i = 0; i < NBR_OF_ANIMALS; i++ )
	{
		if ( i % 2 )
			Animals[ i ] = new Cat();
		else
			Animals[ i ] = new Dog();
	}

	std::cout << std::endl << std::endl;
	for ( short i = 0; i < NBR_OF_ANIMALS; i++ )
	{
		if ( i % 2 )
			Animals[ i ]->getBrain()->setIdea( 0, "sleep");
		else
			Animals[ i ]->getBrain()->setIdea( 0, "eat");
	}

	std::cout << std::endl << std::endl;
	for ( short i = 0; i < NBR_OF_ANIMALS; i++ )
		std::cout << Animals[ i ]->getType() << " wants to " << std::endl << Animals[ i ]->getBrain()->getIdea( 0 ) << std::endl << std::endl;

	std::cout << std::endl;
	*( Animals[ 0 ] ) = *( Animals[ 1 ] );
	*( Animals[ 0 ]->getBrain() ) = *( Animals[ 1 ]->getBrain() );
	std::cout << "-----------------------------" << std::endl;
	for ( short i = 1; i < 4; i++ )
		delete Animals[ i ];
		
	std::cout << std::endl << std::endl;
	std::cout << Animals[ 0 ]->getType() << " wants to " << std::endl << Animals[ 0 ]->getBrain()->getIdea( 0 ) << std::endl << std::endl;

	std::cout << std::endl;
	delete Animals[ 0 ];
	return 0;
}
