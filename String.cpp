#include "String.h"

String::String(char* s){ 
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

