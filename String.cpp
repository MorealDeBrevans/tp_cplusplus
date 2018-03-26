#include "String.h"
	
String::~String() { }

size_t String::capacity() {
	return capacity_;
}

bool String::empty() {
	if (this->length_==0) return true;
	else return false;
}

void String::reserve(size_t n) {
	this->tab_=realloc(this->tab_, n*sizeof(char));
	this->capacity_=n;
}

friend operator=(String s1, char* s2) {
	String s1(s2);
	
	return s1;
}

friend operator+(String s1, String s2) {
	
