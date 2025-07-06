/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:51:06 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/24 14:37:11 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_nbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	std::cout 	<< "index:" << _accountIndex << ";p_amount:" << _amount 
				<< ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

void Account::_displayTimestamp(void) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
		<< std::setfill('0') << std::setw(2) << ltm->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << ltm->tm_hour
		<< std::setfill('0') << std::setw(2) << ltm->tm_min
		<< std::setfill('0') << std::setw(2) << ltm->tm_sec << "] ";
}
