#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

Account::Account() :
_accountIndex( this->getNbAccounts() ), _amount( 0 ),_nbDeposits( 0 ), _nbWithdrawals( 0 )
{
	this->_nbAccounts++;
	this->_accountIndex++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< 0 << ";created" << std::endl;
}

Account::Account( int initial_deposit ) :
_accountIndex( this->getNbAccounts() - 1 ), _amount( initial_deposit ),_nbDeposits( 0 ), _nbWithdrawals( 0 )
{
	this->_totalAmount += initial_deposit;
	this->_nbAccounts++;
	this->_accountIndex++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"	
		<< initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
	this->_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";closed";
	if ( this->_nbAccounts )
		std::cout << std::endl;
}

void Account::makeDeposit( int deposit )
{
	this->_totalNbDeposits++;
	this->_nbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount << ";deposit:" << deposit << ";amount:"
		 << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_totalAmount += deposit;
	this->_amount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount << ";withdrawal:";
	if ( checkAmount() - withdrawal < 0 )
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount() const
{
	return this->_amount;
}

void Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
		<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	using std::chrono::system_clock;

	std::time_t		ToTimeT = system_clock::to_time_t ( system_clock::now() );
	struct std::tm*	Time = std::localtime( &ToTimeT );

	std::cout << "[" << std::put_time( Time, "%Y%m%d" ) << "_"
		<< std::put_time( Time, "%H%M%S" ) << "] ";
}

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;