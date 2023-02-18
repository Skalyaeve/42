#ifndef DOG_HPP
	#define DOG_HPP

	#include "Animal.hpp"
	#include "Brain.hpp"

	class Dog : virtual public Animal
	{
		public :

			Dog();
			Dog( const Dog& src );
			virtual ~Dog();
			
			Dog&			operator=( const Dog& src );

			virtual void	makeSound( void ) const;
			Brain*			getBrain( void ) const;
		
		private :

			Brain*			brain;
	};

#endif
