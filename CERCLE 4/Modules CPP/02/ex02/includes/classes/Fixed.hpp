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

			Fixed&				operator=( const Fixed& src );
			bool				operator==( const Fixed& value ) const;
			bool				operator!=( const Fixed& value ) const;
			bool				operator>=( const Fixed& value ) const;
			bool				operator<=( const Fixed& value ) const;
			bool				operator>( const Fixed& value ) const;
			bool				operator<( const Fixed& value ) const;
			Fixed				operator+( const Fixed& value ) const;
			Fixed				operator-( const Fixed& value ) const;
			Fixed				operator*( const Fixed& value ) const;
			Fixed				operator/( const Fixed& value ) const;
			Fixed&				operator++( void );
			Fixed				operator++( int );
			Fixed&				operator--( void );
			Fixed				operator--( int );

			int					getRawBits( void ) const;
			void				setRawBits( const int src );
			float				toFloat( void ) const;
			int					toInt( void ) const;

			static Fixed&		min( Fixed& nbr1, Fixed& nbr2 );
			static const Fixed&	min( const Fixed& Instance1, const Fixed& Instance2 );
			static Fixed&		max( Fixed& nbr1, Fixed& nbr2 );
			static const Fixed&	max( const Fixed& Instance1, const Fixed& Instance2 );

		private	:

			int					nbr;
			static const int	fBits;
	};

	std::ostream& operator<<( std::ostream& stream, const Fixed& ptr );

#endif
