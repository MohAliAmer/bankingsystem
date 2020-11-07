/*
 * session.h
 *
 *  Created on: Nov 4, 2020
 *      Author: khaled
 */

#ifndef SRC_SESSION_H_
#define SRC_SESSION_H_

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <sstream>
#include "openssl/sha.h"
#include "customer.h"
#include "employee.h"
#include "admin.h"
#include "person.h"
//#include "database.h"

using namespace std;

class Session {

private:
	Person *m_user;
	bool bIsLoggedIn;
	int m_userType;
	vector<int> m_capabilities;
	vector<string> m_capabilitiesLabels;

	void setUserType();

public:
	Session() :  m_user(nullptr), bIsLoggedIn(false), m_userType(UNKNOWN) {}
	~Session();

	enum {
			UNDEFINED,

			ACCOUNT_CREATE,
			ACCOUNT_DELETE,
			ACCOUNT_UPDATE,
			ACCOUNT_ACTIVATE,
			ACCOUNT_DEACTIVATE,
			ACCOUNT_LIST_ALL,
			ACCOUNT_PRINT_INFO,

			CUSTOMER_CREATE,
			CUSTOMER_UPDATE,
			CUSTOMER_DELETE,
			CUSTOMER_ACTIVATE,
			CUSTOMER_DEACTIVATE,
			CUSTOMER_PRINT_INFO,
			CUSTOMER_PRINT_OWN_INFO,
			CUSTOMER_LIST_ALL,
			CUSTOMER_TRANSFER_TO_ACCOUNT,

			EMPLOYEE_CREATE,
			EMPLOYEE_UPDATE,
			EMPLOYEE_DELETE,
			EMPLOYEE_PRINT_INFO,
			EMPLOYEE_LIST_ALL,
			EMPLOYEE_ACTIVATE,
			EMPLOYEE_DEACTIVATE,

			ADMIN_CREATE,
			ADMIN_UPDATE,
			ADMIN_DELETE,
			ADMIN_PRINT_INFO,
			ADMIN_LIST_ALL,
			ADMIN_ACTIVATE,
			ADMIN_DEACTIVATE
		};

		enum {
			UNKNOWN,
			ADMIN,
			EMPLOYEE,
			CUSTOMER
		};

	Person* login(const string username, const string password);
	Person* login(const int userid, const string password);
	void logout();
	bool changePassword(Person *p, const string newpassword);
	string encrypt(const string word);
	void setSessionCapabilities();
	void tmpSetUser(Person *p) {m_user = p;} // TODO: remove me after
	void printCapabilities();
};



#endif /* SRC_SESSION_H_ */
