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


Ui::Ui() : m_session(nullptr), m_execute(nullptr){
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
	cout<< "Bingoooo" << endl;
}

void Ui::ui_update_admin() {
	cout<< "Tangoooo" << endl;
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

void Ui::ui_transfer() {
}

void Ui::ui_transfer_own() {
}

void Ui::ui_deposit() {
}

void Ui::ui_deposit_own() {
}

void Ui::ui_withdraw() {
}

void Ui::ui_print_own_customer() {
}

void Ui::getCallBack(const string desc) {

	if ("Create Administrator" == desc)
		m_execute = std::bind(&Ui::ui_create_admin, this);
	if ("Update Administrator" == desc)
		m_execute = std::bind(&Ui::ui_update_admin, this);
	if ("Delete Administrator" == desc)
		m_execute = std::bind(&Ui::ui_delete_admin, this);
	if ("Activate Administrator" == desc)
		m_execute = std::bind(&Ui::ui_activate_admin, this);
	if ("Deactivate Administrator" == desc)
		m_execute = std::bind(&Ui::ui_deactivate_admin, this);
	if ("Print Administrator Information" == desc)
		m_execute = std::bind(&Ui::ui_print_admin, this);
	if ("List All Administrators" == desc)
		m_execute = std::bind(&Ui::ui_listall_admin, this);

	if ("Create Employee" == desc)
		m_execute = std::bind(&Ui::ui_create_employee, this);
	if ("Update Employee" == desc)
		m_execute = std::bind(&Ui::ui_update_employee, this);
	if ("Delete Employee" == desc)
		m_execute = std::bind(&Ui::ui_delete_employee, this);
	if ("Activate Employee" == desc)
		m_execute = std::bind(&Ui::ui_activate_employee, this);
	if ("Deactivate Employee" == desc)
		m_execute = std::bind(&Ui::ui_deactivate_employee, this);
	if ("Print Employee Information" == desc)
		m_execute = std::bind(&Ui::ui_print_employee, this);
	if ("List All Employees" == desc)
		m_execute = std::bind(&Ui::ui_listall_employee, this);

	if ("Create Account" == desc)
		m_execute = std::bind(&Ui::ui_create_account, this);
	if ("Update Account" == desc)
		m_execute = std::bind(&Ui::ui_update_account, this);
	if ("Delete Account" == desc)
		m_execute = std::bind(&Ui::ui_delete_account, this);
	if ("Activate Account" == desc)
		m_execute = std::bind(&Ui::ui_activate_account, this);
	if ("Deactivate Account" == desc)
		m_execute = std::bind(&Ui::ui_deactivate_account, this);
	if ("Print Account Information" == desc)
		m_execute = std::bind(&Ui::ui_print_account, this);
	if ("List All Accounts" == desc)
		m_execute = std::bind(&Ui::ui_listall_account, this);
	if ("Transfer Money between accounts" == desc)
		m_execute = std::bind(&Ui::ui_transfer, this);
	if ("Deposit Money to Customer" == desc)
		m_execute = std::bind(&Ui::ui_deposit, this);

	if ("Create a new Customer" == desc)
		m_execute = std::bind(&Ui::ui_create_customer, this);
	if ("Update Existing Customer" == desc)
		m_execute = std::bind(&Ui::ui_update_customer, this);
	if ("Delete Customer" == desc)
		m_execute = std::bind(&Ui::ui_delete_customer, this);
	if ("Activate Customer" == desc)
		m_execute = std::bind(&Ui::ui_activate_customer, this);
	if ("Deactivate customer" == desc)
		m_execute = std::bind(&Ui::ui_deactivate_customer, this);
	if ("Print my Customer Information" == desc)
		m_execute = std::bind(&Ui::ui_print_customer, this);
	if ("List All Customers" == desc)
		m_execute = std::bind(&Ui::ui_listall_customer, this);

	if ("Print my customer Information" == desc)
		m_execute = std::bind(&Ui::ui_print_own_customer, this);
	if ("Transfer money to another Account" == desc)
		m_execute = std::bind(&Ui::ui_transfer_own, this);
	if ("Deposit" == desc)
		m_execute = std::bind(&Ui::ui_deposit_own, this);
	if ("Withdraw" == desc)
		m_execute = std::bind(&Ui::ui_withdraw, this);

	if ("Logout" == desc)
		m_execute = std::bind(&Ui::logout, this);

	if ("Exit" == desc) {
		cout << "Bye Bye" <<endl;
		exit(0);
	}

}

void Ui::listWhatToDo() {
	for (map<int, string>::iterator it = m_capMap.begin() ; it != m_capMap.end() ; ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

void Ui::logout() {
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
	m_capabilitiesLabels.push_back("Logout");
	m_capabilitiesLabels.push_back("Exit");

	int counter = 1;
	for (string &capability : m_capabilitiesLabels) {
		m_capMap.insert(pair<int,string>(counter, capability));
		counter++;
	}
	counter = 0;

	cout << endl;

	listWhatToDo();

	cout << endl;
	cout << endl;

	for (;;) {
		int operation = 0;
		map<int, string>::iterator it;
		do {
			cout << "Select Operation: ";
			cin >> operation;
			it = m_capMap.find(operation);
			if (it == m_capMap.end())
				cerr << "Please select a valid operation" << endl;
		} while (it == m_capMap.end());

		getCallBack(m_capMap.find(operation)->second);
		m_execute();
	}

	return 0;
}
