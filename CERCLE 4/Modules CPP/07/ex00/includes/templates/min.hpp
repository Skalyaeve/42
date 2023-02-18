#ifndef MIN_HPP
	#define MIN_HPP

	template< typename T > 
	const T& min( const T& A, const T& B )
	{
		return A < B ? A : B; 
	}

#endif
