#include "../../includes/classes/AForm.hpp"

AForm::AForm() :
name( "UNDEFINED" ), target( "UNDEFINED" ), sGrade( 150 ), eGrade( 150 ), isSigned( 0 ), isExecuted( 0 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] AForm constructor called" << std::endl;
}

AForm::AForm( const AForm& src ) :
name( src.getName() ), target( src.getTarget() ), sGrade( src.getSgrade() ), eGrade( src.getEgrade() ), isSigned( src.checkSignature() ), isExecuted( src.checkExec() )
{
	std::cout << "[ COPY ][ " << this << " ] AForm constructor called" << std::endl;
}

AForm::AForm( const std::string& nStr, const std::string& tStr, const short& sNbr, const short& eNbr ) :
name( nStr ), target( tStr ), isSigned( 0 ), isExecuted( 0 )
{
	std::cout << "[ " << nStr << " | " << tStr << " | " << sNbr << " | " << eNbr << " ][ " << this << " ] AForm constructor called" << std::endl;

	try
	{
		if ( sNbr > 150 )
			throw AForm::GradeTooLowException();
		if ( sNbr < 1 )
			throw AForm::GradeTooHighException();
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
			throw AForm::GradeTooLowException();
		if ( eNbr < 1 )
			throw AForm::GradeTooHighException();
		this->eGrade = eNbr;
	}
	catch ( std::exception& e )
	{
		if ( eNbr < 1 )
			this->eGrade = 1;
		if ( eNbr > 150 )
			this->eGrade = 150;
		std::cerr << "\t[ ERROR ] : setting gradeToBeExecuted -> " << e.what() << " setting it to " << this->eGrade << std::endl;
	}
}

AForm::~AForm()
{
	std::cout << "[ " << this << " ][ " << this->name << " ] AForm destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream& stream, const AForm& src )
{
	if ( src.checkSignature() )
		stream << "[SIGNED]";
	else
		stream << "[TO BE SIGNED]";
	if ( src.checkExec() )
		stream << "[EXECUTED] ";
	else
		stream << "[TO BE EXECUTED] ";
	stream << src.getName() << " -> Grade to be signed : " << src.getSgrade() << " | Grade to be executed : " << src.getEgrade() << " | Target : " << src.getTarget() << std::endl;
	return stream;
}

AForm& AForm::operator=( const AForm& src )
{
	std::cout << "[ " << this << " ][ " << this->name << " ] AForm copy assignment operator called" << std::endl;
	this->sGrade = src.getSgrade();
	this->eGrade = src.getEgrade();
	this->isSigned = src.checkSignature();
	this->isExecuted = src.checkExec();
	return *this;
}

const std::string& AForm::getName( void ) const
{
	return this->name;
}

const std::string& AForm::getTarget( void ) const
{
	return this->target;
}

const unsigned short& AForm::getSgrade( void ) const
{
	return this->sGrade;
}

const unsigned short& AForm::getEgrade( void ) const
{
	return this->eGrade;
}

const bool& AForm::checkSignature( void ) const
{
	return this->isSigned;
}

const bool& AForm::checkExec( void ) const
{
	return this->isExecuted;
}

void AForm::setSgrade( const unsigned short nbr )
{
	try
	{
		if ( nbr < 1 )
			throw AForm::GradeTooHighException();
		if ( nbr > 150 )
			throw AForm::GradeTooLowException();
		this->sGrade = nbr;
	}
	catch ( std::exception& e )
	{
		if ( nbr < 1 )
			this->sGrade = 1;
		if ( nbr > 150 )
			this->sGrade = 150;
		std::cerr << "[ ERROR ] : setting gradeToBeSigned -> " << e.what() << ", setting it to " << this->sGrade << std::endl;
	}
}

void AForm::setEgrade( const unsigned short nbr )
{
	try
	{
		if ( nbr < 1 )
			throw AForm::GradeTooHighException();
		if ( nbr > 150 )
			throw AForm::GradeTooLowException();
		this->sGrade = nbr;
	}
	catch ( std::exception& e )
	{
		if ( nbr < 1 )
			this->sGrade = 1;
		if ( nbr > 150 )
			this->sGrade = 150;
		std::cerr << "[ ERROR ] : setting gradeToBeExecuted -> " << e.what() << ", setting it to " << this->sGrade << std::endl;
	}
}

void AForm::setSignature( const bool state )
{
	this->isSigned = state;
}

void AForm::setExecuteState( const bool state )
{
	this->isExecuted = state;
}

void AForm::upSgrade( void )
{
	try
	{
		if ( this->sGrade == 1 )
			throw AForm::GradeTooHighException();
		this->sGrade--;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : upgrading gradeToBeSigned -> " << e.what() << ", can't upgrade" << std::endl;
	}
}

void AForm::upEgrade( void )
{
	try
	{
		if ( this->eGrade == 1 )
			throw AForm::GradeTooHighException();
		this->eGrade--;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : upgrading gradeToBeExecuted ->  " << e.what() << ", can't upgrade" << std::endl;
	}
}

void AForm::downSgrade( void )
{
	try
	{
		if ( this->sGrade == 150 )
			throw AForm::GradeTooLowException();
		this->sGrade++;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : downgrading gradeToBeSigned ->  " << e.what() << ", can't downgrade" << std::endl;
	}
}

void AForm::downEgrade( void )
{
	try
	{
		if ( this->eGrade == 150 )
			throw AForm::GradeTooLowException();
		this->eGrade++;
	}
	catch ( std::exception& e )
	{
		std::cerr << "[ " << this << " ][ " << this->name << " ][ ERROR ] : downgrading gradeToBeExecuted ->  " << e.what() << ", can't downgrade" << std::endl;
	}
}

const std::string AForm::beSigned( const Bureaucrat& brc )
{
	try
	{
		if ( this->isSigned )
			throw AForm::FormAlreadySigned();
		if ( brc.getGrade() > this->sGrade )
			throw AForm::GradeTooLowException();
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

const std::string AForm::execute( const Bureaucrat& brc )
{
	try
	{
		if ( this->isExecuted )
			throw AForm::FormAlreadyExecuted();
		if ( brc.getGrade() > this->sGrade )
			throw AForm::GradeTooLowException();
		this->isExecuted = 1;
		return "done";
	}
	catch ( const std::exception& e )
	{
		const std::string ret = e.what();
		return ret;
	}
	return "failed";
}

AForm* AForm::photocopie( const std::string& str ) const
{
	( void )str;
	return NULL;
}
