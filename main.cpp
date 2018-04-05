#include "String.h"
#include <iostream>

int main() {
	String s("A character sequence which has a oihnregohneqogteqhzh inhatgr                     ii i iiiii");

	std::cout << s.c_str() << std::endl;
	printf("%d \n",s.length()); 
	printf("%d \n",s.max_size()); 
	return 0;
	
}
