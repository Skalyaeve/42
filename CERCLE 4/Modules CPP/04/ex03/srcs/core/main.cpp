#include "../../includes/header.hpp"

int main( void )
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria( new MateriaIce() );
	src->learnMateria( new MateriaCure() );

	std::cout << std::endl;
	ICharacter*	me = new Character( "me" );
	AMateria*	tmp;
	tmp = src->createMateria( "ice" );
	me->equip( tmp );
	tmp = src->createMateria( "cure" );
	me->equip( tmp );

	std::cout << std::endl;
	ICharacter*	bob = new Character( "bob" );
	me->use( 0, *bob );
	me->use( 1, *bob );

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
