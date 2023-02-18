#ifndef WRONG_CAT_HPP
	#define WRONG_CAT_HPP

	#include "WrongAnimal.hpp"

	class WrongCat : virtual public WrongAnimal
	{
		public :

			WrongCat();
			WrongCat( const WrongCat& src );
			virtual ~WrongCat();
			
			WrongCat&		operator=( const WrongCat& src );
		
			virtual void	makeSound( void ) const;
	};

#endif
