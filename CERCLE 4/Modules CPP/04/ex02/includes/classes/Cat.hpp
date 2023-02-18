#ifndef CAT_HPP
	#define CAT_HPP

	#include "AAnimal.hpp"
	#include "Brain.hpp"

	class Cat : virtual public AAnimal
	{
		public :

			Cat();
			Cat( const Cat& src );
			virtual ~Cat();
			
			Cat&			operator=( const Cat& src );

			virtual void	makeSound( void ) const;
			Brain*			getBrain( void ) const;
		
		private :

			Brain*			brain;
	};

#endif
