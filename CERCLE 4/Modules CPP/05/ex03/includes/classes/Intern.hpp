#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "PresidentialPardonForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "ShrubberyCreationForm.hpp"

	class Intern
	{
		public :

			Intern();
			Intern( const Intern& src );
			~Intern();

			Intern&	operator=( const Intern& src );

			AForm*	makeForm( const std::string& name, const std::string& target ) const;

		private :

			AForm*			formType[ 3 ];
	
			class UnknowType : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "unknow form type"; }
			};
	};

#endif
