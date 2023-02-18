#include "../../includes/header.hpp"

int main( void )
{
	Fixed		a;
	const Fixed	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c( 1.1f );
	Fixed		d( Fixed( 5 ) / Fixed( 2.1f ) );

	std::cout << "a -> " << a << std::endl;
	std::cout << "++a -> " << ++a << std::endl;
	std::cout << "a -> " << a << std::endl;
	std::cout << "a.getRawBits() -> " << a.getRawBits() << std::endl;
	std::cout << "a++ -> " << a++ << std::endl;
	std::cout << "a -> " << a << std::endl;
	std::cout << "a.getRawBits() -> " << a.getRawBits() << std::endl;
	std::cout << "b -> " << b << std::endl;
	std::cout << "c -> " << c << std::endl;
	std::cout << "d -> " << d << std::endl;
	std::cout << "b + d -> " << b + d << std::endl;
	std::cout << "b - d -> " << b - d << std::endl;
	std::cout << "max( a, b ) -> " << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a, b ) -> " << Fixed::min( a, b ) << std::endl;

	return 0;
}
