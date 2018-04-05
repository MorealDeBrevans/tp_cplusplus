#include "String.h"
#include <iostream>

int main() {
	String s("A character sequence");

	std::cout << s.c_str() << std::endl;
	return 0;

}
