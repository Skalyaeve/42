#include "../../includes/classes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain( const std::string str ) const
{
	const std::string	ref[ 4 ] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void				( Harl::*level[ 4 ] )() const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for ( int i = 0; i < 4; i++ )
	{
		if ( !ref[ i ].compare( str ) )
		{
			( this->*( level[ i ] ) )();
			return ;
		}
	} 
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug( void ) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}