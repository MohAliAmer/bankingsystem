/*
 * admin.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */
#include "session.h"

bool Session::createAdmin(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_CREATE))
		return false;
	return false;
}

bool Session::updateAdmin(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_UPDATE))
		return false;
	return false;
}

bool Session::deleteAdmin(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_DELETE))
		return false;
	return false;
}

bool Session::activateAdmin(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_ACTIVATE))
		return false;
	return false;
}

bool Session::deactivateAdmin(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_DEACTIVATE))
		return false;
	return false;
}

bool Session::printAdminInfo(Admin *admin) {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_PRINT_INFO))
		return false;
	return false;
}

bool Session::ListAllAdmins() {
	if (!bIsLoggedIn && !isAuthorized(Session::ADMIN_LIST_ALL))
		return false;
	return false;
}


bool Session::createEmployee(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_CREATE))
		return false;
	return false;
}

bool Session::updateEmployee(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_UPDATE))
		return false;
	return false;
}

bool Session::deleteEmployee(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_DELETE))
		return false;
	return false;
}

bool Session::activateEmployee(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_ACTIVATE))
		return false;
	return false;
}

bool Session::deactivateEmployee(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_DEACTIVATE))
		return false;
	return false;
}

bool Session::printEmployeeInfo(Employee *emp) {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_PRINT_INFO))
		return false;
	return false;
}

bool Session::ListAllEmployees() {
	if (!bIsLoggedIn && !isAuthorized(Session::EMPLOYEE_LIST_ALL))
		return false;
	return false;
}

