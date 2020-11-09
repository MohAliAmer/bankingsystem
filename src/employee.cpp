/*
 * employee.cpp
 *
 *  Created on: Nov 3, 2020
 *      Author: khaled
 */

#include "session.h"


bool Session::createAccount(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_CREATE))
		return false;


	return false;
}

bool Session::deleteAccount(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_DELETE))
		return false;
	return false;
}

bool Session::updateAccount(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_UPDATE))
		return false;
	return false;
}

bool Session::deactivateAccount(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_DEACTIVATE))
		return false;
	return false;
}

bool Session::activateAccount(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_ACTIVATE))
		return false;
	return false;
}

bool Session::printAccountInfo(Account *acct) {
	if (!bIsLoggedIn || !isAuthorized(Session::ACCOUNT_PRINT_INFO))
		return false;
	return false;
}

bool Session::printAccountInfo() {
	if (!bIsLoggedIn)
		return false;
	return false;
}

bool Session::createCustomer(Customer *customer) {
	if (!bIsLoggedIn || !isAuthorized(Session::CUSTOMER_CREATE))
		return false;
	return false;
}

bool Session::updateCustomer(Customer *customer) {
	if (!bIsLoggedIn || !isAuthorized(Session::CUSTOMER_UPDATE))
		return false;
	return false;
}

bool Session::deleteCustomer(Customer *customer) {
	if (!bIsLoggedIn || !isAuthorized(Session::CUSTOMER_DELETE))
		return false;
	return false;
}

bool Session::printCustomerInfo(Customer *cust) {
	if (!bIsLoggedIn || !isAuthorized(Session::CUSTOMER_PRINT_INFO))
		return false;
	return false;
}


bool Session::ListAllCustomers() {
	if (!bIsLoggedIn || !isAuthorized(Session::CUSTOMER_LIST_ALL))
		return false;
	return false;
}


bool Session::transfer(Account *from, Account *to, const int sum) {
	return false;
}


bool Session::deposit(Account *acct, const int sum) {
	return false;
}





