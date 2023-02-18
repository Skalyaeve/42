#ifndef SCAVTRAP_HPP
	#define SCAVTRAP_HPP

	#include "ClapTrap.hpp"

	class ScavTrap : virtual public ClapTrap
	{
		public :

			ScavTrap();
			ScavTrap( const ScavTrap& src );
			ScavTrap( const std::string& str );
			virtual ~ScavTrap();

			ScavTrap&	operator=( const ScavTrap& src );
			
			void		attack( const std::string& target );
			void		guardGate( void );
	};

#endif
