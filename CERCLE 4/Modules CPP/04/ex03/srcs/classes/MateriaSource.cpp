#include "../../includes/classes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "[ DEFAULT ][ " << this << " ] MateriaSource constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		this->source[ i ] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& src )
{
	std::cout << "[ COPY ][ " << this << " ] MateriaSource constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[ " << this << " ] MateriaSource destructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
		if ( this->source[ i ] )
			delete this->source[ i ];
}

MateriaSource& MateriaSource::operator=( const MateriaSource& src )
{
	std::cout << "[ " << this << " ] MateriaSource copy assignment operator called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		delete this->source[ i ];
		this->source[ i ] = src.getMateria( i )->clone();
	}
	return *this;
}

const AMateria* MateriaSource::getMateria( const int index ) const
{
	if ( index < 0 || index > 3 || !this->source[ index ] )
	{
		std::cout << "[ " << this << " ] [ Character ] ERROR : Index do not refere to a materia" << std::endl;
		return NULL;
	}
	return this->source[ index ];
}
			
void MateriaSource::learnMateria( AMateria* src )
{
	int	i;

	if ( !src )
		return ;
	for ( i = 0; i < 4 && this->source[ i ]; i++ )
		continue ;
	if ( i < 4 )
	{
		this->source[ i ] = src;
		std::cout << "[ " << this << " ] New source -> [ " << this->source[ i ] << " ]" << std::endl;
	}
	else
		std::cout << "[ " << this << " ] [ MateriaSource ] ERROR : Source is full" << std::endl;
}

AMateria* MateriaSource::createMateria( const std::string& type ) const
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->source[ i ]->getType() == type )
		{
			std::cout << "[ " << this << " ] Cloning source -> [ " << this->source[ i ] << " ]" << std::endl;
			return this->source[ i ]->clone();
		}
	}
	std::cout << "[ " << this << " ] [ MateriaSource ] ERROR : Unknow Type" << std::endl;
	return NULL;
}
