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
#include <sstream>
#include "openssl/sha.h"

using namespace std;

string encrypt(string word) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, word.c_str(), word.length());
    SHA256_Final(hash, &sha256);
    string result = string();
    stringstream sstream;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    	sstream << hex << (int) hash[i];
    	result = sstream.str();
    }
    return result;
}


int main(){
	cout << "Starting project" << endl;
	Customer *cust = new Customer();
	Account *acct = new Account();
	acct->lock();
	acct->setBalance(10000);

	cust->setAccount(acct);
	cout << cust->getAccount()->isLocked() << endl;
	cust->getAccount()->setBalance(15000);
	cout << cust->getAccount()->getBalance() << endl;
	cout << encrypt("hello, world") << endl;
	return 0;
}
