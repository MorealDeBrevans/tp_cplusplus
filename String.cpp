#include "String.h"
	
String::~String() { }

int String::capacity() {
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
friend void swap(String& s1, String& s2) {
	using std::swap;
	swap(s1.length_, s2.length);
	swap(s1.tab_, s2.tab_);
	swap(s1.capacity_, s2.capacity_);
}

void String::operator=(char* s2) {
	String s(s2);
	this = &s;
}

friend String operator+(String s1, String s2) {
	String s = s1+s2.c_str());
	return s;
}

