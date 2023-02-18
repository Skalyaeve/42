#ifndef A_ANIMAL_HPP
	#define A_ANIMAL_HPP

	#include <iostream>
	#include "Brain.hpp"

	class AAnimal
	{
		public :

			AAnimal();
			AAnimal( const AAnimal& src );
			virtual ~AAnimal();

			AAnimal&				operator=( const AAnimal& src );

			const std::string&	getType( void ) const;

			virtual void		makeSound( void ) const = 0;
			virtual	Brain*		getBrain( void ) const = 0;

		protected :

			std::string			type;
	};

#endif
