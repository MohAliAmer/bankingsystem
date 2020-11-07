#include <iostream>
#include "Person.h"


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Person p;
	p.setFirstName("Ahmed");
	p.setLastName(" Zaher");
	p.setId("a12345");
	p.setNationalID(17051997);
	p.setPassword("1234567890");

	p.printAllF();
	
	
	return 0;
}
