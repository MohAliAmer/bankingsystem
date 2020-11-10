/*
 * userinterface.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: amira
 */


#include "userinterface.h"

Ui::Ui() : m_session(nullptr) {
	m_session = new Session();
	if (m_session->firstRun()) {
		// TODO: Run the registration dialog
	}
}

Ui::~Ui() {
}

int Ui::run() {

	return 0;
}
