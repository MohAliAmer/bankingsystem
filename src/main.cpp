/*
 * main.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */

#include <iostream>
#include "userinterface.h"
#include "session.h"
#include "admin.h"
#include "employee.h"
#include "account.h"
#include "customer.h"
#include "database.h"
#include <typeinfo>

using namespace std;

int main(){

		Ui *interface = new Ui();

	return interface->run();
}

