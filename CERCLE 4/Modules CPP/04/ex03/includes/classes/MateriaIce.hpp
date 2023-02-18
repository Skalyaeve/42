#ifndef MATERIA_ICE_HPP
	#define MATERIA_ICE_HPP

	#include "AMateria.hpp"

	class MateriaIce : virtual public AMateria
	{
		public :

			MateriaIce();
			MateriaIce( const MateriaIce& src );
			virtual ~MateriaIce();

			MateriaIce&	operator=( const MateriaIce& src );

			MateriaIce*	clone() const;
			void		use( const ICharacter& target );
	};

#endif
