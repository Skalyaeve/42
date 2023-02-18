#ifndef BRAIN_HPP
	#define BRAIN_HPP

	#include <iostream>

	class Brain
	{
		public :

			Brain();
			Brain( const Brain& src );
			virtual ~Brain();

			Brain&				operator=( const Brain& src );

			const std::string&	getIdea( const int& index ) const;
			void				setIdea( const int& index, const std::string& str );

		private :

			std::string			ideas[ 100 ];
	};

#endif
