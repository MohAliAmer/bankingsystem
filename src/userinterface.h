/*
 * userinterface.h
 *
 *  Created on: Nov 10, 2020
 *      Author: amira
 */

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

#include <string>
#include "session.h"
#include "person.h"
#include "customer.h"
#include "employee.h"
#include "admin.h"



class Ui {
	
private:
	Session *m_session;
	
public:
	Ui() ;
	~Ui();
};



#endif /* SRC_USERINTERFACE_H_ */
