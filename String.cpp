#include "String.h"

//Constructeurs
String::String(char* s){ //constructeur c-string
	int i=0; 
	this->reserve(25);
	while(s[i]!='\0') { 
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
	s[i]='\0';
}

String::String (String copy){ //constructeur par copie
  self.tab_=copy.tab_;
  self.length_=copy.length_;
}

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

int String::length() {  
	int i=0;
	while(this->tab_[i]!='\0') { 
		i++
	}
	return i;
}


int String::max_Size() { 
	return 5000000;
}

<<<<<<< HEAD
void String::resize(int n) { 
	if(n<this->max_Size()) { 
		if(n<this.length_) { 
			int i=n; 
			while(tab_[i]!="\0") { 
				tab_[i]=nullptr;
				i=i+1;						
			}		
			length_=n;
		} else { 
			length_=n;
		}
	}
}

void String::resize(int n, char c) { 
	int i =this.length;
	if(i>n) { 
		while(tab_[i]!="\0") { 
			tab_[i]=c;
		}
	this.resize(n); 
	}
}
=======
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
>>>>>>> 932e836f68454ed5a6f4c1ad5eabc34eaa75f647
