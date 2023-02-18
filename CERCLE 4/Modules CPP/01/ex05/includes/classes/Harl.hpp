#ifndef HARL_CLASS_HPP
	#define HARL_CLASS_HPP

	#include <iostream>

	class Harl
	{
		public	:

			Harl();
			~Harl();

			void	complain( const std::string str ) const;

		private	:

			void	debug( void ) const;
			void	info( void ) const;
			void	warning( void ) const;
			void	error( void ) const;
	};

#endif
