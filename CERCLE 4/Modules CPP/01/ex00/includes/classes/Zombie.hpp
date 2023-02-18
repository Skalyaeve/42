#ifndef ZOMBIE_CLASS_HPP
	#define ZOMBIE_CLASS_HPP

	#include <iostream>

	class Zombie
	{
		public	:

			Zombie();
			Zombie( const std::string& name );
			~Zombie();

			void				announce( void ) const;
			const std::string&	getName( void ) const;

		private	:

			std::string	name;
	};

#endif