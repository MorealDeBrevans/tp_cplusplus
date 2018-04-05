#include "String.h"
#include <string.h>
#include<cstdlib>

//Constructeurs
String::String(const char* s){ //constructeur c-string
	int i=0;
	int memory=25;
	this->reserve(memory);
	while(s[i]!='\0') {
        if(i<max_size_) {
            if(i>memory) {
            		memory=2*memory;
                this->reserve(memory);
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
  this->reserve(model.capacity_);
  for(int i=0;i<model.length_;i++) {
    this->tab_[i]=model.tab_[i];
  }
  this->length_=model.length_;
}

//Accesseurs
unsigned long String::capacity() {
	return capacity_;
}

int String::length() {
	return length_;
}

const char* String::c_str() const{
  return tab_;
}

long String::max_size() { 
	return max_size_;
}
//Modificateurs
void String::reserve(int n) {
	this->tab_=(char*) realloc(this->tab_, n*sizeof(char));
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
    delete this;
	this->reserve(25);
	int i;
	for(i=0;s[i]!='\0';i++) {
        if(i<max_size_) {
            if(i>25) {
                this->reserve(i);
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
	return *this;
}


//Opérateurs
void String::operator=(char* s2) {
	String s(s2);
	this = &s;

String& String::operator=(String s) {
    delete this;
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
    free(tab_);
}
>>>>>>> theophile


