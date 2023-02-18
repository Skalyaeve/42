#ifndef SPAN_HPP
	#define SPAN_HPP

	#include <iostream>
	#include <vector>
	#include <list>
	#include <algorithm>

	class Span
	{
		public :

			Span( const Span& src );
			Span( const unsigned long long& size );
			virtual ~Span();

			Span&	operator=( const Span& src );

			const unsigned long long&					getSize( void ) const;
			const unsigned long long&					getMaxSize( void ) const;
			const long long&							getValue( const unsigned long long& index ) const;
			const std::vector< long long >&				getTab( void ) const;

			void						addNumber( const long long& nbr );
			void						addNumbers( const long long* src, const unsigned long long len );
			unsigned long long			shortestSpan( void ) const;
			unsigned long long			longestSpan( void ) const;

		private :

			Span();
	
			unsigned long long					maxSize;
			unsigned long long					size;
			std::vector< long long >			tab;

			class InvalidIndexException : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "ERROR : invalid index"; }
			};
			class SpanFullException : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "ERROR : no more space"; }
			};
			class NotEnoughtValuesException : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "ERROR : not enought values"; }
			};
	};

#endif
