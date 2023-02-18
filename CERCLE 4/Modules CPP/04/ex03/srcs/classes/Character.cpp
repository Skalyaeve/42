#include "../../includes/classes/Character.hpp"

Character::Character() :
name( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Character constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		this->materiaStock[ i ] = NULL;
}

Character::Character( const std::string& str ) :
name( str )
{
	std::cout << "[ " << str << " ][ " << this << " ] Character constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		this->materiaStock[ i ] = NULL;
}

Character::Character( const Character& src ) :
name( src.getName() )
{
	std::cout << "[ COPY ][ " << this << " ] Character constructor called" << std::endl;
	*this = src;
}

Character::~Character()
{
	std::cout << "[ " << this << " ] Character destructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		if ( this->materiaStock[ i ] )
			delete this->materiaStock[ i ];
}

Character& Character::operator=( const Character& src )
{
	std::cout << "[ " << this << " ] Character copy assignment operator called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		delete this->materiaStock[ i ];
		this->materiaStock[ i ] = src.getMateria( i )->clone();
	}
	return *this;
}

const AMateria* Character::getMateria( const int index ) const
{
	if ( index < 0 || index > 3 || !this->materiaStock[ index ] )
	{
		std::cout << "[ " << this << " ] [ Character ] ERROR : Index do not refere to a materia" << std::endl;
		return NULL;
	}
	return this->materiaStock[ index ];
}

const std::string& Character::getName( void ) const
{
	return this->name;
}

void Character::equip( AMateria* materia )
{
	int	i;

	if ( !materia )
		return ;
	for ( i = 0; i < 4 && this->materiaStock[ i ]; i++ )
		continue ;
	if ( i < 4 )
	{
		this->materiaStock[ i ] = materia;
		std::cout << "[ " << this << " ] Getting materia -> [ " << this->materiaStock[ i ] << " ]" << std::endl;
	}
	else
		std::cout << "[ " << this << " ] [ Character ] ERROR : Inventory is full" << std::endl;
}

AMateria* Character::dropIt( const int index ) const
{
	if ( index < 0 || index > 3 || !this->materiaStock[ index ] )
	{
		std::cout << "[ " << this << " ] [ Character ] ERROR : Index do not refere to a materia" << std::endl;
		return NULL;
	}
	std::cout << "[ " << this << " ] Droping materia -> [ " << this->materiaStock[ index ] << " ]" << std::endl;
	return this->materiaStock[ index ];
}

void Character::unequip( const int index )
{
	if ( index < 0 || index > 3 || !this->materiaStock[ index ] )
	{
		std::cout << "[ " << this << " ] [ Character ] ERROR : Index do not refere to a materia" << std::endl;
		return ;
	}
	this->dropIt( index );
	this->materiaStock[ index ] = NULL;
}

void Character::use( const int index, const ICharacter& target )
{
	if ( index < 0 || index > 3 || !this->materiaStock[ index ] )
	{
		std::cout << "[ " << this << " ] [ Character ] ERROR : Index do not refere to a materia" << std::endl;
		return ;
	}
	std::cout << "[ " << this << " ] Using Materia -> [ " << this->materiaStock[ index ] << " ] : ";
	this->materiaStock[ index ]->use( target );
	delete this->materiaStock[ index ];
	this->materiaStock[ index ] = NULL;
}
