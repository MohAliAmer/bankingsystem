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
	void populateCapabilityLabels();

public:
	Session() :  m_user(nullptr), bIsLoggedIn(false), m_userType(UNKNOWN) {}
	~Session();

	enum {
			UNDEFINED = 0,

			ACCOUNT_CREATE = 1,
			ACCOUNT_DELETE = 2,
			ACCOUNT_UPDATE = 4,
			ACCOUNT_ACTIVATE = 8,
			ACCOUNT_DEACTIVATE = 16,
			ACCOUNT_LIST_ALL = 32,
			ACCOUNT_PRINT_INFO = 64,

			CUSTOMER_CREATE = 128,
			CUSTOMER_UPDATE = 256,
			CUSTOMER_DELETE = 512,
			CUSTOMER_ACTIVATE = 1024,
			CUSTOMER_DEACTIVATE = 2048,
			CUSTOMER_PRINT_INFO = 4096,
			CUSTOMER_PRINT_OWN_INFO = 8192,
			CUSTOMER_LIST_ALL = 16384,
			CUSTOMER_TRANSFER_TO_ACCOUNT = 32768,

			EMPLOYEE_CREATE = 65536,
			EMPLOYEE_UPDATE = 131072,
			EMPLOYEE_DELETE = 262144,
			EMPLOYEE_PRINT_INFO = 524288,
			EMPLOYEE_LIST_ALL = 1048576 ,
			EMPLOYEE_ACTIVATE = 2097152,
			EMPLOYEE_DEACTIVATE = 4194304,

			ADMIN_CREATE = 8388608,
			ADMIN_UPDATE = 16777216,
			ADMIN_DELETE = 33554432,
			ADMIN_PRINT_INFO = 67108864,
			ADMIN_LIST_ALL = 134217728,
			ADMIN_ACTIVATE = 268435456,
			ADMIN_DEACTIVATE = 536870912
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

};



#endif /* SRC_SESSION_H_ */
