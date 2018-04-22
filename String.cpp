#include "String.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

//Constructeurs
String::String(const char* s){ //constructeur c-string
	int i=0;
	int memory=25;
	//this->reserve(memory);
	capacity_=memory;
	tab_=new char[memory];
	while(s[i]!='\0') {
        if(i<max_size_) {
            if(i>memory) {
            	memory=2*memory;
                this->reserve(memory);
			}
            tab_[i]=s[i];
            i++;
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

unsigned long String::size(){
  return length_;
}

const char* String::c_str() const{
  return tab_;
}

long String::max_size() {
	return max_size_;
}
//Modificateurs
void String::reserve(unsigned long n) {
	char* temp = new char[n];
	int i;
	for(i=0;i<n;i++) temp[i]=tab_[i];
	delete[] this->tab_;
	this->tab_=temp;
	this->capacity_=n;
}


//Méthodes
bool String::empty() {
	if (length_==0) return true;
	else return false;
}

void String::resize(int n) {
	int i = n+1;
	if(n<this->max_size_) {
		if(n>this->capacity_) {
			this->reserve(this->capacity_*2);
			if(n>this->length_) {
				while(this->tab_[i]!='\0') {
					this->tab_[i]=' ';
					i=i+1;
				}
				tab_[i]='\0';
			}
			this->length_=n;

		} else {
			this->reserve(n);
		}
	}
}

void String::resize(int n, char c) {
	int tailleinit = this->length_;
	int i=tailleinit;
	this->resize(n);
	if(n>tailleinit) {
		while(i<=n) {
			tab_[i]=c;
			i++;
		}
		this->length_=n;
		tab_[i]='\0';
	}
}

void String::clear(){
  this->resize(1);
  this->tab_[0] = '\0';
}

//Opérateurs
String& String::operator=(const char* s) {
	delete[] this->tab_;
	unsigned long memory=25;

	tab_=new char[memory];
	capacity_=25;
	int i;
	for(i=0;s[i]!='\0';i++) {
		if(i>memory) {
			memory=2*memory;
	    	if(memory<max_size_) this->reserve(memory);
	    }
	    tab_[i]=s[i];
	}
	tab_[i]='\0';
	length_=i;
	return *this;
}

String& String::operator=(String s) {
    *this = s.c_str();
    return *this;
}

String operator+(String s1, const char* s2) {
    int i;
    for(i=0;s2[i]!=0;i++) {}
    char* cat=new char[s1.length()+i];

    strcpy(cat,s1.c_str());
    strcat(cat,s2);
    String s(cat);
    delete[] cat;
    return s;
}

String operator+(String s1, String s2) {
	String s("");
	s=s1+s2.c_str();
	return s;
}

String& String::operator=(const char c) {
	this->reserve(1);
	tab_[0]=c;
	this->length_=1;
	return *this;
}

String operator+(const char * c, String s1) {
	int i;
	for(i=0;c[i]!=0;i++) {}
	char* cat=new char[s1.length()+i];

	strcpy(cat, c);
	strcat(cat, s1.c_str());
	String s(cat);
	delete[] cat;
	return s;
}

//Suppresseur
String::~String() {
    delete[] tab_;
}
