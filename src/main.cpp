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
	//Account *acct = new Account();
	Session *s = new Session();


#if 0
	Database *db = new Database();

	Admin *adm = new Admin();
	adm->setId(13);
	adm->setUserName("kmoussa");
	adm->setFirstName("Khaled");
	adm->setLastName("Moussa");
	adm->setNationalId("45455767878");
	adm->setPassword(s->encrypt("abc123"));
	adm->cap_AdminPrintInfo(true);
	adm->cap_AdminActivate(true);
	adm->cap_AdminDeactivate(true);
	adm->cap_AdminDelete(true);
	adm->cap_AdminCreate(true);
	adm->cap_AdminUpdate(true);
	adm->unlock();

	db->insertPerson(adm);

#endif
/*
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
	farida->cap_custCreate(false);
	farida->cap_custDelete(true);
	farida->cap_acctCreate(true);
	farida->cap_EmployeeCreate(true);
	farida->lock();

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
	adam->unlock();
	adam->setId(3);
	adam->setUserName("amoussa");
	adam->setFirstName("Adam");
	adam->setLastName("Moussa");
	adam->setNationalId("1212121");
	adam->setPassword(s->encrypt("mypassword"));
	adam->setAccount(acct);


	Customer *rokaia = new Customer();
	rokaia->unlock();
	rokaia->setId(4);
	rokaia->setUserName("rmoussa");
	rokaia->setFirstName("Rokaia");
	rokaia->setLastName("Moussa");
	rokaia->setNationalId("222233333444");
	rokaia->setPassword(s->encrypt("testpass"));
	Account *rokaiaaccount = new Account();
	rokaiaaccount->setId(123);
	rokaiaaccount->setBalance(0);
	rokaiaaccount->setCustomerId(rokaia->getId());
	rokaiaaccount->unlock();
	rokaia->setAccount(rokaiaaccount);

	acct->setId(122);
	acct->unlock();
	acct->setBalance(10000);
	acct->setCustomerId(adam->getId());


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
	farida->cap_custCreate(false);
	farida->cap_custDelete(true);
	farida->cap_acctCreate(true);
	farida->cap_EmployeeCreate(true);
	farida->unlock();
*/


	s->login("kmoussa", "abc123");
	if (s->isLoggedIn()) {
		cout << "Login successfull" << endl;
#if 1
		//s->deleteAdmin(farida);
		//bool (Session::*f)(Admin *admin) = &Session::createAdmin;
		//(s->*f)(farida);
		//(s->*s->Session::execute)(farida);

#endif
	}
	else
		cerr << "Failed attempt to login" << endl;

	return 0;
}

