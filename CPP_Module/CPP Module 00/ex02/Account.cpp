#include "Account.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>

int		Account::_nbAccounts			= -1;
int		Account::_totalAmount			= 0;
int		Account::_totalNbDeposits 		= 0;
int		Account::_totalNbWithdrawals	= 0;

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account()
{
	_nbAccounts++;
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int 	Account::getNbAccounts(void)		{ return (_nbAccounts);		}
int		Account::getTotalAmount(void)		{ return (_totalAmount);		}
int		Account::getNbDeposits(void)		{ return (_totalNbDeposits);	}
int		Account::getNbWithdrawals(void)		{ return (_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts + 1 << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
	}
	return (true);
}

int Account::checkAmount(void) const { return (0); }

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t cur_timestamp = std::time(nullptr);
	std::tm* cur_date = gmtime(&cur_timestamp);
	std::cout << "[" << cur_date->tm_year + 1900;
	if (cur_date->tm_mon + 1 < 10)
		std::cout << "0" << cur_date->tm_mon + 1;
	else
		std::cout << cur_date->tm_mon + 1;
	if (cur_date->tm_mday < 10)
		std::cout << "0" << cur_date->tm_mday;
	else
		std::cout << cur_date->tm_mday;
	std::cout << "_";
	if (cur_date->tm_hour + 3 > 23)
		cur_date->tm_hour = cur_date->tm_hour - 23;
	if (cur_date->tm_hour + 3 < 10)
		std::cout << "0" << cur_date->tm_hour + 3;
	else
		std::cout << cur_date->tm_hour + 3;
	if (cur_date->tm_min < 10)
		std::cout << "0" << cur_date->tm_min;
	else
		std::cout << cur_date->tm_min;
	if (cur_date->tm_sec < 10)
		std::cout << "0" << cur_date->tm_sec;
	else
		std::cout << cur_date->tm_sec;
	std::cout << "] ";
}
