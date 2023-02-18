#include "../../includes/classes/Fixed.hpp"

Fixed::Fixed() :
nbr( 0 )
{
}

Fixed::Fixed( const int src ) :
nbr( src << this->fBits )
{
}

Fixed::Fixed( const float src ) :
nbr( static_cast< int >( roundf( src * ( 1 << this->fBits ) ) ) )
{
}

Fixed::Fixed( const Fixed& src )
{
	*this = src;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return this->nbr;
}

void Fixed::setRawBits( int const src )
{
	this->nbr = src;
}

float Fixed::toFloat( void ) const
{
	return static_cast< float >( this->nbr ) / ( 1 << this->fBits );
}

int Fixed::toInt( void ) const
{
	return this->nbr >> this->fBits;
}

std::ostream& operator<<( std::ostream& stream, const Fixed& ptr )
{
	stream << ptr.toFloat();
	return stream;
}

Fixed& Fixed::operator=( const Fixed& src )
{
	this->nbr = src.getRawBits();
	return *this;
}

bool Fixed::operator==( const Fixed& value ) const
{
	return this->nbr == value.getRawBits();
}

bool Fixed::operator!=( const Fixed& value ) const
{
	return this->nbr != value.getRawBits();
}

bool Fixed::operator>=( const Fixed& value ) const
{
	return this->nbr >= value.getRawBits();
}

bool Fixed::operator<=( const Fixed& value ) const
{
	return this->nbr <= value.getRawBits();
}

bool Fixed::operator>( const Fixed& value ) const
{
	return this->nbr > value.getRawBits();
}

bool Fixed::operator<( const Fixed& value ) const
{
	return this->nbr < value.getRawBits();
}

Fixed Fixed::operator+( const Fixed& value ) const
{
	Fixed ret;
	ret.setRawBits( this->nbr + value.getRawBits() );
	return ret;
}

Fixed Fixed::operator-( const Fixed& value ) const
{
	Fixed ret;
	ret.setRawBits( this->nbr - value.getRawBits() );
	return ret;
}

Fixed Fixed::operator*( const Fixed& value ) const
{
	Fixed ret;
	ret.setRawBits( ( this->nbr * value.getRawBits() ) >> this->fBits );
	return ret;
}

Fixed Fixed::operator/( const Fixed& value ) const
{
	Fixed ret;
	ret.setRawBits( ( this->nbr << this->fBits ) / value.getRawBits() );
	return ret;
}

Fixed& Fixed::operator++( void )
{
	this->nbr++;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed i( *this );
	this->operator++();
	return i;
}

Fixed& Fixed::operator--( void )
{
	this->nbr--;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed i( *this );
	this->operator--();
	return i;
}

Fixed& Fixed::min( Fixed& instance1, Fixed& instance2 )
{
	if ( instance1.getRawBits() > instance2.getRawBits() )
		return instance2;
	return instance1;
}

const Fixed& Fixed::min( const Fixed& instance1, const Fixed& instance2 )
{
	if ( instance1.getRawBits() > instance2.getRawBits() )
		return instance2;
	return instance1;
}

Fixed& Fixed::max( Fixed& instance1, Fixed& instance2 )
{
	if ( instance1 > instance2 )
		return instance1;
	return instance2;
}

const Fixed& Fixed::max( const Fixed& instance1, const Fixed& instance2 )
{
	if ( instance1.getRawBits() > instance2.getRawBits() )
		return instance1;
	return instance2;
}

const int Fixed::fBits = 8;
