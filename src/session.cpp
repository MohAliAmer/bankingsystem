/*
 * session.cpp
 *
 *  Created on: Nov 4, 2020
 *      Author: Amira
 */

#include "session.h"

Session::Session() : m_user(nullptr), bIsLoggedIn(false), m_userType(UNKNOWN) {
	m_db = new Database();
}

Session::~Session() {
	delete m_db;
}

bool Session::isAuthorized(int priv) {
	if (m_user->getCaps() & priv)
		return true;
	return false;
}

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

void Session::logout() {
}

bool Session::changePassword(Person *p, const string newpassword) {
	return false;
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
		m_capabilitiesLabels.push_back("Print my customer Information");
		m_capabilitiesLabels.push_back("Transfer money to another Account");
		break;

	case EMPLOYEE:
		if (dynamic_cast<Employee*>(m_user)->canCreateAccount())
			m_capabilitiesLabels.push_back("Create Account");

		if (dynamic_cast<Employee*>(m_user)->canUpdateAccount())
			m_capabilitiesLabels.push_back("Update Account");

		if (dynamic_cast<Employee*>(m_user)->canDeleteAccount())
			m_capabilitiesLabels.push_back("Delete Account");

		if (dynamic_cast<Employee*>(m_user)->canActivateAccount())
			m_capabilitiesLabels.push_back("Activate Account");

		if (dynamic_cast<Employee*>(m_user)->canDeactivateAccount())
			m_capabilitiesLabels.push_back("Deactivate Account");

		if (dynamic_cast<Employee*>(m_user)->canListAllAccounts())
			m_capabilitiesLabels.push_back("List All Accounts");

		if (dynamic_cast<Employee*>(m_user)->canPrintAccountInfo())
			m_capabilitiesLabels.push_back("Print Account Information");

		if (dynamic_cast<Employee*>(m_user)->canCreateCustomer())
			m_capabilitiesLabels.push_back("Create a new Customer");

		if (dynamic_cast<Employee*>(m_user)->canUpdateCustomer())
			m_capabilitiesLabels.push_back("Update Existing Customer");

		if (dynamic_cast<Employee*>(m_user)->canDeleteCustomer())
			m_capabilitiesLabels.push_back("Delete Customer");

		if (dynamic_cast<Employee*>(m_user)->canActivateCustomer())
			m_capabilitiesLabels.push_back("Activate Customer");

		if (dynamic_cast<Employee*>(m_user)->canDeactivateCustomer())
			m_capabilitiesLabels.push_back("Deactivate Customer");

		if (dynamic_cast<Employee*>(m_user)->canListAllCustomers())
			m_capabilitiesLabels.push_back("List All Customers");

		if (dynamic_cast<Employee*>(m_user)->canPrintCustomerInfo())
			m_capabilitiesLabels.push_back("Print Customer Information");
		break;

	case ADMIN:
		if (dynamic_cast<Admin*>(m_user)->canCreateAdmin())
			m_capabilitiesLabels.push_back("Create Administrator");

		if (dynamic_cast<Admin*>(m_user)->canUpdateAdmin())
			m_capabilitiesLabels.push_back("Update Administrator");

		if (dynamic_cast<Admin*>(m_user)->canDeleteAdmin())
			m_capabilitiesLabels.push_back("Delete Administrator");

		if (dynamic_cast<Admin*>(m_user)->canActivateAdmin())
			m_capabilitiesLabels.push_back("Activate Administrator");

		if (dynamic_cast<Admin*>(m_user)->canDeactivateAdmin())
			m_capabilitiesLabels.push_back("Deactivate Administrator");

		if (dynamic_cast<Admin*>(m_user)->canPrintAdminInfo())
			m_capabilitiesLabels.push_back("Print Administrator Information");

		if (dynamic_cast<Admin*>(m_user)->canListAllAdmin())
			m_capabilitiesLabels.push_back("List All Administrators");

		if (dynamic_cast<Admin*>(m_user)->canCreateEmployee())
			m_capabilitiesLabels.push_back("Create Employee");

		if (dynamic_cast<Admin*>(m_user)->canUpdateEmployee())
			m_capabilitiesLabels.push_back("Update Employee");

		if (dynamic_cast<Admin*>(m_user)->canDeleteEmployee())
			m_capabilitiesLabels.push_back("Delete Employee");

		if (dynamic_cast<Admin*>(m_user)->canActivateEmployee())
			m_capabilitiesLabels.push_back("Activate Employee");

		if (dynamic_cast<Admin*>(m_user)->canDeactivateEmployee())
			m_capabilitiesLabels.push_back("Deactivate Employee");

		if (dynamic_cast<Admin*>(m_user)->canPrintEmployeeInfo())
			m_capabilitiesLabels.push_back("Print Employee Information");

		if (dynamic_cast<Admin*>(m_user)->canListAllEmployee())
			m_capabilitiesLabels.push_back("List All Employees");

		if (dynamic_cast<Admin*>(m_user)->canCreateAccount())
			m_capabilitiesLabels.push_back("Create Account");

		if (dynamic_cast<Admin*>(m_user)->canUpdateAccount())
			m_capabilitiesLabels.push_back("Update Account");

		if (dynamic_cast<Admin*>(m_user)->canDeleteAccount())
			m_capabilitiesLabels.push_back("Delete Account");

		if (dynamic_cast<Admin*>(m_user)->canActivateAccount())
			m_capabilitiesLabels.push_back("Activate Account");

		if (dynamic_cast<Admin*>(m_user)->canDeactivateAccount())
			m_capabilitiesLabels.push_back("Deactivate Account");

		if (dynamic_cast<Admin*>(m_user)->canListAllAccounts())
			m_capabilitiesLabels.push_back("List All Accounts");

		if (dynamic_cast<Admin*>(m_user)->canPrintAccountInfo())
			m_capabilitiesLabels.push_back("Print Account Information");

		if (dynamic_cast<Admin*>(m_user)->canCreateCustomer())
			m_capabilitiesLabels.push_back("Create a new Customer");

		if (dynamic_cast<Admin*>(m_user)->canUpdateCustomer())
			m_capabilitiesLabels.push_back("Update Existing Customer");

		if (dynamic_cast<Admin*>(m_user)->canDeleteCustomer())
			m_capabilitiesLabels.push_back("Delete Customer");

		if (dynamic_cast<Admin*>(m_user)->canActivateCustomer())
			m_capabilitiesLabels.push_back("Delete Customer");

		if (dynamic_cast<Admin*>(m_user)->canDeactivateCustomer())
			m_capabilitiesLabels.push_back("Deactivate Customer");

		if (dynamic_cast<Admin*>(m_user)->canListAllCustomers())
			m_capabilitiesLabels.push_back("List All Customers");

		if (dynamic_cast<Admin*>(m_user)->canPrintCustomerInfo())
			m_capabilitiesLabels.push_back("Print my customer Information");
		break;

	default:
		break;
	}
	/*
	 for (vector<string>::iterator it = m_capabilitiesLabels.begin(); it != m_capabilitiesLabels.end(); ++it){ // TODO: remove me after
	 cout << *it << endl;
	 }
	 */

}

