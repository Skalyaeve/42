#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#include <iostream>
	#include "AForm.hpp"

	class AForm;

	class Bureaucrat
	{
		public :

			Bureaucrat();
			Bureaucrat( const Bureaucrat& src );
			Bureaucrat( const std::string& str, const short& nbr );
			virtual ~Bureaucrat();

			Bureaucrat&				operator=( const Bureaucrat& src );

			const std::string&		getName( void ) const;
			const unsigned short&	getGrade( void ) const;

			void					upgrade( void );
			void					downgrade( void );
			void					signForm( AForm& form ) const;
			void					executeForm( AForm& form ) const;

		private :

			const std::string	name;
			unsigned short		grade;
	
			class GradeTooLowException : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "grade too low"; }
			};	
			class GradeTooHighException : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "grade too high"; }
			};
	};

	std::ostream&	operator<<( std::ostream& stream, const Bureaucrat& src );

#endif
