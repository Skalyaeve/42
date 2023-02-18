#include "../../includes/classes/Point.hpp"

Point::Point() :
x( 0 ), y( 0 )
{
}

Point::Point( const Point& src ) :
x( src.getX() ), y( src.getY() )
{
}

Point::Point( const float x, const float y ) :
x( x ), y( y )
{
}

Point::~Point()
{
}

std::ostream& operator<<( std::ostream& stream, const Point& ptr )
{
	stream << ptr.getX() << ", " << ptr.getY();
	return stream;
}

Point& Point::operator=( const Point& src )
{
	( void )src;
	return *this;
}

bool Point::operator!=( const Point& src ) const
{
	if ( this->x != src.getX() )
		return true;
	if ( this->y != src.getY() )
		return true;
	return false;
}

const Fixed& Point::getX( void ) const
{
	return this->x;
}

const Fixed& Point::getY( void ) const
{
	return this->y;
}
