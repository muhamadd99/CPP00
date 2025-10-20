/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 07:29:29 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/20 17:14:34 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //cin cout endl
#include <string> //std::string
#include <sstream> //stringstream class
#include <ctime>    // for std::time, std::localtime, std::strftime
#include <cstring> //strftime
#include "./Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return (_nbAccounts);	
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);	
}

static std::string	colourNb(int value)
{
	std::stringstream ss;
	ss << value;
	return (BLUE + ss.str() + RESET);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << colourNb(getNbAccounts()) << ';';
	std::cout << "total:" << colourNb(getTotalAmount()) << ';';
	std::cout << "deposits:" << colourNb(getNbDeposits()) << ';';
	std::cout << "withdrawals:" << colourNb(getNbWithdrawals()) << std::endl;
	return ;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << colourNb(_accountIndex)
				<< ";amount:" << colourNb(_amount)
				<< ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << colourNb(_accountIndex)
				<< ";amount:" << colourNb(_amount) 
				<< ";closed" << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << colourNb(_accountIndex)
			  << ";p_amount:" << colourNb(_amount)
			  << ";deposit:" << colourNb(deposit);

	_totalAmount += deposit; //add totalamount
	_totalNbDeposits++; //add numberofdeposits
	
	_amount += deposit; //add _amount
	_nbDeposits++; //add _nbDeposits

	std::cout << ";amount:" << colourNb(_amount)
			  << ";nb_deposits:" << colourNb(_nbDeposits)
			  << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << colourNb(_accountIndex)
		  	  << ";p_amount:" << colourNb(_amount)
		  	  << ";withdrawal:";
	if (withdrawal > _amount || withdrawal <= 0)
	{
		std::cout  << "refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << colourNb(withdrawal)
				  << ";amount:" << colourNb(_amount)
				  << ";nb_withdrawals:" << colourNb(_nbWithdrawals)
				  << std::endl;
		return (true);
	} 
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << colourNb(_accountIndex)
			  << ";amount:" << colourNb(_amount)
			  << ";deposits:" << colourNb(_nbDeposits)
			  << ";withdrawals:" << colourNb(_nbWithdrawals)
			  << std::endl;
}

void Account::_displayTimestamp(void) 
{
	std::time_t now = std::time(0); //get current time since 1970 in secs format
	std::tm* localTime = std::localtime(&now); //tm a struct w/ separated time components

	char buffer[20]; //buffer to store strings
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);//
	std::cout << "[" << buffer << "] ";
}