#ifndef MATERIA_SOURCE_HPP
	#define MATERIA_SOURCE_HPP

	#include "IMateriaSource.hpp"

	class MateriaSource : virtual public IMateriaSource
	{
		public :

			MateriaSource();
			MateriaSource( const MateriaSource& src );
			virtual ~MateriaSource();

			MateriaSource&	operator=( const MateriaSource& src );

			const AMateria*	getMateria( const int index ) const;
			
			void			learnMateria( AMateria* src );
			AMateria*		createMateria( const std::string& type ) const;

		private :

			AMateria*	source[ 4 ];
	};

#endif
