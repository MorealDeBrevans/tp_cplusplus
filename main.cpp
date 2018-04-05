#include "String.h"
#include <iostream>

int main() {
	String s("A character sequence which has a oihnregohneqogteqhzh inhatgr                     ii i iiiii");

	std::cout << s.c_str() << std::endl;
	printf("%d \n",s.length()); 
	printf("%d \n",s.max_size()); 
	
	s.resize(100);
	printf("%d \n",s.length()); 
	s.resize(100,'f');
	std::cout << s.c_str() << std::endl;
	s.resize(20); 
	std::cout << s.c_str() << std::endl;
	return 0;
	
}
