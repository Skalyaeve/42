#ifndef DIAMONDTRAP_HPP
	#define DIAMONDTRAP_HPP

	#include "ScavTrap.hpp"
	#include "FragTrap.hpp"

	class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
	{
		public	:

			DiamondTrap();
			DiamondTrap( const DiamondTrap& src );
			DiamondTrap( const std::string& str );
			virtual ~DiamondTrap();

			DiamondTrap&		operator=( const DiamondTrap& src );

			const std::string&	getName( void ) const;

			void				attack( const std::string& target );
			void				whoAmI( void ) const;

		private	:

			std::string			name;
	};

#endif
