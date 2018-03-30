#include "String.h"

//Constructeurs

//Accesseurs
unsigned long String::capacity() {
	return capacity_;
}

//Modificateurs
void String::reserve(int n) {
	this->tab_=realloc(this->tab_, n*sizeof(char));
	this->capacity_=n;
}

//Méthodes
bool String::empty() {
	if (this->length_==0) return true;
	else return false;
}

//Opérateurs
void String::operator=(char* s2) {
	String s(s2);
	this = &s;
}

friend String operator+(String s1, String s2) {
	String s = s1+s2.c_str());
	return s;
}

//Suppresseur
String::~String() { }
