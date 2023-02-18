#ifndef ROBOTOMY_REQUEST_FORM_HPP
	#define ROBOTOMY_REQUEST_FORM_HPP

	#include <cstdlib>
	#include "AForm.hpp"

	class RobotomyRequestForm : virtual public AForm
	{
		public :

			RobotomyRequestForm();
			RobotomyRequestForm( const RobotomyRequestForm& src );
			RobotomyRequestForm( const std::string& str );
			~RobotomyRequestForm();

			RobotomyRequestForm&	operator=( const RobotomyRequestForm& src );
			
			const std::string		execute( const Bureaucrat& brc );
	};

#endif
