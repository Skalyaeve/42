#include "../../includes/classes/FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap::ClapTrap()
{
	std::cout << "[ DEFAULT ] FragTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 100;
	this->ad = 30;
}

FragTrap::FragTrap( const FragTrap& src ) :
	ClapTrap::ClapTrap( src )
{
	std::cout << "[ COPY ][ " << ClapTrap::getName() << " ] FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string& str ) :
	ClapTrap::ClapTrap( str )
{
	std::cout << "[ name ][ " << ClapTrap::getName() << " ] FragTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 100;
	this->ad = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "[ " << ClapTrap::getName() << " ] FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src )
{
	std::cout << "[ " << src.getName() << " ] FragTrap copy assignment operator called" << std::endl;
	this->name = src.getName();
	this->hp = src.getHP();
	this->energy = src.getEnergy();
	this->ad = src.getAD();
	return *this;
}

void FragTrap::attack( const std::string& target )
{
	if ( ClapTrap::getEnergy() > 0 )
	{
		this->energy = ClapTrap::getEnergy() - 5;
		std::cout << "FragTrap [ " << ClapTrap::getName() << " ] attacks [ " << target << " ]" << std::endl;
		std::cout << "FragTrap [ " << ClapTrap::getName() << " ] -> -5 energy (" << ClapTrap::getEnergy() << " left)" << std::endl;
	}
	else
		std::cout << "FragTrap [ " << ClapTrap::getName() << " ] tried to attack [ " << target << " ] but have no energy left" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "[ " << ClapTrap::getName() << " ] want to [ High Fives ]" << std::endl;
}
