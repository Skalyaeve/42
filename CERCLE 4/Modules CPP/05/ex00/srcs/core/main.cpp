#include "../../includes/header.hpp"

int main( void )
{
	Bureaucrat	test1;
	Bureaucrat	test2( test1 );
	Bureaucrat	test3( "a", 1 );
	Bureaucrat	test4( "b", 42 );
	Bureaucrat	test5( "c", 150 );
	Bureaucrat	test6( "d", 0 );
	Bureaucrat	test7( "e", 151 );
	Bureaucrat	test8( "f", -42 );

	std::cout << std::endl;
	std::cout << "[ " << &test1 << " ] " << test1 << std::endl;
	std::cout << "[ " << &test2 << " ] " << test2 << std::endl;
	std::cout << "[ " << &test3 << " ] " << test3 << std::endl;
	std::cout << "[ " << &test4 << " ] " << test4 << std::endl;
	std::cout << "[ " << &test5 << " ] " << test5 << std::endl;
	std::cout << "[ " << &test6 << " ] " << test6 << std::endl;
	std::cout << "[ " << &test7 << " ] " << test7 << std::endl;
	std::cout << "[ " << &test8 << " ] " << test8 << std::endl;

	std::cout << std::endl;
	test1.upgrade();
	test2.upgrade();
	test3.upgrade();
	test4.upgrade();
	test5.upgrade();
	test6.upgrade();
	test7.upgrade();
	test8.upgrade();

	std::cout << std::endl;
	std::cout << "[ " << &test1 << " ] " << test1 << std::endl;
	std::cout << "[ " << &test2 << " ] " << test2 << std::endl;
	std::cout << "[ " << &test3 << " ] " << test3 << std::endl;
	std::cout << "[ " << &test4 << " ] " << test4 << std::endl;
	std::cout << "[ " << &test5 << " ] " << test5 << std::endl;
	std::cout << "[ " << &test6 << " ] " << test6 << std::endl;
	std::cout << "[ " << &test7 << " ] " << test7 << std::endl;
	std::cout << "[ " << &test8 << " ] " << test8 << std::endl;

	test1.downgrade();
	test2.downgrade();
	test3.downgrade();
	test4.downgrade();
	test5.downgrade();
	test6.downgrade();
	test7.downgrade();
	test8.downgrade();

	std::cout << std::endl;
	std::cout << "[ " << &test1 << " ] " << test1 << std::endl;
	std::cout << "[ " << &test2 << " ] " << test2 << std::endl;
	std::cout << "[ " << &test3 << " ] " << test3 << std::endl;
	std::cout << "[ " << &test4 << " ] " << test4 << std::endl;
	std::cout << "[ " << &test5 << " ] " << test5 << std::endl;
	std::cout << "[ " << &test6 << " ] " << test6 << std::endl;
	std::cout << "[ " << &test7 << " ] " << test7 << std::endl;
	std::cout << "[ " << &test8 << " ] " << test8 << std::endl;

	std::cout << std::endl;
	test1.downgrade();
	test2.downgrade();
	test3.downgrade();
	test4.downgrade();
	test5.downgrade();
	test6.downgrade();
	test7.downgrade();
	test8.downgrade();

	std::cout << std::endl;
	std::cout << "[ " << &test1 << " ] " << test1 << std::endl;
	std::cout << "[ " << &test2 << " ] " << test2 << std::endl;
	std::cout << "[ " << &test3 << " ] " << test3 << std::endl;
	std::cout << "[ " << &test4 << " ] " << test4 << std::endl;
	std::cout << "[ " << &test5 << " ] " << test5 << std::endl;
	std::cout << "[ " << &test6 << " ] " << test6 << std::endl;
	std::cout << "[ " << &test7 << " ] " << test7 << std::endl;
	std::cout << "[ " << &test8 << " ] " << test8 << std::endl;
	std::cout << std::endl;

	return 0;
}
