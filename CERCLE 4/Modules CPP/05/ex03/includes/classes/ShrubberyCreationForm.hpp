#ifndef SHRUBERRY_CREATION_FORM_HPP
	#define SHRUBERRY_CREATION_FORM_HPP

	#include <fstream>
	#include "AForm.hpp"

	class ShrubberyCreationForm : virtual public AForm
	{
		public :

			ShrubberyCreationForm();
			ShrubberyCreationForm( const ShrubberyCreationForm& src );
			ShrubberyCreationForm( const std::string& str );
			~ShrubberyCreationForm();

			ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& src );
			
			const std::string		execute( const Bureaucrat& brc );
			ShrubberyCreationForm*	photocopie( const std::string& str ) const;
	};

#endif
