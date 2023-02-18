#ifndef CHARACTER_HPP
	#define CHARACTER_HPP

	#include "ICharacter.hpp"

	class Character : virtual public ICharacter
	{
		public :

			Character();
			Character( const std::string& name );
			Character( const Character& src );
			virtual ~Character();

			Character&			operator=( const Character& src );

			const std::string&	getName() const;
			const AMateria*		getMateria( const int index ) const;

			void				equip( AMateria* materia );
			void				unequip( const int index );
			AMateria*			dropIt( const int index ) const;
			void				use( const int index, const ICharacter& target );

		private :

			const std::string	name;
			AMateria*			materiaStock[ 4 ];
	};

#endif
