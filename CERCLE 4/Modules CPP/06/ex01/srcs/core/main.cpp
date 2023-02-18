#include "../../includes/header.hpp"

uintptr_t serialize( Data* ptr )
{
	return reinterpret_cast< uintptr_t >( ptr );
}

Data* deserialize( uintptr_t serial )
{
	return reinterpret_cast< Data* >( serial );
}

int main( void )
{
	Data	instance1;
	Data*	instance2 = deserialize( serialize( &instance1 ) );

	std::cout << &instance1 << " | " << instance2 << std::endl;

	return 0;
}
