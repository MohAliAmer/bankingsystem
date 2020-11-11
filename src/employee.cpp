/*
 * employee.cpp
 *
 *  Created on: Nov 3, 2020
 *      Author: khaled
 */

#include <assert.h>
#include <typeinfo>
#include "session.h"
#include "userinterface.h"

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

bool Session::printEmployeeInfo() {
	Employee *emp = dynamic_cast<Employee*>(m_user);
	if (!bIsLoggedIn || !emp)
		return false;

	cout << "Employee Id = " << emp->getId() << endl;
	cout << "Employee username = " << emp->getUserName() << endl;
	cout << "Employee First Name = " << emp->getFirstName() << endl;
	cout << "Employee Last Name = " << emp->getLastName() << endl;
	cout << "Employee National ID = " << emp->getNationalId() << endl;
	cout << "Employee Last Name = " << emp->getLastName() << endl;

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


void Ui::ui_create_customer() {
}

void Ui::ui_update_customer() {
}

void Ui::ui_delete_customer() {

	string username = "";
	Customer *tmp;
	cout << "Enter Customer's user name to delete: ";
	cin >> username;
	tmp = m_session->getCustomer(username);
	if (tmp) {
		if (!m_session->deleteCustomer(tmp))
			cerr << "Failed to delete customer acount: " << username << endl;
		else
			cout << "Deleted customer account: " << username << endl;
	}
	else
		cout << "Failed to query the deleting desired Customer: " << username << endl;
}

void Ui::ui_activate_customer() {
}

void Ui::ui_deactivate_customer() {
}

void Ui::ui_print_customer() {
}

void Ui::ui_listall_customer() {
}

void Ui::ui_create_account() {
}

void Ui::ui_update_account() {
}

void Ui::ui_delete_account() {
}

void Ui::ui_activate_account() {
}

void Ui::ui_deactivate_account() {
}

void Ui::ui_print_account() {
}

void Ui::ui_listall_account() {
}

void Ui::ui_transfer() {
}

void Ui::ui_deposit() {
}

