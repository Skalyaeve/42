#ifndef ARRAY_HPP
	#define ARRAY_HPP

	#include <iostream>

	template< typename T >
	class Array
	{
		public :

			Array() :
			tabSize( 0 ),
			tab( new T[ 0 ] )
			{};
		
			Array( Array& src ) :
			tab( NULL )
			{ *this = src; };
		
			Array( const unsigned int& nbr ) :
			tabSize( nbr ),
			tab( new T[ nbr ] )
			{};
	
			virtual ~Array()
			{ delete[] this->tab; }

			Array& operator=( Array& src )
			{
				this->tabSize = src.size();
				if ( this->tab )
					delete[] this->tab;
				this->tab = new T[ this->tabSize ];
				for ( unsigned int i = 0; i < this->tabSize; i++ )
					this->tab[ i ] = src[ i ];
				return *this;
			}
			
			T& operator[]( const unsigned int& index )
			{
				if ( index >= this->tabSize )
					throw Array::InvalidIndexException();
				else
					return this->tab[ index ];
			}
			
			const unsigned int& size( void ) const
			{ return this->tabSize; }

			void setValue( const unsigned int& index, const T& value )
			{
				try
				{
					if ( index > this->tabSize )
						throw Array::InvalidIndexException();
					this->tab[ index ] = value;
					return this->tab[ index ];
				}
				catch( const std::exception& e )
				{ std::cerr << e.what() << '\n'; }
			}

		private :

			unsigned int	tabSize;
			T*				tab;

			class InvalidIndexException : public std::exception
			{
				public :

					const char* what() const throw()
					{ return "[ ERROR ] : invalid index"; }
			};
	};

#endif
