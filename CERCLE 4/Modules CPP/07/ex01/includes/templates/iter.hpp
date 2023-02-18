#ifndef ITER_HPP
	#define ITER_HPP

	#include <iostream>
	#include <functional>

	template< typename T > 
	void iter( T* tab, const unsigned long long size, void ( *func )( T& ) )
	{
		for ( unsigned long long i = 0; i < size; i++ )
			func( tab[ i ] );
	}

#endif