bool Session::withdraw(const int sum) {
	return false;
}

bool Session::transfer(Account *acct, const int sum) {
	return false;
}

bool Session::printCustomerInfo() {
	if (!isAuthorized(Session::CUSTOMER_PRINT_INFO))
		return false;

	return false;

}

bool Session::createAccount(Account *acct) {
	return false;
}

bool Session::deleteAccount(Account *acct) {
	return false;
}

bool Session::updateAccount(Account *acct) {
	return false;
}

bool Session::deactivateAccount(Account *acct) {
	return false;
}

bool Session::activateAccount(Account *acct) {
	return false;
}

bool Session::createCustomer(Customer *customer) {
	return false;
}

bool Session::updateCustomer(Customer *customer) {
	return false;
}

bool Session::deleteCustomer(Customer *customer) {
	return false;
}

bool Session::transfer(Account *from, Account *to, const int sum) {
	return false;
}

bool Session::deposit(Account *acct, const int sum) {
	return false;
}

bool Session::printAllCustomers() {
	return false;
}

bool Session::printCustInfo(Customer *cust) {
	return false;
}

bool Session::printAcctInfo(Account *acct) {
	return false;
}

bool Session::createAdmin(Admin *admin) {
	return false;
}

bool Session::updateAdmin(Admin *admin) {
	return false;
}

bool Session::deleteAdmin(Admin *admin) {
	return false;
}

bool Session::activateAdmin(Admin *admin) {
	return false;
}

bool Session::deactivateAdmin(Admin *admin) {
	return false;
}

bool Session::printAdminInfo(Admin *admin) {
	return false;
}

bool Session::createEmployee(Employee *emp) {
	return false;
}

bool Session::updateEmployee(Employee *emp) {
	return false;
}

bool Session::deleteEmployee(Employee *emp) {
	return false;
}

bool Session::activateEmployee(Employee *emp) {
	return false;
}

bool Session::deactivateEmployee(Employee *emp) {
	return false;
}

bool Session::printEmployeeInfo(Employee *emp) {
	return false;
}

bool Session::printAllAdmins() {
	return false;
}

bool Session::printAllEmployees() {
	return false;
}
