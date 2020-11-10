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

	bool loggedIn = m_session->login("kmoussa", "abc123");  // FIXME: use cin to get credentials
	if (!loggedIn) {
		cerr << "Login Failed" << endl;
		run();
	}

	m_capabilitiesLabels = m_session->getSessionCapabilities();

	for (vector<string>::iterator it = m_capabilitiesLabels.begin() ; it != m_capabilitiesLabels.end() ; ++it){
		cout << *it << endl;
	}

	return 0;
}
