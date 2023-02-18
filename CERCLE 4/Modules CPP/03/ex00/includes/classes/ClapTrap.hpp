#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP

	#include <iostream>

	class ClapTrap
	{
		public :

			ClapTrap();
			ClapTrap( const ClapTrap& src );
			ClapTrap( const std::string& str );
			virtual ~ClapTrap();

			ClapTrap&			operator=( const ClapTrap& src );

			const std::string&	getName( void ) const;
			const short&		getHP( void ) const;
			const short&		getEnergy( void ) const;
			const short&		getAD( void ) const;

			void				attack( const std::string& target );
			void				takeDamage( unsigned int amount );
			void				beRepaired( unsigned int amount );

		private :

			std::string			name;
			short				hp;
			short				energy;
			short				ad;
	};

#endif
