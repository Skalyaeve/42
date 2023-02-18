#ifndef A_MATERIA_HPP
	#define A_MATERIA_HPP

	#include <iostream>
	#include "ICharacter.hpp"

	class ICharacter;

	class AMateria
	{
		public :

			AMateria();
			AMateria( const AMateria& src );
			AMateria( const std::string& type );
			virtual ~AMateria();

			AMateria&			operator=( const AMateria& src );

			const std::string&	getType() const;

			virtual AMateria*	clone() const = 0;
			virtual void		use( const ICharacter& target );

		protected :
			
			const std::string	type;
	};

#endif
