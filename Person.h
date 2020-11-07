#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string firstName;
	string lastName;
	string id;
	int nationalID;
	string password;
public:
	Person(){
	firstName = " ";
	lastName = " ";
	id = " ";
	nationalID= 0;
	password = " ";
	}
	
	Person(string fn,string ln,string id,int nID,string p){
	firstName = fn;
	lastName = ln;
	this->id = id;
	nationalID= nID;
	password = p;
	}
	
	void setFirstName(string n){
		firstName = n;
	}
	string getFirstName(){
		return firstName;
	}
	
	void setLastName(string l){
		lastName = l;
	}
	string getLastName(){
		return lastName;
	}
	
	void setId(string id){
		this->id = id;
	}
	string getId(){
		return id;
	}
	
	void setNationalID(int ni){
	nationalID = ni;
	}
	int getNationalID(){
		return nationalID;
	}
	
	void setPassword(string p){
		password = p;
	}
	string getPassword(){
		return password;
	}
	
	void printAllF(){
		cout<<"first name : "<<firstName<<endl;
		cout<<"last name : "<<lastName<<endl;
		cout<<"ID : "<<id<<endl;
		cout<<"National ID : "<<nationalID<<endl;
		cout<<"password : "<<password<<endl;
		
	}
	
};

#endif
