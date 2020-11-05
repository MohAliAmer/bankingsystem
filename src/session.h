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

using namespace std;

class Session {

private:
	Person *m_user;
	bool bIsLoggedIn;
	int m_userType;
	vector<int> m_capabilities;
	vector<string> m_capabilitiesLabels;

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
		CUSTOMER_PRINT_INFO,
		CUSTOMER_PRINT_OWN_INFO,
		CUSTOMER_LIST_ALL,
		CUSTOMER_TRANSFER_TO_ACCOUNT,

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

	void setUserType();

public:
	Session() :  m_user(nullptr), bIsLoggedIn(false), m_userType(UNKNOWN) {}
	~Session();

	Person* login(const string username, const string password);
	Person* login(const int userid, const string password);
	void logout();
	string encrypt(const string word);
	void setSessionCapabilities();
	void tmpSetUser(Person *p) {m_user = p;}
	void printCapabilities();
};



#endif /* SRC_SESSION_H_ */
