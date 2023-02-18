#ifndef POINT_CLASS_HPP
	#define POINT_CLASS_HPP

	#include "Fixed.hpp"
	#include <iostream>

	class Point
	{
		public	:

			Point();
			Point( const Point& src );
			Point( const float x, const float y );
			~Point();

			Point&			operator=( const Point& src );
			bool			operator!=( const Point& value ) const;

			const Fixed&	getX( void ) const;
			const Fixed&	getY( void ) const;

		private	:

			const Fixed	x;
			const Fixed	y;
	};

	std::ostream& operator<<( std::ostream& stream, const Point& ptr );

#endif
