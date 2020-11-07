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
	adm->cap_AdminPrintInfo(false);
	adm->cap_AdminActivate(false);
	adm->cap_AdminDeactivate(false);
	adm->cap_AdminDelete(false);
	adm->cap_AdminCreate(false);
	adm->cap_AdminUpdate(false);
	adm->cap_custCreate(false);
	adm->cap_custDelete(true);
	adm->cap_EmployeeCreate(false);
	//adm->setCaps(4000);
	//adm->unlock();

	acct->setId(122);
	acct->lock();
	acct->setBalance(10000);

	cust->tmpSetAccount(acct);

	Employee *emp = new Employee();
	emp->unlock();
	emp->setId(2);
	emp->setUserName("amohamed");
	emp->setFirstName("Amira");
	emp->setLastName("Mohamed");
	emp->setNationalId("888877779999");
	emp->setPassword(s->encrypt("test"));
	emp->cap_AcctActivate(true);
	emp->cap_AcctDeactivate(true);
	emp->cap_AcctCreate(true);



	s->setSessionUser(emp);
	s->setSessionCapabilities();

	//cout << cust->getAccount()->getBalance() << endl;

	Database *db = new Database();
	db->createAccountsTable();
	db->createPersonsTable();
	db->insertPerson(emp);
	db->insertAccount(acct);
	//db->deleteAccount(acct);

	//cout << Session::CUSTOMER_ACTIVATE << endl;

	Person *p = db->retrievePerson("kmoussa");
	cout << p->getCaps();
	return 0;
}
