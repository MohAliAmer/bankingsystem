/*
 * employee.h
 *
 *  Created on: Nov 3, 2020
 *      Author: khaled
 */

#ifndef SRC_EMPLOYEE_H_
#define SRC_EMPLOYEE_H_

#include <string>
#include "person.h"
#include "customer.h"
#include "account.h"



class Employee : public Person {

private:
	bool bLocked;
	bool bAcctCreate;
	bool bAcctUpdate;
	bool bAcctDelete;
	bool bAcctDeactivate;
	bool bAcctActivate;
	bool bAcctListAll;
	bool bAcctPrintInfo;

	bool bCustCreate;
	bool bCustUpdate;
	bool bCustDelete;
	bool bPrintCustInfo;

public:
	Employee() : bLocked(true), bAcctCreate(false),bAcctUpdate(false),
				bAcctDelete(false), bAcctDeactivate(false), bAcctActivate(false),
				bAcctListAll(false),bAcctPrintInfo(false),bCustCreate(false),
				bCustUpdate(false),bCustDelete(false), bPrintCustInfo(false) {}
	~Employee();

	void cap_AcctCreate(bool value) {bAcctCreate = value;}
	void cap_AcctUpdate(bool value) {bAcctUpdate = value;}
	void cap_AcctDelete(bool value) {bAcctDelete = value;}
	void cap_AcctDeactivate(bool value) {bAcctDeactivate = value;}
	void cap_AcctActivate(bool value) {bAcctActivate = value;}
	void cap_AcctListAll(bool value) {bAcctListAll = value;}
	void cap_AcctPrintInfo(bool value) {bPrintCustInfo = value;}
	void cap_custCreate(bool value) {bCustCreate = value;}
	void cap_custUpdate(bool value) {bCustUpdate = value;}
	void cap_custDelete(bool value) {bCustDelete = value;}
	void lock() {bLocked = true;}
	void unlock() {bLocked = false;}

	bool canCreateAccount() {return bAcctCreate;}
	bool canUpdateAccount() {return bAcctUpdate;}
	bool canDeleteAccount() {return bAcctDelete;}
	bool canDeactivateAccount() {return bAcctDeactivate;}
	bool canActivateAccount() {return bAcctActivate;}
	bool canListAllAccounts() {return bAcctCreate;}
	bool canPrintCustomerInfo() {return bAcctCreate;}
	bool isLocked() {return bLocked;}

	bool createAccount(Account *acct);
	bool deleteAccount(Account *acct);
	bool updateAccount(Account *acct);
	bool deactivateAccount(Account *acct);
	bool activateAccount(Account *acct);
	bool createCustomer(Customer *customer);
	bool updateCustomer(Customer *customer);
	bool deleteCustomer(Customer *customer);

	void printCustInfo(Customer *cust);


};



#endif /* SRC_EMPLOYEE_H_ */
