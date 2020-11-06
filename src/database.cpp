/*
 * database.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: Amira
 */

#include <iostream>
#include <string>
#include "database.h"

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


Database::Database() : db(nullptr) {
	initDB();
}

Database::~Database() {
}

void Database::initDB() {

	int rc;
	rc = sqlite3_open(DBNAME, &db);

	if(rc) {
		cerr << "Error opening the future bank database: " << sqlite3_errmsg(db) << endl;
		//exit -1;
	}
}

bool Database::createAccountsTable() {
	char *zErrMsg = nullptr;
	int rc;
	string sql;

	sql = "CREATE TABLE IF NOT EXISTS ACCOUNTS(" \
			"ID INT PRIMARY KEY     NOT NULL,"   \
			"BALANCE         INT    NOT NULL);";

	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		cerr <<  "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		return false;
	}
	else
		return true;

	return false;
}

bool Database::createPersonsTable() {

	char *zErrMsg = nullptr;
	int rc;
	string sql;

	sql = "CREATE TABLE IF NOT EXISTS PERSONS(" \
			"ID INT PRIMARY KEY     NOT NULL,"  \
			"BALANCE         INT    NOT NULL);";

	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		cerr <<  "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		return false;
	}
	else
		return true;

	return false;
}

bool Database::insertAccount(Account *acct) {
	return false;
}

bool Database::updateAcount(Account *acct) {
	return false;
}

bool Database::deleteAccount(Account *acct) {
	return false;
}

Account* Database::retrieveAccount(const int account_id) {
	return nullptr;
}

bool Database::insertPerson(Person *p) {
	return false;
}

bool Database::updatePerson(Person *p) {
	return false;
}

bool Database::deletePerson() {
	return false;
}

Person* Database::retrievePerson(const int person_id) {
	return nullptr;
}

Person* Database::retrievePerson(const string username) {
	return nullptr;
}

Person* Database::retrievePerson(const int person_id, const string username) {
	return nullptr;
}
