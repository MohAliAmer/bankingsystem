/*
 * customer.h
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */

#ifndef SRC_CUSTOMER_H_
#define SRC_CUSTOMER_H_

#include "person.h"
#include "account.h"


class Customer : public Person{

private:
	Account *m_account;
	void setAccount(Account *acct) {m_account = acct;}

public:

	Customer() : m_account(nullptr) {}
	virtual ~Customer() = default;
	void lock() {Person::bLocked = true;}
	void unlock() {Person::bLocked = false;}
	bool isLocked(){return Person::bLocked;}
	bool deposite(const int sum);

	Account* getAccount() {return this->m_account;}
	void tmpSetAccount(Account *acct) {setAccount(acct);} // TODO: remove me after

};

#endif /* SRC_CUSTOMER_H_ */


