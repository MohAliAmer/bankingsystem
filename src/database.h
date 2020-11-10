/*
 * database.h
 *
 *  Created on: Nov 6, 2020
 *      Author: Amira
 */

#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_

#include <vector>
#include <map>
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
	bool initDB();
	int setUserType(Person *p);
	int computeUserCaps(Person *p);
	bool createAccountsTable();
	bool createPersonsTable();
	int getUsersCount();

public:
	Database();
	~Database();

	bool insertAccount(Account *acct);
	bool deleteAccount(Account *acct);
	Account* retrieveAccount(const int account_id);
	Account* retrieveAccountByCustomer(const int customer_id);

	bool insertPerson(Person *p);
	bool deletePerson(Person *p);
	Person* retrievePerson(const string username);

	int generateAccountNumber();
	int generatePersonNumber();

	vector<Person*> getAllPersons(int person_type);
	vector<Account*> getAllAccounts();


};


#endif /* SRC_DATABASE_H_ */
