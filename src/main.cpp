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

	Admin *farida = new Admin();
	farida->setId(4);
	farida->setUserName("fmoussa");
	farida->setFirstName("Farida");
	farida->setLastName("Moussa");
	farida->setNationalId("908908324");
	farida->setPassword(s->encrypt("xyz123"));
	farida->cap_AdminPrintInfo(true);
	farida->cap_AdminActivate(true);
	farida->cap_AdminDeactivate(true);
	farida->cap_AdminDelete(true);
	farida->cap_AdminCreate(true);
	farida->cap_AdminUpdate(true);
	farida->cap_custCreate(true);
	farida->cap_custDelete(true);
	farida->cap_acctCreate(true);
	farida->cap_EmployeeCreate(true);
	farida->unlock();

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

	Database *db = new Database();
	db->insertPerson(adm);
	db->insertPerson(farida);
	db->insertPerson(emp);
	db->insertAccount(acct);
	db->insertPerson(adam);

	Person *p;
	Admin *tmpA;
	Employee *tmpE;
	Customer  *tmpC;

	p = db->retrievePerson("amohamed");
	tmpE = dynamic_cast<Employee*>(p);
	cout << tmpE->isLocked() << endl;
	cout << tmpE->getFirstName() << " " << tmpE->getLastName() << endl;
	cout << tmpE->getCaps()<<endl;
	cout << "Can Create Customers " << tmpE->canCreateCustomer() << endl;

	cout << endl;

	p = db->retrievePerson("kmoussa");
	tmpA = dynamic_cast<Admin*>(p);
	cout << tmpA->isLocked() << endl;
	cout << tmpA->getFirstName() << " " << tmpA->getLastName() << endl;
	cout << tmpA->getCaps()<<endl;
	cout << "Can Create Admins " << tmpA->canCreateAdmin() << endl;

	cout << endl;

	p = db->retrievePerson("amoussa");
	tmpC = dynamic_cast<Customer*>(p);
	cout << tmpC->isLocked() << endl;
	cout << tmpC->getFirstName() << " " << tmpC->getLastName() << endl;
	cout << tmpC->getCaps()<<endl;

	cout << endl;

	p = db->retrievePerson("fmoussa");
	tmpA = dynamic_cast<Admin*>(p);
	cout << dynamic_cast<Admin*>(tmpA)->isLocked() << endl;
	cout << tmpA->getFirstName() << " " << tmpA->getLastName() << endl;
	cout << tmpA->getCaps()<<endl;
	cout << "Can Create Admins " << tmpA->canCreateAdmin() << endl;

	delete s;
	delete tmpA;
	delete tmpE;
	delete tmpC;
	delete db;


	return 0;
}
