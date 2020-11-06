/*
 * database.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Amira
 */

#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_

#include <sqlite3.h>
#include "account.h"
#include "person.h"
#include "customer.h"
#include "employee.h"
#include "admin.h"

using namespace std;

#define DBNAME "future_bank.db"

class Database {

private:
	sqlite3 *db;

public:
	Database();
	~Database();
	bool insertAccount(Account *acct);
	bool updateAcount(Account *acct);
	bool deleteAccount(Account *acct);
	Account* retrieveAccount(const int account_id);

	bool insertPerson(Person *p);
	bool updatePerson(Person *p);
	bool deletePerson();
	Person* retrievePerson(const int person_id);
	Person* retrievePerson(const string username);
	Person* retrievePerson(const int person_id, const string username);

};


#endif /* SRC_DATABASE_H_ */
