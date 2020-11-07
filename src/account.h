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
	int m_id;
	long m_balance;


public:
	Account() : bLocked(true), m_id(0), m_balance(0) {}
	virtual ~Account() = default;
	void lock(){bLocked = true;}
	void unlock(){bLocked = false;}
	bool isLocked() {return bLocked;}
	Account* operator = (const Account &acct) {
		this->bLocked = acct.bLocked;
		this->m_balance = acct.m_balance;
		return this;
	}
	void setId(const int id) {m_id = id;}
	int getId() {return m_id;}
	double getBalance() {return m_balance;}
	void setBalance(double newBalance) {m_balance = newBalance;}


};


#endif /* SRC_ACCOUNT_H_ */
