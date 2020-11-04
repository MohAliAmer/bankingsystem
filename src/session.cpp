/*
 * session.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Amira
 */

#include "session.h"

#include <iostream>
using namespace std;

void Session::setUserType() {
	if (typeid(*m_user) == typeid(Customer))      m_userType = CUSTOMER;
	else if (typeid(*m_user) == typeid(Employee)) m_userType = EMPLOYEE;
	else if (typeid(*m_user) == typeid(Admin))    m_userType = ADMIN;
	else m_userType = UNKNOWN;
}

Person* Session::login(string username, string password) {
	return nullptr;
}

Person* Session::login(int userid, string password) {
	return nullptr;
}

void Session::logout() {
}

string Session::encrypt(string word) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, word.c_str(), word.length());
    SHA256_Final(hash, &sha256);
    string result = string();
    stringstream sstream;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    	sstream << hex << (int) hash[i];
    	result = sstream.str();
    }
    return result;
}

void Session::setSessionCapabilities() {

	setUserType();
	switch (m_userType) {
	case CUSTOMER:
	{
		m_capabilities.push_back(CUSTOMER_PRINT_OWN_INFO);
		m_capabilities.push_back(CUSTOMER_TRANSFER_TO_ACCOUNT);
		break;
	}

	case EMPLOYEE:
	{
		if (dynamic_cast<Employee*>(m_user)->canCreateAccount())     m_capabilities.push_back(ACCOUNT_CREATE);
		if (dynamic_cast<Employee*>(m_user)->canUpdateAccount())     m_capabilities.push_back(ACCOUNT_UPDATE);
		if (dynamic_cast<Employee*>(m_user)->canDeleteAccount())     m_capabilities.push_back(ACCOUNT_DELETE);
		if (dynamic_cast<Employee*>(m_user)->canActivateAccount())   m_capabilities.push_back(ACCOUNT_ACTIVATE);
		if (dynamic_cast<Employee*>(m_user)->canDeactivateAccount()) m_capabilities.push_back(ACCOUNT_DEACTIVATE);
		if (dynamic_cast<Employee*>(m_user)->canListAllAccounts())   m_capabilities.push_back(ACCOUNT_LIST_ALL);
		if (dynamic_cast<Employee*>(m_user)->canPrintAccountInfo())  m_capabilities.push_back(ACCOUNT_PRINT_INFO);
		if (dynamic_cast<Employee*>(m_user)->canPrintCustomerInfo()) m_capabilities.push_back(CUSTOMER_PRINT_INFO);
		if (dynamic_cast<Employee*>(m_user)->canCreateCustomer())    m_capabilities.push_back(CUSTOMER_CREATE);
		if (dynamic_cast<Employee*>(m_user)->canUpdateCustomer())    m_capabilities.push_back(CUSTOMER_UPDATE);
		if (dynamic_cast<Employee*>(m_user)->canDeleteCustomer())    m_capabilities.push_back(CUSTOMER_DELETE);
		if (dynamic_cast<Employee*>(m_user)->canListAllCustomers())  m_capabilities.push_back(CUSTOMER_LIST_ALL);
		break;
	}

	case ADMIN:
	{
		if (dynamic_cast<Admin*>(m_user)->canCreateAdmin())     m_capabilities.push_back(ADMIN_CREATE);
		if (dynamic_cast<Admin*>(m_user)->canUpdateAdmin())     m_capabilities.push_back(ADMIN_UPDATE);
		if (dynamic_cast<Admin*>(m_user)->canDeleteAdmin())     m_capabilities.push_back(ADMIN_DELETE);
		if (dynamic_cast<Admin*>(m_user)->canActivateAdmin())   m_capabilities.push_back(ADMIN_ACTIVATE);
		if (dynamic_cast<Admin*>(m_user)->canDeactivateAdmin()) m_capabilities.push_back(ADMIN_DEACTIVATE);
		if (dynamic_cast<Admin*>(m_user)->canPrintAdminInfo())  m_capabilities.push_back(ADMIN_PRINT_INFO);
		if (dynamic_cast<Admin*>(m_user)->canListAllAdmin())    m_capabilities.push_back(ADMIN_LIST_ALL);
		break;
	}
	default:
		break;
	}

}
