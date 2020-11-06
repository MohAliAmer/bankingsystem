/*
 * database.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: Amira
 */

#include "database.h"


Database::Database() : db(nullptr) {

}

Database::~Database() {
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
