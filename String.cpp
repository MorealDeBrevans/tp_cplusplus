#include "String.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

//Constructeurs
String::String(const char* s){ //constructeur c-string
	int i=0;
	int memory=25;
	//this->reserve(memory);
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

const char* String::c_str() const{
  return tab_;
}

long String::max_size() { 
	return max_size_;
}
//Modificateurs
void String::reserve(unsigned long n) {
	std::cout<<"tableau temp\n";
	char* temp = new char[n];
	int i;
	std::cout<<"recopie\n";
	for(i=0;i<n-1;i++) temp[i]=tab_[i];
	std::cout<<"supression\n";
	delete[] tab_;
	std::cout <<"reassignation\n";
	tab_=temp;
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
	int i =this->length_;
	if(i>n) { 
		while(tab_[i]!='\0') { 
			tab_[i]=c;
		}
		tab_[i]='\0';
	}
	this->resize(n); 
}


//Opérateurs
String& String::operator=(const char* s) {
	std::cout << "suppression tab\n";
	delete[] tab_;
	unsigned long memory=25;
	std::cout << "reallocation\n";
	tab_=new char[memory];
	std::cout<<"succes realloc\n";
	//this->reserve(memory);
	int i;
	for(i=0;s[i]!='\0';i++) {
	    if(i==capacity_) {
	    	std::cout<<"agrandissement\n";
	    	memory=2*memory;
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


//Opérateurs
void String::operator=(char* s2) {
	String s(s2);
	this = &s;

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
<<<<<<< HEAD
String::~String() { }
>>>>>>> 932e836f68454ed5a6f4c1ad5eabc34eaa75f647
=======
String::~String() {
    delete[] tab_;
}
>>>>>>> theophile


