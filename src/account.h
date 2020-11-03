/*
 * account.h
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_


class Account{

private:
	bool bLocked;
	long m_balance;


public:
	Account() : bLocked(true), m_balance(0) {}
	~Account();
	void lock(){bLocked = true;}
	void operator = (const Account &acct) {
		this->bLocked = acct.bLocked;
		this->m_balance = acct.m_balance;
	}
	void unlock(){bLocked = false;}
	double getBalance() {return m_balance;}
	void setBalance(double newBalance) {m_balance = newBalance;}

};


#endif /* SRC_ACCOUNT_H_ */
