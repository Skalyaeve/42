#include "../../includes/header.hpp"

int main( void )
{
	const Animal*		aI = new Animal();
	const Animal*		cI = new Cat();
	const Animal*		dI = new Dog();
	const WrongAnimal*	waI = new WrongAnimal();
	const WrongAnimal*	wcI = new WrongCat();

	std::cout << std::endl;
	std::cout << aI->getType() << std::endl;
	std::cout << cI->getType() << std::endl;
	std::cout << dI->getType() << std::endl;
	std::cout << waI->getType() << std::endl;
	std::cout << wcI->getType() << std::endl;

	std::cout << std::endl;
	aI->makeSound();
	cI->makeSound();
	dI->makeSound();
	waI->makeSound();
	wcI->makeSound();

	std::cout << std::endl;
	delete aI;
	delete cI;
	delete dI;
	delete waI;
	delete wcI;

	return 0;
}
