#include "String.h"
	
String::~String() { }

<<<<<<< HEAD
size_t String::capacity() {
	return capacity_;
}

bool String::empty() {
	if (this->length_==0) return true;
	else return false;
}

void String::reserve(int n) {
	this->tab_=realloc(this->tab_, n*sizeof(char));
	this->capacity_=n;
}

friend String operator=(String s1, char* s2) {
	String s1(s2);
	
	return s1;
}

#friend String operator+(String s1, String s2) {

