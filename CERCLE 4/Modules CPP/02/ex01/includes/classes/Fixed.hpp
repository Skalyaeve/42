#ifndef FIXED_CLASS_HPP
	#define FIXED_CLASS_HPP

	#include <iostream>
	#include <math.h>  

	class Fixed
	{
		public	:

			Fixed();
			Fixed( const Fixed& src );
			Fixed( const int src );
			Fixed( const float src );
			~Fixed();

			Fixed&	operator=( const Fixed& src );

			int		getRawBits( void ) const;
			void	setRawBits( const int src );
			float	toFloat( void ) const;
			int		toInt( void ) const;

		private	:

			int					nbr;
			static const int	fBits;
	};

	std::ostream& operator<<( std::ostream& stream, const Fixed& ptr );

#endif
