#ifndef WRONG_ANIMAL_HPP
	#define WRONG_ANIMAL_HPP

	#include <iostream>

	class WrongAnimal
	{
		public :

			WrongAnimal();
			WrongAnimal( const WrongAnimal& src );
			virtual ~WrongAnimal();

			WrongAnimal&		operator=( const WrongAnimal& src );

			const std::string&	getType( void ) const;

			void				makeSound( void ) const;

		protected :

			std::string			type;
	};

#endif
