#include "String.h"

String::String(char* s){ //constructeur c-string
	int i=0; 
	this->reserve(25);
	while(s[i]!='\0') { 
		if(i>25) { 
			this->reserve(i);
			tab[i]=s[i];
			i++;
		} 
		else { 
			tab[i]=s[i];
			i++;
		}
	}
	s[i]='\0';
}

//Constructeurs

String::String (String copy){ //constructeur par copie
  self.tab=copy.tab;
  self.length_=copy.length_;
} 

//méthode
int String::length() {  
	int i=0;
	while(this->tab[i]!='\0') { 
		i++
	}
	return i;
}

