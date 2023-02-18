#ifndef PRINT_VALUE_HPP
	#define PRINT_VALUE_HPP

	#include <iostream>

	template< typename T > 
	void printValue( T& value )
	{
		std::cout << value << std::endl;
	}

#endif
