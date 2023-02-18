#ifndef MATERIA_CURE_HPP
	#define MATERIA_CURE_HPP

	#include "AMateria.hpp"

	class MateriaCure : virtual public AMateria
	{
		public :

			MateriaCure();
			MateriaCure( const MateriaCure& src );
			virtual ~MateriaCure();

			MateriaCure&	operator=( const MateriaCure& src );

			MateriaCure*	clone() const;
			void			use( const ICharacter& target );
	};

#endif
