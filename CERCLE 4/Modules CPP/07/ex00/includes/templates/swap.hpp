#ifndef SWAP_HPP
	#define SWAP_HPP

	template< typename T > 
	void swap( T& A, T& B )
	{
		const T	temp = A;
		A = B;
		B = temp;
	}

#endif
