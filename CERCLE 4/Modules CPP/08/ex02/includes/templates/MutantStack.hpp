#ifndef MUTANT_STACK_HPP
	#define MUTANT_STACK_HPP

	#include <iostream>
	#include <stack>

	template< typename T >
	class MutantStack : public std::stack< T >
	{
		public :

			MutantStack()
			{};
		
			MutantStack( MutantStack& src )
			{ *this = src; };
		
			virtual ~MutantStack()
			{}

			MutantStack& operator=( MutantStack& src )
			{
				( void )src;
				return *this;
			}
			
			typedef typename std::stack< T >::container_type::iterator	iterator;

			iterator	begin( void )
			{ return this->c.begin(); }
			iterator	end( void )
			{ return this->c.end(); }
	};

#endif
