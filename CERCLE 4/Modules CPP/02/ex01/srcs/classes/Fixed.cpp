#include "../../includes/classes/Fixed.hpp"

Fixed::Fixed() :
nbr( 0 )
{
	std::cout << "Default constructor called " << std::endl;
}

Fixed::Fixed( const int src ) :
nbr( src << this->fBits )
{
	std::cout << "Int constructor called " << std::endl;
}

Fixed::Fixed( const float src ) :
nbr( static_cast< int >( roundf( src * ( 1 << this->fBits ) ) ) )
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->nbr = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->nbr;
}

void Fixed::setRawBits( int const nbr )
{
	this->nbr = nbr;
}

float Fixed::toFloat( void ) const
{
	return static_cast< float >( this->nbr ) / ( 1 << this->fBits );
}

int Fixed::toInt( void ) const
{
	return this->nbr >> this->fBits;
}

const int Fixed::fBits = 8;

std::ostream &operator<<( std::ostream &stream, const Fixed &ptr )
{
	stream << ptr.toFloat();
	return stream;
}