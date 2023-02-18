#include "../../includes/header.hpp"

Base* generate( void )
{
	srand( time( NULL ) );
	const int random = rand() % 3 + 1;

	if ( random == 1 )
	{
		std::cout << "New Base* instance created -> A*" << std::endl;
		return new A;
	}
	if ( random == 2 )
	{
		std::cout << "New Base* instance created -> B*" << std::endl;
		return new B;
	}
	std::cout << "New Base* instance created -> C*" << std::endl;
	return new C;
}

void identify( Base* p )
{
	std::cout << "Identifying ( Base* )[ " << p << " ]" << std::endl;

	A*	testA = dynamic_cast< A* >( p );
	B*	testB = dynamic_cast< B* >( p );
	C*	testC = dynamic_cast< C* >( p );

	std::cout << std::endl << "Downcasting ( Base* )->( A* ) ..." << std::endl;
	if ( !testA )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ A ]" << std::endl;
	
	std::cout << std::endl << "Downcasting ( Base* )->( B* ) ..." << std::endl;
	if ( !testB )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ B ]" << std::endl;
	
	std::cout << std::endl << "Downcasting ( Base* )->( C* ) ..." << std::endl;
	if ( !testC )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ C ]" << std::endl;
}

void identify( Base& p )
{
	std::cout << "Identifying ( Base& )[ " << &p << " ]" << std::endl;

	A*	testA = dynamic_cast< A* >( &p );
	B*	testB = dynamic_cast< B* >( &p );
	C*	testC = dynamic_cast< C* >( &p );

	std::cout << std::endl << "Downcasting ( &Base )->( A* ) ..." << std::endl;
	if ( !testA )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ A ]" << std::endl;
	
	std::cout << std::endl << "Downcasting ( &Base )->( B* ) ..." << std::endl;
	if ( !testB )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ B ]" << std::endl;
	
	std::cout << std::endl << "Downcasting ( &Base )->( C* ) ..." << std::endl;
	if ( !testC )
		std::cout << "\tFailed : real types doesn't match" << std::endl;
	else
		std::cout << "\tSucess : address of type [ Base ] is now of type [ C ]" << std::endl;
}

int main( void )
{
	Base*	ptr = generate();

	std::cout << std::endl << "\t---------------------" << std::endl << std::endl;
	identify( ptr );
	std::cout << std::endl << "\t---------------------" << std::endl << std::endl;
	identify( *ptr );

	delete ptr;

	return 0;
}
