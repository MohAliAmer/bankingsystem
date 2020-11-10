/*
 * userinterface.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: amira
 */

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <termios.h>
#include <unistd.h>
#endif

#include <string>
#include "userinterface.h"


Ui::Ui() : m_session(nullptr) {
	m_session = new Session();
	showWelcomeScreen();
	if (m_session->firstRun()) {
		registerSuperAdmin();
	}
}

Ui::~Ui() {
	delete m_session;
}

bool Ui::registerSuperAdmin() {

	string username;
	string firstname;
	string lastname;
	string nationalid;
	string password;
	string password_confirm;

	cout << "Registering the bank super administrator" << endl;
	cout << endl;

	Admin *super = new Admin();
	super->setId(m_session->genUserId());
	cout << "User name: ";
	cin >> username;
	cout <<  endl;
	cout << "First name: ";
	cin >> firstname;
	cout <<  endl;
	cout << "last name: ";
	cin >> lastname;
	cout <<  endl;
	cout << "National ID: ";
	cin >> nationalid;
	cout <<  endl;

	do {
		cout << "Password: ";
		cin >> password;
		cout <<  endl;
		cout << "Confirm password: ";
		cin >> password_confirm;
		if (password != password_confirm)
			cerr << "Password mismatch, Please try again" << endl;
	}
	while (password != password_confirm);

	super->setUserName(username);
	super->setFirstName(firstname);
	super->setLastName(lastname);
	super->setNationalId(nationalid);
	super->setPassword(m_session->encrypt(password));
	super->unlock();
	super->cap_AdminCreate(true);
	super->cap_AdminUpdate(true);
	super->cap_AdminDelete(true);
	super->cap_AdminActivate(true);
	super->cap_AdminDeactivate(true);
	super->cap_AdminListAll(true);
	super->cap_AdminPrintInfo(true);

	if(!m_session->createAdmin(super)) {
		cerr << "Error creating super administrator please contact the system developer" << endl;
		exit(-1);
	}
	else {
		cout << "Bank super administrator created successfully, please login to setup more users" << endl;
		delete super;
		run();
	}

	return false;
}

void Ui::showWelcomeScreen() {
	cout << "<<<<<<<<<<<<<<< Welcome To Future Bank >>>>>>>>>>>>>>>>" << endl;
}

void Ui::ui_create_admin() {
	cout << "Bingooooooooooooooo" << endl;
}

void Ui::ui_update_admin() {
}

void Ui::ui_delete_admin() {
}

void Ui::ui_activate_admin() {
}

void Ui::ui_deactivate_admin() {
}

void Ui::ui_print_admin() {
}

void Ui::ui_listall_admin() {
}

void Ui::ui_create_employee() {
}

void Ui::ui_update_employee() {
}

void Ui::ui_delete_employee() {
}

void Ui::ui_activate_employee() {
}

void Ui::ui_deactivate_employee() {
}

void Ui::ui_print_employee() {
}

void Ui::ui_listall_employee() {
}

void Ui::ui_create_customer() {
}

void Ui::ui_update_customer() {
}

void Ui::ui_delete_customer() {
}

void Ui::ui_activate_customer() {
}

void Ui::ui_deactivate_customer() {
}

void Ui::ui_print_customer() {
}

void Ui::ui_listall_customer() {
}

void Ui::ui_create_account() {
}

void Ui::ui_update_account() {
}

void Ui::ui_delete_account() {
}

void Ui::ui_activate_account() {
}

void Ui::ui_deactivate_account() {
}

void Ui::ui_print_account() {
}

void Ui::ui_listall_account() {
}

int Ui::run() {

	string username, password;
	cout << "User: ";
	cin >> username;
	cout << "Password: ";

#if 0
#ifdef __linux__
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getline(cin, password);
    tcgetattr(STDIN_FILENO, &oldt);
#elif _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    getline(cin, password);
#endif
#endif

    cin >> password; // TODO: should be replaced with non echoed password input

	bool loggedIn = m_session->login(username, password);
	if (!loggedIn) {
		cerr << "Login Failed" << endl;
		run();
	}

	m_capabilitiesLabels = m_session->getSessionCapabilities();

	for (string &cap : m_capabilitiesLabels) cout << cap << endl;

	m_function = std::bind(&Ui::ui_create_admin, this);

	m_function();

	return 0;
}
