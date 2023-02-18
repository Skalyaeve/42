#include "../../includes/classes/ClapTrap.hpp"

ClapTrap::ClapTrap() :
name( "UNDEFINED" ), hp( 10 ), energy( 10 ), ad( 0 )
{
	std::cout << "[ DEFAULT ] ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << "[ COPY ][ " << src.getName() << " ] ClapTrap constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap( const std::string& str ) :
name( str ), hp( 10 ), energy( 10 ), ad( 0 )
{
	std::cout << "[ name ][ " << str << " ] ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ " << this->name << " ] ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& src )
{
	std::cout << "[ " << src.getName() << " ] ClapTrap copy assignment operator called" << std::endl;
	this->name = src.getName();
	this->hp = src.getHP();
	this->energy = src.getEnergy();
	this->ad = src.getAD();
	return *this;
}

const std::string& ClapTrap::getName( void ) const
{
	return this->name;
}

const short& ClapTrap::getHP( void ) const
{
	return this->hp;
}

const short& ClapTrap::getEnergy( void ) const
{
	return this->energy;
}

const short& ClapTrap::getAD( void ) const
{
	return this->ad;
}

void ClapTrap::attack( const std::string& target )
{
	if ( this->energy > 0 )
	{
		this->energy--;
		std::cout << "ClapTrap [ " << this->name << " ] attacks [ " << target << " ]" << std::endl;
		std::cout << "ClapTrap [ " << this->name << " ] -> -1 energy (" << this->energy << " left)" << std::endl;
	}
	else
		std::cout << "ClapTrap [ " << this->name << " ] tried to attack [ " << target << " ] but have no energy left" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	this->hp -= amount;
	if ( this->hp < 0 )
		this->hp = 0;
	std::cout << "[ " << this->name << " ] -> -" << amount << " hp (" << this->hp << " left)" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if ( this->energy > 0 )
	{
		this->energy--;
		this->hp += amount;
		std::cout << "[ " << this->name << " ] is healing himself" << std::endl;
		std::cout << "[ " << this->name << " ] -> -1 energy (" << this->energy << " left)" << std::endl;
		std::cout << "[ " << this->name << " ] -> +" << amount << " hp (" << this->hp << " left)" << std::endl;
	}
	else
		std::cout << "[ " << this->name << " ] tried to heal himself but have no energy left" << std::endl;
}
