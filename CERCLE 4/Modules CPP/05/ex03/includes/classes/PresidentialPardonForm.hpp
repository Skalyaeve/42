#ifndef PRESIDENTIAL_PARDON_FORM_HPP
	#define PRESIDENTIAL_PARDON_FORM_HPP

	#include "AForm.hpp"

	class PresidentialPardonForm : virtual public AForm
	{
		public :

			PresidentialPardonForm();
			PresidentialPardonForm( const PresidentialPardonForm& src );
			PresidentialPardonForm( const std::string& str );
			~PresidentialPardonForm();

			PresidentialPardonForm&	operator=( const PresidentialPardonForm& src );
			
			const std::string		execute( const Bureaucrat& brc );
			PresidentialPardonForm*	photocopie( const std::string& str ) const;
	};

#endif
