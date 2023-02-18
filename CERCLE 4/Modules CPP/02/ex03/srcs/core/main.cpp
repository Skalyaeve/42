#include "../../includes/header.hpp"

float ftSqrt( const float nbr )  
{
	if ( nbr <= 0 )
		return 0;
	
	union
	{
		int		i;
		float	x;
	}			u;

	u.x = nbr;
 	u.i = ( 1 << 29 ) + ( u.i >> 1 ) - ( 1 << 22 );
 	u.x = u.x + nbr / u.x;
 	u.x = 0.25f * u.x + nbr / u.x;

	return u.x;
} 

Fixed getArea( const Fixed* norm )
{
	Fixed a, b, c, d;

	a = ( norm[ 0 ].toFloat() + norm[ 1 ].toFloat() + norm[ 2 ].toFloat() ) / 2;
	b = ( norm[ 0 ].toFloat() + norm[ 1 ].toFloat() + norm[ 2 ].toFloat() ) / 2 - norm[ 0 ].toFloat();
	c = ( norm[ 0 ].toFloat() + norm[ 1 ].toFloat() + norm[ 2 ].toFloat() ) / 2 - norm[ 1 ].toFloat();
	d = ( norm[ 0 ].toFloat() + norm[ 1 ].toFloat() + norm[ 2 ].toFloat() ) / 2 - norm[ 2 ].toFloat();
	delete[] norm;
	std::cout << "Area is " << Fixed( ftSqrt( a.toFloat() * b.toFloat() * c.toFloat() * d.toFloat() ) ) << std::endl << std::endl;

	return Fixed( ftSqrt( a.toFloat() * b.toFloat() * c.toFloat() * d.toFloat() ) );
}

Fixed* newTriangle( const Point a, const Point b, const Point c )
{
	Fixed* AB = new Fixed[ 2 ];
	Fixed* BC = new Fixed[ 2 ];
	Fixed* CA = new Fixed[ 2 ];
	AB[ 0 ] = b.getX() - a.getX();
	AB[ 1 ] = b.getY() - a.getY();
	BC[ 0 ] = c.getX() - b.getX();
	BC[ 1 ] = c.getY() - b.getY();
	CA[ 0 ] = a.getX() - c.getX();
	CA[ 1 ] = a.getY() - c.getY();

	Fixed* norm = new Fixed[ 3 ];
	norm[ 0 ] = Fixed( ftSqrt( ( AB[ 0 ].toFloat() * AB[ 0 ].toFloat() ) + ( AB[ 1 ].toFloat() * AB[ 1 ].toFloat() ) ) );
	norm[ 1 ] = Fixed( ftSqrt( ( BC[ 0 ].toFloat() * BC[ 0 ].toFloat() ) + ( BC[ 1 ].toFloat() * BC[ 1 ].toFloat() ) ) );
	norm[ 2 ] = Fixed( ftSqrt( ( CA[ 0 ].toFloat() * CA[ 0 ].toFloat() ) + ( CA[ 1 ].toFloat() * CA[ 1 ].toFloat() ) ) );

	std::cout << "New triangle created from ( " << a << " ), ( " << b << " ), ( " << c << " ) ==>" << std::endl;
	std::cout << "vector1( " << AB[ 0 ] << ", " << AB[ 1 ] << " ) -> norm is " << norm[ 0 ] << std::endl;
	std::cout << "vector2( " << BC[ 0 ] << ", " << BC[ 1 ] << " ) -> norm is " << norm[ 1 ] << std::endl;
	std::cout << "vector3( " << CA[ 0 ] << ", " << CA[ 1 ] << " ) -> norm is " << norm[ 2 ] << std::endl;

	delete[] AB;
	delete[] BC;
	delete[] CA;

	return norm;
}

bool bsp( const Point a, const Point b, const Point c, const Point point )
{
	std::cout << "[ Managing triangle A( " << a << " ) | B( " << b << " ) | C( " << c << " ) & point( " << point << " ) ]" << std::endl << std::endl;

	Fixed diff = getArea( newTriangle( a, b, c ) ) - getArea( newTriangle( a, b, point ) )
		- getArea( newTriangle( a, c, point ) ) - getArea( newTriangle( c, b, point ) );
	std::cout << "Diff is " << diff << std::endl;
	if ( diff.toFloat() < -0.075f )
		return false;
	return true;
}

int main( void )
{
	Point a( 2.0f, 4.0f );
	Point b( 0.0f, 1.0f );
	Point c( 4.0f, 1.0f );
	Point x( 3.9f, 1.1f );

	if ( bsp( a, b, c, x ) )
		std::cout << "[ Point is inside ]" << std::endl;
	else
		std::cout << "[ Point is outside ]" << std::endl;
	return 0;
}
