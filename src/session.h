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
	vector<string> m_capabilitiesLabels;
	void setUserType();
	void setSessionCapabilities();

public:
	Session() :  m_user(nullptr), bIsLoggedIn(false), m_userType(UNKNOWN) {}
	~Session();

	enum {
			UNDEFINED = 0,

			ACCOUNT_CREATE = (1 << 0),
			ACCOUNT_DELETE = (1 << 1),
			ACCOUNT_UPDATE = (1 << 2),
			ACCOUNT_ACTIVATE = (1 << 3),
			ACCOUNT_DEACTIVATE = (1 << 4),
			ACCOUNT_LIST_ALL = (1 << 5),
			ACCOUNT_PRINT_INFO = (1 << 6),

			CUSTOMER_CREATE = (1 << 7),
			CUSTOMER_UPDATE = (1 << 8),
			CUSTOMER_DELETE = (1 << 9),
			CUSTOMER_ACTIVATE = (1 << 10),
			CUSTOMER_DEACTIVATE = (1 << 11),
			CUSTOMER_PRINT_INFO = (1 << 12),
			CUSTOMER_PRINT_OWN_INFO = (1 << 13),
			CUSTOMER_LIST_ALL = (1 << 14),
			CUSTOMER_TRANSFER_TO_ACCOUNT = (1 << 15),

			EMPLOYEE_CREATE = (1 << 16),
			EMPLOYEE_UPDATE = (1 << 17),
			EMPLOYEE_DELETE = (1 << 18),
			EMPLOYEE_PRINT_INFO = (1 << 19),
			EMPLOYEE_LIST_ALL = (1 << 20),
			EMPLOYEE_ACTIVATE = (1 << 21),
			EMPLOYEE_DEACTIVATE = (1 << 22),

			ADMIN_CREATE = (1 << 23),
			ADMIN_UPDATE = (1 << 24),
			ADMIN_DELETE = (1 << 25),
			ADMIN_PRINT_INFO = (1 << 26),
			ADMIN_LIST_ALL = (1 << 27),
			ADMIN_ACTIVATE = (1 << 28),
			ADMIN_DEACTIVATE = (1 << 29)
		};

		enum {
			UNKNOWN,
			ADMIN,
			EMPLOYEE,
			CUSTOMER
		};

	Person* login(const string username, const string password);
	void logout();
	bool changePassword(Person *p, const string newpassword);
	string encrypt(const string word);

	void setSessionUser(Person *p) {
		m_user = p;
		setSessionCapabilities();
	}

};



#endif /* SRC_SESSION_H_ */
