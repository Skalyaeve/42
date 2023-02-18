#include "../../includes/classes/Span.hpp"

Span::Span() :
maxSize( 0 ),
size( 0 )
{
}

Span::Span( const Span& src )
{
	*this = src;
}

Span::Span( const unsigned long long& nbr ) :
maxSize( nbr ),
size( 0 )
{
}

Span::~Span()
{
}

Span& Span::operator=( const Span& src )
{
	this->maxSize = src.getMaxSize();
	this->tab = src.getTab();
	this->size = this->tab.size();

	return *this;
}

const std::vector< long long >& Span::getTab( void ) const
{
	return this->tab;
}

const unsigned long long& Span::getSize( void ) const
{
	return this->size;
}

const unsigned long long& Span::getMaxSize( void ) const
{
	return this->maxSize;
}

const long long& Span::getValue( const unsigned long long& index ) const
{
	if ( index >= this->maxSize || index >= this->tab.size() )
		throw Span::InvalidIndexException();
	else
		return *( this->tab.begin() + index );
}

void Span::addNumber( const long long& nbr )
{
	if ( this->size == this->maxSize )
		throw Span::SpanFullException();
	else
	{
		this->tab.push_back( nbr );
		this->size++;
	}
}

void Span::addNumbers( const long long* src, const unsigned long long len )
{
	unsigned long long toAdd = len;
	if ( this->size + toAdd > this->maxSize )
		toAdd = this->maxSize - this->size;
	this->tab.insert( this->tab.end(), src, src + toAdd );
	this->size += toAdd;

	if ( this->size - toAdd + len > this->maxSize )
		throw Span::SpanFullException();
}

unsigned long long Span::shortestSpan( void ) const
{
	if ( this->size < 2 )
		throw Span::NotEnoughtValuesException();
	
	std::list< long long > temp( this->tab.begin(), this->tab.end() );
	temp.sort();
	
	unsigned long long	minDiff;
	if ( *this->tab.begin() > *( this->tab.end() - 1 ) )
		minDiff = *this->tab.begin() - *this->tab.end();
	else
		minDiff = *( this->tab.end() - 1 ) - *this->tab.begin();

	unsigned long long	diff;
	for ( unsigned long long i = 0; i < this->size - 1; i++ )
	{
		if ( *( this->tab.begin() + i ) > *( this->tab.begin() + i + 1 ) )
			diff = *( this->tab.begin() + i ) - *( this->tab.begin() + i + 1 );
		else
			diff = *( this->tab.begin() + i + 1 ) - *( this->tab.begin() + i );
		
		if ( diff < minDiff )
			minDiff = diff;
	}

	return minDiff;
}

unsigned long long Span::longestSpan( void ) const
{
	if ( this->size < 2 )
		throw Span::NotEnoughtValuesException();
	
	long long max = *std::max_element( this->tab.begin(), this->tab.end() );
	long long min = *std::min_element( this->tab.begin(), this->tab.end() );

	return max - min;
}

