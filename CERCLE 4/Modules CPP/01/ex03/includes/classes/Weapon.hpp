#ifndef WEAPON_CLASS_HPP
	#define WEAPON_CLASS_HPP

	#include <iostream>

	class Weapon
	{
		public	:

			Weapon();
			Weapon( const std::string& str );
			~Weapon();

			const std::string&	getType( void ) const;
			void				setType( const std::string& str );

		private	:

			std::string	type;
	};

#endif