/*
 * customer.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: Amira
 */


#include "session.h"


bool Session::withdraw(const int sum) {

	Customer *cust = dynamic_cast<Customer*>(m_user);
	if (!cust || !bIsLoggedIn)
		return false;

	int oldBalance = cust->getAccount()->getBalance();
	if (cust->getAccount()->getBalance() < sum) {
		return false;
	}

	cust->getAccount()->setBalance(oldBalance - sum);

	// Stricktly verify since it is user money
	if (cust->getAccount()->getBalance() == (oldBalance - sum))
		if (m_db->insertAccount(cust->getAccount()))
			return true;

	return false;
}

bool Session::transfer(const int to, const int sum) {

	Customer *cust = dynamic_cast<Customer*>(this->m_user);
	if (!cust || !bIsLoggedIn)
		return false;

	int oldBalance = cust->getAccount()->getBalance();
	if (cust->getAccount()->getBalance() < sum)
		return false;


	Account *toAccount = m_db->retrieveAccount(to);
	if (toAccount) {
		cust->getAccount()->setBalance(oldBalance - sum);
		int oldAccountBalance = toAccount->getBalance();
		toAccount->setBalance(oldAccountBalance + sum);

		// Stricktly verify since it is user money
		if (toAccount->getBalance() == (oldAccountBalance + sum))
			if (m_db->insertAccount(cust->getAccount())
					&& m_db->insertAccount(toAccount))
				return true;
	}
	return false;
}

bool Session::deposit(const int sum) {

	Customer *cust = dynamic_cast<Customer*>(m_user);
	if (!cust || !bIsLoggedIn)
		return false;

	int oldBalance = cust->getAccount()->getBalance();
	cust->getAccount()->setBalance(sum + oldBalance);

	// Stricktly verify since it is user money
	if (cust->getAccount()->getBalance() == (oldBalance + sum))
		if (m_db->insertAccount(cust->getAccount()))
			return true;

	return false;
}

bool Session::printCustomerInfo() {

	Customer *cust = dynamic_cast<Customer*>(m_user);
	if (!cust || !bIsLoggedIn)
		return false;

	return false;

}

bool Session::printAccountInfo() {
	if (!bIsLoggedIn)
		return false;
	return false;
}
