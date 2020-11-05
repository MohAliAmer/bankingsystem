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
#include <typeinfo>

using namespace std;

int main(){
	Customer *cust = new Customer();
	Account *acct = new Account();
	acct->lock();
	acct->setBalance(10000);
	cust->setAccount(acct);

	Employee *emp = new Employee();
	emp->cap_AcctActivate(true);
	emp->cap_AcctDeactivate(true);
	emp->cap_AcctCreate(true);
	Session *s = new Session();
	s->tmpSetUser(emp);

	s->setSessionCapabilities();
	s->printCapabilities();

	cout << cust->getAccount()->getBalance() << endl;

	return 0;
}
