/*
 * main.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */


#include <iostream>
#include "admin.h"
#include "employee.h"
#include "account.h"
#include "customer.h"

using namespace std;

int main(){
	cout << "Starting project" << endl;
	Customer *cust = new Customer();
	Account *acct = new Account();
	acct->lock();
	acct->setBalance(10000);

	cust->setAccount(acct);
	cout << cust->getAccount()->isLocked() << endl;


	return 0;
}
