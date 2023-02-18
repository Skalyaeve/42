#ifndef ANIMAL_HPP
	#define ANIMAL_HPP

	#include <iostream>

	class Animal
	{
		public :

			Animal();
			Animal( const Animal& src );
			virtual ~Animal();

			Animal&				operator=( const Animal& src );

			const std::string&	getType( void ) const;

			virtual void		makeSound( void ) const;

		protected :

			std::string			type;
	};

#endif
