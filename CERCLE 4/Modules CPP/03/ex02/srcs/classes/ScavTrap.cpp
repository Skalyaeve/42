#include "../../includes/classes/ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap::ClapTrap()
{
	std::cout << "[ DEFAULT ] ScavTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap( const ScavTrap& src ) :
	ClapTrap::ClapTrap( src )
{
	std::cout << "[ COPY ][ " << ClapTrap::getName() << " ] ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string& str ) :
	ClapTrap::ClapTrap( str )
{
	std::cout << "[ name ][ " << ClapTrap::getName() << " ] ScavTrap constructor called" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->ad = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ " << ClapTrap::getName() << " ] ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src )
{
	std::cout << "[ " << src.getName() << " ] ScavTrap copy assignment operator called" << std::endl;
	this->name = src.getName();
	this->hp = src.getHP();
	this->energy = src.getEnergy();
	this->ad = src.getAD();
	return *this;
}

void ScavTrap::attack( const std::string& target )
{
	if ( ClapTrap::getEnergy() > 0 )
	{
		this->energy = ClapTrap::getEnergy() - 5;
		std::cout << "ScavTrap [ " << ClapTrap::getName() << " ] attacks [ " << target << " ]" << std::endl;
		std::cout << "ScavTrap [ " << ClapTrap::getName() << " ] -> -5 energy (" << ClapTrap::getEnergy() << " left)" << std::endl;
	}
	else
		std::cout << "ScavTrap [ " << ClapTrap::getName() << " ] tried to attack [ " << target << " ] but have no energy left" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "[ " << ClapTrap::getName() << " ] entered [ Gate Keeper ] mode" << std::endl;
}
