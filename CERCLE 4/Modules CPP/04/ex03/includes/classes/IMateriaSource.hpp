#ifndef I_MATERIA_SOURCE_HPP
	#define I_MATERIA_SOURCE_HPP

	#include "AMateria.hpp"

	class IMateriaSource
	{
		public :

			virtual ~IMateriaSource() {}

			virtual void		learnMateria( AMateria* src ) = 0;
			virtual AMateria*	createMateria( const std::string& type ) const = 0;
	};

#endif
