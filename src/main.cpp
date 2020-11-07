/*
 * main.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */


#include <iostream>
#include "session.h"
#include "admin.h"
#include "employee.h"
#include "account.h"
#include "customer.h"
#include "database.h"
#include <typeinfo>

using namespace std;

int main(){
	Customer *cust = new Customer();
	Account *acct = new Account();
	Admin *adm = new Admin();
	Session *s = new Session();

	adm->setId(1);
	adm->setUserName("kmoussa");
	adm->setFirstName("Khaled");
	adm->setLastName("Moussa");
	adm->setNationalId("45455767878");
	adm->setPassword(s->encrypt("abc123"));
	adm->cap_AdminActivate(true);
	adm->cap_AdminDelete(true);
	adm->cap_AdminCreate(true);
	adm->cap_AdminUpdate(true);
	adm->setCaps(4000);
	//adm->unlock();


	acct->setId(122);
	acct->lock();
	acct->setBalance(10000);

	cust->tmpSetAccount(acct);

	Employee *emp = new Employee();
	emp->cap_AcctActivate(true);
	emp->cap_AcctDeactivate(true);
	emp->cap_AcctCreate(true);

	s->tmpSetUser(adm);


	s->setSessionCapabilities();
	s->printCapabilities();

	//cout << cust->getAccount()->getBalance() << endl;


	Database *db = new Database();
	db->createAccountsTable();
	db->createPersonsTable();
	db->insertPerson(adm);
	db->insertAccount(acct);

	db->deleteAccount(acct);

	return 0;
}
