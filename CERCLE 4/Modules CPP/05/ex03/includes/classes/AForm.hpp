#ifndef A_FORM_HPP
	#define A_FORM_HPP

	#include <iostream>
	#include "Bureaucrat.hpp"

	class Bureaucrat;

	class AForm
	{
		public :

			AForm();
			AForm( const AForm& src );
			AForm( const std::string& nStr, const std::string& tStr, const short& sNbr, const short& eNbr );
			virtual ~AForm();

			AForm&						operator=( const AForm& src );

			const std::string&			getName( void ) const;
			const std::string&			getTarget( void ) const;
			const unsigned short&		getSgrade( void ) const;
			const unsigned short&		getEgrade( void ) const;
			const bool&					checkSignature( void ) const;
			const bool&					checkExec( void ) const;

			void						upSgrade( void );
			void						upEgrade( void );
			void						downSgrade( void );
			void						downEgrade( void );
			const std::string			beSigned( const Bureaucrat& brc );
			virtual const std::string	execute( const Bureaucrat& brc ) = 0;
			virtual AForm*				photocopie( const std::string& str ) const = 0;

		protected :

			void	setSgrade( const unsigned short nbr );
			void	setEgrade( const unsigned short nbr );
			void	setSignature( const bool state );
			void	setExecuteState( const bool state );

		private :

			const std::string	name;
			const std::string	target;
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
			class FormNotSigned : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "form not signed"; }
			};
			class FormAlreadyExecuted : public std::exception
			{
				public :

					const char*	what() const throw()
					{ return "form already executed"; }
			};
	};

	std::ostream&	operator<<( std::ostream& stream, const AForm& src );

#endif
