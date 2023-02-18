#include "../../includes/classes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
name( "UNDEFINED" ), grade( 150 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) :
name( src.getName() ), grade( src.getGrade() )
{
	std::cout << "[ COPY ][ " << this << " ] Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& str, const short& nbr ) :
name( str )
{
	std::cout << "[ " << str << " | " << nbr << " ][ " << this << " ] Bureaucrat constructor called" << std::endl;
	try
	{
		if ( nbr < 1 )
			throw Bureaucrat::GradeTooHighException();
		if ( nbr > 150 )
			throw Bureaucrat::GradeTooLowException();
		this->grade = nbr;
	}
	catch ( std::exception& e )
	{
		if ( nbr < 1 )
			this->grade = 1;
		if ( nbr > 150 )
			this->grade = 150;
		std::cerr << "\t[ ERROR ] : setting grade -> " << e.what() << ", setting it to " << this->grade << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[ " << this << " ][ " << this->name << " ] Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& src )
{
	return stream << src.getName() << ", bureaucrat grade " << src.getGrade();
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src )
{
	std::cout << "[ " << this << " ][ " << this->name << " ] Bureaucrat copy assignment operator called" << std::endl;
	this->grade = src.getGrade();
	return *this;
}

const std::string& Bureaucrat::getName( void ) const
{
	return this->name;
}

const unsigned short& Bureaucrat::getGrade( void ) const
{
	return this->grade;
}

void Bureaucrat::upgrade( void )
{
	try
	{
		if ( this->grade == 1 )
			throw Bureaucrat::GradeTooHighException();
		this->grade--;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : upgrading -> " << e.what() << ", can't upgrade" << std::endl;
	}
}

void Bureaucrat::downgrade( void )
{
	try
	{
		if ( this->grade == 150 )
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : downgrading -> " << e.what() << ", can't downgrade" << std::endl;
	}
}

void Bureaucrat::signForm( AForm& form ) const
{
	const std::string ret = form.beSigned( *this );
	if ( ret == "done" )
		std::cout << "[ " << this << " ] " << this->name << " signed " << form.getName() << std::endl;
	else
		std::cerr << "[ " << this << " ][ ERROR ] : signing form -> " << this->name << " can't sign " << form.getName() << " -> " << ret << std::endl;
}

void Bureaucrat::executeForm( AForm& form ) const
{
	const std::string ret = form.execute( *this );
	if ( ret == "done" )
		std::cout << "[ " << this << " ] " << this->name << " executed " << form.getName() << std::endl;
	else
		std::cerr << "[ " << this << " ][ ERROR ] : executing form -> " << this->name << " can't execute " << form.getName() << " -> " << ret << std::endl;
}
