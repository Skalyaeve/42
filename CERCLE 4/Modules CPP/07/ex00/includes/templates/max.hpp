#ifndef MAX_HPP
	#define MAX_HPP

	template< typename T > 
	const T& max( const T& A, const T& B )
	{
		return A > B ? A : B; 
	}

#endif
