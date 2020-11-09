/*
 * admin.cpp

 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */
#include <assert.h>
#include <typeinfo>
#include "session.h"

bool Session::createAdmin(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_CREATE))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin || m_db->retrievePerson(admin->getUserName()))
			return false;

	if (!m_db->insertPerson(admin))
		return false;
	else
		return true;

	return false;
}

bool Session::updateAdmin(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_UPDATE))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin)
		return false;
	else {
		Admin *tmp = dynamic_cast<Admin*>(m_db->retrievePerson(admin->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->insertPerson(admin))
		return false;
	else
		return true;

	return false;

}

bool Session::deleteAdmin(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_DELETE))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin)
		return false;
	else {
		Admin *tmp = dynamic_cast<Admin*>(m_db->retrievePerson(admin->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->deletePerson(admin))
		return false;
	else
		return true;

	return false;

}

bool Session::deactivateAdmin(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_DEACTIVATE))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin || !m_db->retrievePerson(admin->getUserName()))
		return false;

	admin->lock();

	if (!m_db->insertPerson(admin))
		return false;
	else
		return true;

	return false;
}

bool Session::activateAdmin(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_ACTIVATE))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin || !m_db->retrievePerson(admin->getUserName()))
		return false;

	admin->unlock();

	if (!m_db->insertPerson(admin))
		return false;
	else
		return true;

	return false;

}

bool Session::printAdminInfo(Admin *admin) {
	if (!isAuthorized(Session::ADMIN_PRINT_INFO))
		return false;

	assert(typeid(*admin) == typeid(Admin));

	if (!admin || !m_db->retrievePerson(admin->getUserName()))
		return false;

	// TODO: Implement admin print info here

	return true;
}

bool Session::ListAllAdmins() {
	if (!isAuthorized(Session::ADMIN_LIST_ALL))
		return false;
	return false;
}

bool Session::createEmployee(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_CREATE))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp || m_db->retrievePerson(emp->getUserName()))
		return false;

	if (!m_db->insertPerson(emp))
		return false;
	else
		return true;

	return false;

}

bool Session::updateEmployee(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_UPDATE))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp)
		return false;
	else {
		Employee *tmp = dynamic_cast<Employee*>(m_db->retrievePerson(emp->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->insertPerson(emp))
		return false;
	else
		return true;

	return false;
}

bool Session::deleteEmployee(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_DELETE))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp)
		return false;
	else {
		Employee *tmp = dynamic_cast<Employee*>(m_db->retrievePerson(emp->getUserName()));
		if (!tmp)
			return false;
	}

	if (!m_db->deletePerson(emp))
		return false;
	else
		return true;

	return false;
}

bool Session::activateEmployee(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_ACTIVATE))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp || !m_db->retrievePerson(emp->getUserName()))
		return false;

	emp->unlock();

	if (!m_db->insertPerson(emp))
		return false;
	else
		return true;

	return false;
}

bool Session::deactivateEmployee(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_DEACTIVATE))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp || !m_db->retrievePerson(emp->getUserName()))
		return false;

	emp->lock();

	if (!m_db->insertPerson(emp))
		return false;
	else
		return true;

	return false;
}

bool Session::printEmployeeInfo(Employee *emp) {
	if (!isAuthorized(Session::EMPLOYEE_PRINT_INFO))
		return false;

	assert(typeid(*emp) == typeid(Employee));

	if (!emp || !m_db->retrievePerson(emp->getUserName()))
		return false;

	return true;
}

bool Session::ListAllEmployees() {
	if (!isAuthorized(Session::EMPLOYEE_LIST_ALL))
		return false;
	return false;
}

