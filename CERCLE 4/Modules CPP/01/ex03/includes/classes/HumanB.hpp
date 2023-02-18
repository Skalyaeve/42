#ifndef HUMAN_B_CLASS_HPP
	#define HUMAN_B_CLASS_HPP

	#include <iostream>
	#include "Weapon.hpp"

	class HumanB
	{
		public	:

			HumanB();
			HumanB( const std::string& name );
			HumanB( const std::string& name, Weapon& mainWeapon );
			~HumanB();

			const std::string&	getName( void ) const;
			void				attack( void ) const;
			void				setWeapon( Weapon& mainWeapon );

		private	:

			const std::string	name;
			Weapon*				mainWeapon;
	};

#endif