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
	bool bAdminPrintInfo;
	bool bAdminActivate;
	bool bAdminDeactivate;


public:
	Admin() : bAdminCreate(false),bAdminUpdate(false),
				bAdminDelete(false), bAdminListAll(false),
				bAdminPrintInfo(false),bAdminActivate(false),
				bAdminDeactivate(false) {
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
	virtual ~Admin() = default;
	void cap_AdminCreate(bool value)    {bAdminCreate = value;}
	void cap_AdminUpdate(bool value)    {bAdminUpdate = value;}
	void cap_AdminDelete(bool value)    {bAdminDelete = value;}
	void cap_AdminListAll(bool value)   {bAdminListAll = value;}
	void cap_AdminPrintInfo(bool value) {bAdminPrintInfo = value;}
	void cap_AdminActivate(bool value)  {bAdminActivate = value;}
	void cap_AdminDeactivate(bool value){bAdminDeactivate = value;}

	bool canCreateAdmin()    {return bAdminCreate;}
	bool canUpdateAdmin()    {return bAdminUpdate;}
	bool canDeleteAdmin()    {return bAdminDelete;}
	bool canActivateAdmin()  {return bAdminActivate;}
	bool canDeactivateAdmin(){return bAdminDeactivate;}
	bool canListAllAdmin()   {return bAdminListAll;}
	bool canPrintAdminInfo() {return bAdminPrintInfo;}

	bool createAdmin(Admin *admin);
	bool updateAdmin(Admin *admin);
	bool deleteAdmin(Admin *admin);
	bool createEmployee(Employee *emp);
	bool updateEmployee(Employee *emp);
	bool deleteEmployee(Employee *emp);
	void printEmployeeInfo(Employee *emp);
	void printAdminInfo(Admin *admin);

	void printAllAdmins();

};




#endif /* SRC_ADMIN_H_ */
