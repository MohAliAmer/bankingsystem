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
	adm->cap_acctCreate(true);
	adm->cap_EmployeeCreate(false);
	adm->unlock();

	acct->setId(122);
	acct->lock();
	acct->setBalance(10000);

	cust->tmpSetAccount(acct);

	Employee *emp = new Employee();
	emp->lock();
	emp->setId(2);
	emp->setUserName("amohamed");
	emp->setFirstName("Amira");
	emp->setLastName("Mohamed");
	emp->setNationalId("888877779999");
	emp->setPassword(s->encrypt("test"));
	emp->cap_acctActivate(true);
	emp->cap_acctDeactivate(true);
	emp->cap_acctCreate(true);


	Customer *adam = new Customer();
	adam->lock();
	adam->setId(3);
	adam->setUserName("amoussa");
	adam->setFirstName("Adam");
	adam->setLastName("Moussa");
	adam->setNationalId("1212121");
	adam->setPassword(s->encrypt("mypassword"));


	s->setSessionUser(adm);
	//s->setSessionCapabilities();

	//cout << cust->getAccount()->getBalance() << endl;

	Database *db = new Database();
	db->createAccountsTable();
	db->createPersonsTable();
	db->insertPerson(adm);
	db->insertPerson(emp);
	db->insertAccount(acct);
	db->insertPerson(adam);
	//db->deleteAccount(acct);

	//cout << Session::CUSTOMER_ACTIVATE << endl;

	Person *p = db->retrievePerson("amohamed");
	cout << dynamic_cast<Employee*>(p)->isLocked() << endl;
	cout << p->getFirstName() << endl;
	cout << p->getCaps()<<endl;

	Person *q = db->retrievePerson("kmoussa");
	cout << dynamic_cast<Admin*>(q)->isLocked() << endl;
	cout << q->getFirstName() << endl;
	cout << q->getCaps()<<endl;



	Person *m = db->retrievePerson("amoussa");
	cout << dynamic_cast<Customer*>(m)->isLocked() << endl;
	cout << m->getFirstName() << endl;
	cout << m->getCaps()<<endl;


	Account *aa = db->retrieveAccount(122);
	cout << "Account balance = " << aa->getBalance() << endl;

	return 0;
}
