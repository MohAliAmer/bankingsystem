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
#include <csignal>

using namespace std;


void signalHandler( int signum ) {
   exit(signum);
}

int main(){

	std::signal(SIGINT, signalHandler);
	Ui *interface = new Ui();

	return interface->run();
}

