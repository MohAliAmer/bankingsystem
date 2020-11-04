/*
 * admin.h
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */

#ifndef SRC_ADMIN_H_
#define SRC_ADMIN_H_

#include "employee.h"

class Admin : public Employee {
private:

	bool bAdminCreate;
	bool bAdminUpdate;
	bool bAdminDelete;
	bool bAdminListAll;


public:
	Admin() : bAdminCreate(false),bAdminUpdate(false), bAdminDelete(false), bAdminListAll(false)  {
		Employee::cap_AcctActivate(true);
		Employee::cap_AcctCreate(true);
		Employee::cap_AcctDeactivate(true);
		Employee::cap_AcctDelete(true);
		Employee::cap_AcctListAll(true);
		Employee::cap_AcctPrintInfo(true);
		Employee::cap_AcctUpdate(true);
		Employee::cap_custCreate(true);
		Employee::cap_custDelete(true);
		Employee::cap_custUpdate(true);
		Employee::lock();
	}
	~Admin();
	void cap_AdminCreate(bool value) {bAdminCreate = value;}
	void cap_AdminUpdate(bool value) {bAdminCreate = value;}
	void cap_AdminDelete(bool value) {bAdminCreate = value;}
	void cap_AdminListAll(bool value) {bAdminCreate = value;}

	bool canCreateAdmin() {return bAdminCreate;}
	bool canUpdateAdmin() {return bAdminCreate;}
	bool canDeleteAdmin() {return bAdminCreate;}
	bool canListAllAdmin() {return bAdminCreate;}

	bool createAdmin(Admin *admin);
	bool updateAdmin(Admin *admin);
	bool deleteAdmin(Admin *admin);

	void printAllAdmins();

};




#endif /* SRC_ADMIN_H_ */
