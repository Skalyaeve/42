#ifndef ZOMBIE_CLASS_HPP
	#define ZOMBIE_CLASS_HPP

	#include <iostream>

	class Zombie
	{
		public	:

			Zombie();
			Zombie( const std::string& str );
			~Zombie();

			void				announce( void ) const;
			void				setName( const std::string& str );
			const std::string&	getName( void ) const;

		private	:
		
			std::string	name;
	};

#endif