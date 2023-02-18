#ifndef HUMAN_A_CLASS_HPP
	#define HUMAN_A_CLASS_HPP

	#include <iostream>
	#include "Weapon.hpp"

	class HumanA
	{
		public	:

			HumanA( const std::string& name, Weapon& mainWeapon );
			~HumanA();

			const std::string&	getName( void ) const;
			void				attack( void ) const;
			void				setWeapon( Weapon& mainWeapon );

		private	:

			HumanA();
	
			const std::string	name;
			Weapon&				mainWeapon;
	};

#endif