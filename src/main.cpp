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
	Admin *admin1 = new Admin();
	cout << admin1->canCreateAccount() << endl;
	admin1->cap_AcctCreate(true);
	cout << admin1->canCreateAccount() << endl;
	return 0;
}
