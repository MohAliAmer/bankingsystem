/*
 * employee.cpp
 *
 *  Created on: Nov 3, 2020
 *      Author: khaled
 */

#include <assert.h>
#include <typeinfo>
#include "session.h"


bool Session::createAccount(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_CREATE))
		return false;

	assert(typeid(*acct) == typeid(Account));
	if (!acct || m_db->retrieveAccount(acct->getId()))
			return false;

	if (!m_db->insertAccount(acct))
		return false;
	else
		return true;

	return false;
}

bool Session::deleteAccount(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_DELETE))
		return false;

	assert(typeid(*acct) == typeid(Account));
	if (!acct || m_db->retrieveAccount(acct->getId()))
		return false;

	if (!m_db->deleteAccount(acct))
		return false;
	else
		return true;

	return false;
}

bool Session::updateAccount(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_UPDATE))
		return false;

	assert(typeid(*acct) == typeid(Account));
	if (!acct || !m_db->deleteAccount(acct))
		return false;
	else
		return true;

	return false;
}

bool Session::deactivateAccount(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_DEACTIVATE))
		return false;


	assert(typeid(*acct) == typeid(Account));

	if (!acct)
		return false;

	acct->lock();

	if (!m_db->insertAccount(acct))
		return false;
	else
		return true;

	return false;
}

bool Session::activateAccount(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_ACTIVATE))
		return false;

	assert(typeid(*acct) == typeid(Account));
	if (!acct)
		return false;

	acct->unlock();

	if (!m_db->insertAccount(acct))
		return false;
	else
		return true;

	return false;
}

bool Session::printAccountInfo(Account *acct) {
	if (!isAuthorized(Session::ACCOUNT_PRINT_INFO))
		return false;

	assert(typeid(*acct) == typeid(Account));
	if (!acct)
		return false;

	// TODO: Implement the printing here

	return true;
}

bool Session::createCustomer(Customer *customer) {
	if (!isAuthorized(Session::CUSTOMER_CREATE))
		return false;

	assert(typeid(*customer) == typeid(Customer));
	if (!customer || m_db->retrievePerson(customer->getUserName()))
			return false;

	if (!m_db->insertPerson(customer))
		return false;
	else
		return true;

	return false;
}

bool Session::updateCustomer(Customer *customer) {
	if (!isAuthorized(Session::CUSTOMER_UPDATE))
		return false;

	assert(typeid(*customer) == typeid(Customer));
	if (!customer)
		return false;
	else {
		Customer *tmp = dynamic_cast<Customer*>(m_db->retrievePerson(customer->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->insertPerson(customer))
		return false;
	else
		return true;

	return false;
}

bool Session::deleteCustomer(Customer *customer) {
	if (!isAuthorized(Session::CUSTOMER_DELETE))
		return false;

	assert(typeid(*customer) == typeid(Customer));
	if (!customer)
		return false;
	else {
		Customer *tmp = dynamic_cast<Customer*>(m_db->retrievePerson(customer->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->deletePerson(customer))
		return false;
	else
		return true;

	return false;
}

bool Session::printCustomerInfo(Customer *cust) {
	if (!isAuthorized(Session::CUSTOMER_PRINT_INFO))
		return false;

	assert(typeid(*cust) == typeid(Customer));
	if (!cust)
		return false;

	// TODO: Implement the printing here

	return true;
}

bool Session::ListAllCustomers() {
	if (!isAuthorized(Session::CUSTOMER_LIST_ALL))
		return false;

	vector<Person*> customers = m_db->getAllPersons(Session::CUSTOMER);

	if (customers.size() == 0) {
		return false;
	}

	for (Person *customer : customers) {
		delete customer; // TODO: prints customer information instead of deleting it
	}

	return true;
}

bool Session::transfer(Account *from, Account *to, const int sum) {

	if (!from || !to || sum > from->getBalance())
		return false;

	int oldFromBalance = from->getBalance();
	int oldToBalance = to->getBalance();

	int newFromBalance = oldFromBalance - sum;
	int newToBalance = oldToBalance + sum;

	from->setBalance(newFromBalance);
	to->setBalance(newToBalance);

	if (!m_db->insertAccount(from))
		return false;

	if (!m_db->insertAccount(to))
		return false;

	return true;
}

bool Session::deposit(Account *acct, const int sum) {

	assert(typeid(*acct) == typeid(Account));
	if (!acct)
		return false;

	int newBalance = acct->getBalance() + sum;
	acct->setBalance(newBalance);

	if (!m_db->insertAccount(acct))
		return false;

	return true;
}
