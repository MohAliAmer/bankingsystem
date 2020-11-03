/*
 * employee.h
 *
 *  Created on: Oct 19, 2020
 *      Author: amira
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <string>

using namespace std;

class Person{

private:
	int m_id;
	string m_firstName;
	string m_lastName;
	string m_nationalId;
	string m_password;

public:
	Person():m_id(0),m_firstName(""), m_lastName(""), m_nationalId(""), m_password("") {}
	Person(int personId, string fname, string lname, string pass, string natid) {
		m_id = personId;
		m_firstName = fname;
		m_lastName = lname;
		m_nationalId = natid;
		m_password = pass;
	}

	virtual ~Person();

	void setFirstName(string name) {
		m_firstName = name;
	}
	void setLastName(string name) {
		m_lastName = name;
	}
	void setId(int id) {
		m_id = id;
	}
	void setNationalId(string natid) {
		m_nationalId = natid;
	}
	void setPassword(string pass) {
		m_password = pass;
	}

	int getId(){return m_id;}
	string getFirstName(){return m_firstName;}
	string getLastName(){return m_lastName;}
	string getNationalId(){return m_nationalId;}
	string getPassword(){return m_password;}


};


#endif /* SRC_PERSON_H_ */
