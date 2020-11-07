/*
 * session.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Amira
 */

#include "session.h"

void Session::setUserType() {
	if (typeid(*m_user) == typeid(Customer))
		m_userType = CUSTOMER;
	else if (typeid(*m_user) == typeid(Employee))
		m_userType = EMPLOYEE;
	else if (typeid(*m_user) == typeid(Admin))
		m_userType = ADMIN;
	else
		m_userType = UNKNOWN;
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

	int usercaps = 0;
	setUserType();

	switch (m_userType) {

	case CUSTOMER:
	{
		m_capabilities.push_back(CUSTOMER_PRINT_OWN_INFO);
		m_capabilities.push_back(CUSTOMER_TRANSFER_TO_ACCOUNT);
		m_capabilitiesLabels.push_back("Print my customer Information");
		m_capabilitiesLabels.push_back("Transfer money to another Account");

		break;
	}

	case EMPLOYEE:
	{
		if (dynamic_cast<Employee*>(m_user)->canCreateAccount()) {
			m_capabilities.push_back(ACCOUNT_CREATE);
			m_capabilitiesLabels.push_back("Create Account");
		}
 		if (dynamic_cast<Employee*>(m_user)->canUpdateAccount()) {
			m_capabilities.push_back(ACCOUNT_UPDATE);
			m_capabilitiesLabels.push_back("Update Account");
 		}
		if (dynamic_cast<Employee*>(m_user)->canDeleteAccount()) {
			m_capabilities.push_back(ACCOUNT_DELETE);
			m_capabilitiesLabels.push_back("Delete Account");
		}
		if (dynamic_cast<Employee*>(m_user)->canActivateAccount()) {
			m_capabilities.push_back(ACCOUNT_ACTIVATE);
			m_capabilitiesLabels.push_back("Activate Account");
		}
		if (dynamic_cast<Employee*>(m_user)->canDeactivateAccount()) {
			m_capabilities.push_back(ACCOUNT_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Account");
		}
		if (dynamic_cast<Employee*>(m_user)->canListAllAccounts()) {
			m_capabilities.push_back(ACCOUNT_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Accounts");
		}
		if (dynamic_cast<Employee*>(m_user)->canPrintAccountInfo()) {
			m_capabilities.push_back(ACCOUNT_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print Account Information");
		}

		if (dynamic_cast<Employee*>(m_user)->canCreateCustomer()) {
			m_capabilities.push_back(CUSTOMER_CREATE);
			m_capabilitiesLabels.push_back("Create a new Customer");
		}
		if (dynamic_cast<Employee*>(m_user)->canUpdateCustomer()) {
			m_capabilities.push_back(CUSTOMER_UPDATE);
			m_capabilitiesLabels.push_back("Update Existing Customer");
		}
		if (dynamic_cast<Employee*>(m_user)->canDeleteCustomer()) {
			m_capabilities.push_back(CUSTOMER_DELETE);
			m_capabilitiesLabels.push_back("Delete Customer");
		}
		if (dynamic_cast<Employee*>(m_user)->canActivateCustomer()) {
			m_capabilities.push_back(CUSTOMER_ACTIVATE);
			m_capabilitiesLabels.push_back("Activate Customer");
		}
		if (dynamic_cast<Employee*>(m_user)->canDeactivateCustomer()) {
			m_capabilities.push_back(CUSTOMER_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Customer");
		}
		if (dynamic_cast<Employee*>(m_user)->canListAllCustomers()) {
			m_capabilities.push_back(CUSTOMER_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Customers");
		}
		if (dynamic_cast<Employee*>(m_user)->canPrintCustomerInfo()) {
			m_capabilities.push_back(CUSTOMER_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print Customer Information");
		}
		break;
	}

	case ADMIN:
	{
		if (dynamic_cast<Admin*>(m_user)->canCreateAdmin()) {
			m_capabilities.push_back(ADMIN_CREATE);
			m_capabilitiesLabels.push_back("Create Administrator");
		}
		if (dynamic_cast<Admin*>(m_user)->canUpdateAdmin()) {
			m_capabilities.push_back(ADMIN_UPDATE);
			m_capabilitiesLabels.push_back("Update Administrator");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeleteAdmin()) {
			m_capabilities.push_back(ADMIN_DELETE);
			m_capabilitiesLabels.push_back("Delete Administrator");
		}
		if (dynamic_cast<Admin*>(m_user)->canActivateAdmin()) {
			m_capabilities.push_back(ADMIN_ACTIVATE);
			m_capabilitiesLabels.push_back("Activate Administrator");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeactivateAdmin()) {
			m_capabilities.push_back(ADMIN_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Administrator");
		}
		if (dynamic_cast<Admin*>(m_user)->canPrintAdminInfo()) {
			m_capabilities.push_back(ADMIN_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print Administrator Information");
		}
		if (dynamic_cast<Admin*>(m_user)->canListAllAdmin()) {
			m_capabilities.push_back(ADMIN_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Administrators");
		}

		if (dynamic_cast<Admin*>(m_user)->canCreateEmployee()) {
			m_capabilities.push_back(EMPLOYEE_CREATE);
			m_capabilitiesLabels.push_back("Create Employee");
		}
		if (dynamic_cast<Admin*>(m_user)->canUpdateEmployee()) {
			m_capabilities.push_back(EMPLOYEE_UPDATE);
			m_capabilitiesLabels.push_back("Update Employee");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeleteEmployee()) {
			m_capabilities.push_back(EMPLOYEE_DELETE);
			m_capabilitiesLabels.push_back("Delete Employee");
		}
		if (dynamic_cast<Admin*>(m_user)->canActivateEmployee()) {
			m_capabilities.push_back(EMPLOYEE_ACTIVATE);
			m_capabilitiesLabels.push_back("Activate Employee");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeactivateEmployee()) {
			m_capabilities.push_back(EMPLOYEE_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Employee");
		}
		if (dynamic_cast<Admin*>(m_user)->canPrintEmployeeInfo()) {
			m_capabilities.push_back(EMPLOYEE_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print Employee Information");
		}
		if (dynamic_cast<Admin*>(m_user)->canListAllEmployee()) {
			m_capabilities.push_back(EMPLOYEE_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Employees");
		}

		if (dynamic_cast<Admin*>(m_user)->canCreateAccount()) {
			m_capabilities.push_back(ACCOUNT_CREATE);
			m_capabilitiesLabels.push_back("Create Account");
		}
		if (dynamic_cast<Admin*>(m_user)->canUpdateAccount()) {
			m_capabilities.push_back(ACCOUNT_UPDATE);
			m_capabilitiesLabels.push_back("Update Account");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeleteAccount()) {
			m_capabilities.push_back(ACCOUNT_DELETE);
			m_capabilitiesLabels.push_back("Delete Account");
		}
		if (dynamic_cast<Admin*>(m_user)->canActivateAccount()) {
			m_capabilities.push_back(ACCOUNT_ACTIVATE);
			m_capabilitiesLabels.push_back("Activate Account");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeactivateAccount()) {
			m_capabilities.push_back(ACCOUNT_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Account");
		}
		if (dynamic_cast<Admin*>(m_user)->canListAllAccounts()) {
			m_capabilities.push_back(ACCOUNT_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Accounts");
		}
		if (dynamic_cast<Admin*>(m_user)->canPrintAccountInfo()) {
			m_capabilities.push_back(ACCOUNT_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print Account Information");
		}


		if (dynamic_cast<Admin*>(m_user)->canCreateCustomer()) {
			m_capabilities.push_back(CUSTOMER_CREATE);
			m_capabilitiesLabels.push_back("Create a new Customer");
		}
		if (dynamic_cast<Admin*>(m_user)->canUpdateCustomer()) {
			m_capabilities.push_back(CUSTOMER_UPDATE);
			m_capabilitiesLabels.push_back("Update Existing Customer");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeleteCustomer()) {
			m_capabilities.push_back(CUSTOMER_DELETE);
			m_capabilitiesLabels.push_back("Delete Customer");
		}
		if (dynamic_cast<Admin*>(m_user)->canActivateCustomer()) {
			m_capabilities.push_back(CUSTOMER_ACTIVATE);
			m_capabilitiesLabels.push_back("Delete Customer");
		}
		if (dynamic_cast<Admin*>(m_user)->canDeactivateCustomer()) {
			m_capabilities.push_back(CUSTOMER_DEACTIVATE);
			m_capabilitiesLabels.push_back("Deactivate Customer");
		}
		if (dynamic_cast<Admin*>(m_user)->canListAllCustomers()) {
			m_capabilities.push_back(CUSTOMER_LIST_ALL);
			m_capabilitiesLabels.push_back("List All Customers");
		}
		if (dynamic_cast<Admin*>(m_user)->canPrintCustomerInfo()) {
			m_capabilities.push_back(CUSTOMER_PRINT_INFO);
			m_capabilitiesLabels.push_back("Print my customer Information");
		}
		break;
	}
	default:
		break;
	}

	for (vector<int>::iterator it = m_capabilities.begin() ; it != m_capabilities.end() ; ++it) {
		usercaps |= *it;
	}
	m_user->setCaps(usercaps);

/*
	for (vector<string>::iterator it = m_capabilitiesLabels.begin(); it != m_capabilitiesLabels.end(); ++it){ // TODO: remove me after
		cout << *it << endl;
	}
*/
}

