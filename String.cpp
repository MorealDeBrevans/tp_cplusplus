#include "String.h"

String::String(char* s){ 
	int i=0;
	while(s[i]!="\o") { 
		tab[i]=s[i];
		i++;
	}
	s[i]="\o";
}
