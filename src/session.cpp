/*
 * session.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Amira
 */

#include "session.h"

void Session::setUserType() {
	if (typeid(*m_user) == typeid(Customer))      m_userType = CUSTOMER;
	else if (typeid(*m_user) == typeid(Employee)) m_userType = EMPLOYEE;
	else if (typeid(*m_user) == typeid(Admin))    m_userType = ADMIN;
	else m_userType = UNKNOWN;
}

Person* Session::login(const string username, const string password) {
	return nullptr;
}

Person* Session::login(int userid, string password) {
	return nullptr;
}

void Session::logout() {
}

string Session::encrypt(const string word) {
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
		if (dynamic_cast<Admin*>(m_user)->canCreateAccount())     m_capabilities.push_back(ACCOUNT_CREATE);
		if (dynamic_cast<Admin*>(m_user)->canUpdateAccount())     m_capabilities.push_back(ACCOUNT_UPDATE);
		if (dynamic_cast<Admin*>(m_user)->canDeleteAccount())     m_capabilities.push_back(ACCOUNT_DELETE);
		if (dynamic_cast<Admin*>(m_user)->canActivateAccount())   m_capabilities.push_back(ACCOUNT_ACTIVATE);
		if (dynamic_cast<Admin*>(m_user)->canDeactivateAccount()) m_capabilities.push_back(ACCOUNT_DEACTIVATE);
		if (dynamic_cast<Admin*>(m_user)->canListAllAccounts())   m_capabilities.push_back(ACCOUNT_LIST_ALL);
		if (dynamic_cast<Admin*>(m_user)->canPrintAccountInfo())  m_capabilities.push_back(ACCOUNT_PRINT_INFO);
		if (dynamic_cast<Admin*>(m_user)->canPrintCustomerInfo()) m_capabilities.push_back(CUSTOMER_PRINT_INFO);
		if (dynamic_cast<Admin*>(m_user)->canCreateCustomer())    m_capabilities.push_back(CUSTOMER_CREATE);
		if (dynamic_cast<Admin*>(m_user)->canUpdateCustomer())    m_capabilities.push_back(CUSTOMER_UPDATE);
		if (dynamic_cast<Admin*>(m_user)->canDeleteCustomer())    m_capabilities.push_back(CUSTOMER_DELETE);
		if (dynamic_cast<Admin*>(m_user)->canListAllCustomers())  m_capabilities.push_back(CUSTOMER_LIST_ALL);

		break;
	}
	default:
		break;
	}
}

void Session::printCapabilities() {
	for (vector<int>::iterator it = m_capabilities.begin(); it != m_capabilities.end() ; ++it) {
		switch (*it) {
		case ACCOUNT_CREATE:
			m_capabilitiesLabels.push_back("Create Account");
			break;
		case ACCOUNT_DELETE:
			m_capabilitiesLabels.push_back("Delete Account");
			break;
		case ACCOUNT_UPDATE:
			m_capabilitiesLabels.push_back("Update Account");
			break;
		case ACCOUNT_ACTIVATE:
			m_capabilitiesLabels.push_back("Activate Account");
			break;
		case ACCOUNT_DEACTIVATE:
			m_capabilitiesLabels.push_back("Deactivate Account");
			break;
		case ACCOUNT_LIST_ALL:
			m_capabilitiesLabels.push_back("List All Accounts");
			break;
		case ACCOUNT_PRINT_INFO:
			m_capabilitiesLabels.push_back("Print Account Information");
			break;
		case CUSTOMER_CREATE:
			m_capabilitiesLabels.push_back("Create a new Customer");
			break;
		case CUSTOMER_UPDATE:
			m_capabilitiesLabels.push_back("Update Existing Customer");
			break;
		case CUSTOMER_DELETE:
			m_capabilitiesLabels.push_back("Delete Customer");
			break;
		case CUSTOMER_PRINT_INFO:
			m_capabilitiesLabels.push_back("Print Customer Information");
			break;
		case CUSTOMER_PRINT_OWN_INFO:
			m_capabilitiesLabels.push_back("Print my customer Information");
			break;
		case CUSTOMER_LIST_ALL:
			m_capabilitiesLabels.push_back("List All Customers");
			break;
		case CUSTOMER_TRANSFER_TO_ACCOUNT:
			m_capabilitiesLabels.push_back("Transfer money to another Account");
			break;
		case ADMIN_CREATE:
			m_capabilitiesLabels.push_back("Create Administrator");
			break;
		case ADMIN_UPDATE:
			m_capabilitiesLabels.push_back("Update Administrator");
			break;
		case ADMIN_DELETE:
			m_capabilitiesLabels.push_back("Delete Administrator");
			break;
		case ADMIN_PRINT_INFO:
			m_capabilitiesLabels.push_back("Print Administrator Information");
			break;
		case ADMIN_LIST_ALL:
			m_capabilitiesLabels.push_back("List All Administrators");
			break;
		case ADMIN_ACTIVATE:
			m_capabilitiesLabels.push_back("Activate Administrator");
			break;
		case ADMIN_DEACTIVATE:
			m_capabilitiesLabels.push_back("Deactivate Administrator");
			break;
		default:
			break;
		}
	}
	for (vector<string>::iterator it = m_capabilitiesLabels.begin(); it != m_capabilitiesLabels.end(); ++it){
		cout << *it << endl;
	}
}
