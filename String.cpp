#include "String.h"
#include <string.h>
#include<cstdlib>
#include <iostream>

//Constructeurs
String::String(const char* s){ //constructeur c-string
	int i=0;
	length_=0;
	//this->reserve(25);
	this->tab_=new char[25];
	while(s[i]!='\0') {
        if(i<max_size_) {
            if(i>25) {
                this->reserve(i+1);
                tab_[i]=s[i];
                i++;
            }
            else {
                tab_[i]=s[i];
                i++;
            }
        }
	}
	tab_[i]='\0';
	length_=i;
}

String::String (const String& model){ //constructeur par copie
  this->capacity_=model.capacity_;
  this->tab_=new char[capacity_];
  for(int i=0;i<model.length_;i++) {
    this->tab_[i]=model.tab_[i];
  }
  this->length_=model.length_;
}

//Accesseurs
unsigned long String::capacity() {
	return capacity_;
}

unsigned long String::length() {
	return length_;
}

const char* String::c_str() const{
    return tab_;
}

//Modificateurs
void String::reserve(unsigned long n) {
	char* temp = new char[n];
	int i;
	for(i=0;i<n;i++) temp[i]=tab_[i];
	delete[] tab_;
	tab_=temp;
	this->capacity_=n;
}

//Méthodes
bool String::empty() {
	if (length_==0) return true;
	else return false;
}

//Opérateurs
String& String::operator=(const char* s) {
	unsigned long memory=25;
	this->reserve(memory);
	int i;
	for(i=0;s[i]!='\0';i++) {
	    if(i==capacity_) {
	    	memory=memory*2;
        	this->reserve(memory);
        }
        if(i<max_size_) {
           tab_[i]=s[i];
           i++;
        }
	}
	tab_[i]='\0';
	length_=i;
	return *this;
}

String& String::operator=(String s) {
    *this = s.c_str();
    return *this;
}

String operator+(String s1, char* s2) {
    int i;
    for(i=0;s2[i]!=0;i++) {}
    char cat[s1.length()+i];
    //char* cat=(char*) malloc((s1.length()+i));
    strcpy(cat,s1.c_str());
    strcat(cat,s2);
    String* s = new String(cat);
    free(cat);
    return *s;
}

String operator+(String s1, String s2) {
	String s = s1+s2.c_str();
	return s;
}

//Suppresseur
String::~String() {
    delete[] tab_;
}
