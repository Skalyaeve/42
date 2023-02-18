#include "../../includes/classes/Form.hpp"

Form::Form() :
name( "UNDEFINED" ), sGrade( 150 ), eGrade( 150 ), isSigned( 0 ), isExecuted( 0 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Form constructor called" << std::endl;
}

Form::Form( const Form& src ) :
name( src.getName() ), sGrade( src.getSgrade() ), eGrade( src.getEgrade() ), isSigned( src.checkSignature() ), isExecuted( src.checkExec() )
{
	std::cout << "[ COPY ][ " << this << " ] Form constructor called" << std::endl;
}

Form::Form( const std::string& str, const short& sNbr, const short& eNbr ) :
name( str ), isSigned( 0 ), isExecuted( 0 )
{
	std::cout << "[ " << str << " | " << sNbr << " | " << eNbr << " ][ " << this << " ] Form constructor called" << std::endl;

	try
	{
		if ( sNbr > 150 )
			throw Form::GradeTooLowException();
		if ( sNbr < 1 )
			throw Form::GradeTooHighException();
		this->sGrade = sNbr;
	}
	catch ( std::exception& e )
	{
		if ( sNbr < 1 )
			this->sGrade = 1;
		if ( sNbr > 150 )
			this->sGrade = 150;
		std::cerr << "\t[ ERROR ] : setting gradeToBeSigned -> " << e.what() << ", setting it to " << this->sGrade << std::endl;
	}

	try
	{
		if ( eNbr > 150 )
			throw Form::GradeTooLowException();
		if ( eNbr < 1 )
			throw Form::GradeTooHighException();
		this->eGrade = eNbr;
	}
	catch ( std::exception& e )
	{
		if ( eNbr < 1 )
			this->eGrade = 1;
		if ( eNbr > 150 )
			this->eGrade = 150;
		std::cerr << "\t[ ERROR ] : setting gradeToBeExecuted -> " << e.what() << ", setting it to " << this->eGrade << std::endl;
	}
}

Form::~Form()
{
	std::cout << "[ " << this << " ][ " << this->name << " ] Form destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream& stream, const Form& src )
{
	if ( src.checkSignature() )
		stream << "[SIGNED]";
	else
		stream << "[TO BE SIGNED]";
	if ( src.checkExec() )
		stream << "[EXECUTED] ";
	else
		stream << "[TO BE EXECUTED] ";
	stream << src.getName() << " -> Grade to be signed : " << src.getSgrade() << " | Grade to be executed : " << src.getEgrade() << std::endl;
	return stream;
}

Form& Form::operator=( const Form& src )
{
	std::cout << "[ " << this << " ][ " << this->name << " ] Form copy assignment operator called" << std::endl;
	this->sGrade = src.getSgrade();
	this->eGrade = src.getEgrade();
	this->isSigned = src.checkSignature();
	this->isExecuted = src.checkExec();
	return *this;
}

const std::string& Form::getName( void ) const
{
	return this->name;
}

const unsigned short& Form::getSgrade( void ) const
{
	return this->sGrade;
}

const unsigned short& Form::getEgrade( void ) const
{
	return this->eGrade;
}

const bool& Form::checkSignature( void ) const
{
	return this->isSigned;
}

const bool& Form::checkExec( void ) const
{
	return this->isExecuted;
}

void Form::upSgrade( void )
{
	try
	{
		if ( this->sGrade == 1 )
			throw Form::GradeTooHighException();
		this->sGrade--;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : upgrading gradeToBeSigned -> " << e.what() << ", can't upgrade" << std::endl;
	}
}

void Form::upEgrade( void )
{
	try
	{
		if ( this->eGrade == 1 )
			throw Form::GradeTooHighException();
		this->eGrade--;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : upgrading gradeToBeExecuted -> " << e.what() << ", can't upgrade" << std::endl;
	}
}

void Form::downSgrade( void )
{
	try
	{
		if ( this->sGrade == 150 )
			throw Form::GradeTooLowException();
		this->sGrade++;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : downgrading gradeToBeSigned -> " << e.what() << ", can't downgrade" << std::endl;
	}
}

void Form::downEgrade( void )
{
	try
	{
		if ( this->eGrade == 150 )
			throw Form::GradeTooLowException();
		this->eGrade++;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : downgrading gradeToBeExecuted -> " << e.what() << ", can't downgrade" << std::endl;
	}
}

const std::string Form::beSigned( const Bureaucrat& brc )
{
	try
	{
		if ( this->isSigned )
			throw Form::FormAlreadySigned();
		if ( brc.getGrade() > this->sGrade )
			throw Form::GradeTooLowException();
		this->isSigned = 1;
		return "done";
	}
	catch ( const std::exception& e )
	{
		const std::string ret = e.what();
		return ret;
	}
	return "failed";
}
