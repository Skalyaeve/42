#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

	#include <iostream>

	template< typename T >
	void easyfind( T& container, long long value )
	{
		const typename T::iterator it = find( container.begin(), container.end(), value );
		if ( it != container.end() )
			std::cout << value << " found in container" << std::endl;
		else
			std::cout << value << " not found in container" << std::endl;
	}

#endif
