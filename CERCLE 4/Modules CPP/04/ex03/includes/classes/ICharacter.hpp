#ifndef I_CHARACTER_HPP
	#define I_CHARACTER_HPP

	#include <iostream>
	#include "AMateria.hpp"

	class AMateria;

	class ICharacter
	{
		public :

			virtual ~ICharacter() {}

			virtual const std::string&	getName() const = 0;

			virtual void				equip( AMateria* materia ) = 0;
			virtual void				unequip( const int index ) = 0;
			virtual void				use( const int index, const ICharacter& target ) = 0;
	};

#endif
