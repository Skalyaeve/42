#ifndef FORM_HPP
	#define FORM_HPP

	#include <iostream>
	#include "Bureaucrat.hpp"

	class Bureaucrat;

	class Form
	{
		public :

			Form();
			Form( const Form& src );
			Form( const std::string& name, const short& sGrade,const short& eGrade );
			virtual ~Form();

			Form&					operator=( const Form& src );

			const std::string&		getName( void ) const;
			const unsigned short&	getSgrade( void ) const;
			const unsigned short&	getEgrade( void ) const;
			const bool&				checkSignature( void ) const;
			const bool&				checkExec( void ) const;

			void					upSgrade( void );
			void					upEgrade( void );
			void					downSgrade( void );
			void					downEgrade( void );
			const std::string		beSigned( const Bureaucrat& brc );

		private :

			const std::string	name;
			unsigned short		sGrade;
			unsigned short		eGrade;
			bool				isSigned;
			bool				isExecuted;
	
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
			class FormAlreadySigned : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "form already signed"; }
			};	
	};

	std::ostream&	operator<<( std::ostream& stream, const Form& src );

#endif
