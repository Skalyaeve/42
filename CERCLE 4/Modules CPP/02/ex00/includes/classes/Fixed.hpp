#ifndef FIXED_CLASS_HPP
	#define FIXED_CLASS_HPP

	#include <iostream>

	class Fixed
	{
		public	:

			Fixed();
			Fixed( const Fixed& src );
			~Fixed();

			Fixed&	operator=( const Fixed& src );

			int		getRawBits( void ) const;
			void	setRawBits( const int raw );

		private	:

			int					nbr;
			static const int	fBits;
	};

#endif
