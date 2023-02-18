#ifndef FRAGTRAP_HPP
	#define FRAGTRAP_HPP

	#include "ClapTrap.hpp"

	class FragTrap : virtual public ClapTrap
	{
		public :

			FragTrap();
			FragTrap( const FragTrap& src );
			FragTrap( const std::string& str );
			virtual ~FragTrap();

			FragTrap&	operator=( const FragTrap& src );
			
			void		attack( const std::string& target );
			void		highFivesGuys( void );
	};

#endif
