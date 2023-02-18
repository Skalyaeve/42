#include "../../includes/classes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap::ClapTrap( "UNDEFINED_clap_name" ),
	ScavTrap::ScavTrap( "UNDEFINED_clap_name" ),
	FragTrap::FragTrap( "UNDEFINED_clap_name" ),
name( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ] DiamondTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->ad = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) :
	ClapTrap::ClapTrap( src ),
	ScavTrap::ScavTrap( src ),
	FragTrap::FragTrap( src ),
name( src.getName() )
{
	std::cout << "[ COPY ][ " << this->name << " ] DiamondTrap constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
}

DiamondTrap::DiamondTrap( const std::string& str ) :
	ClapTrap::ClapTrap( str + "_clap_name" ),
	ScavTrap::ScavTrap( str ),
	FragTrap::FragTrap( str ),
name( str )
{
	std::cout << "[ name ][ " << this->name << " ] DiamondTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->ad = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[ " << this->name << " ] DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& src )
{
	std::cout << "[ " << src.getName() << " ] DiamondTrap copy assignment operator called" << std::endl;
	this->name = src.getName();
	this->hp = src.getHP();
	this->energy = src.getEnergy();
	this->ad = src.getAD();
	return *this;
}

void DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack( target );
}

const std::string& DiamondTrap::getName( void ) const
{
	return this->name;
}

void DiamondTrap::whoAmI( void ) const
{
	std::cout << "[ " << this->name << " ] is a DiamondTrap created from ClapTrap [ " << ClapTrap::getName() << " ]" << std::endl;
}
