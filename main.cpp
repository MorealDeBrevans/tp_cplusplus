#include "String.h"
#include <iostream>

int main() {
	//Test constructeur
	String s("A character sequence longer than twenty-five char");
	std::cout << s.c_str() << std::endl;	
	
	//Par copie
	String s2(s);
	std::cout << s2.c_str() << std::endl;
	
	//Accesseurs
	std::cout << "Longueur : " << s2.length() << std::endl;
	std::cout << "Capacité: " << s2.capacity() << std::endl;
	
	
	//Methodes
	std::cout << "vide : " << s2.empty() << std::endl;
	String s3("");
	std::cout << "vide : " << s3.empty() << std::endl;
	s2.resize(60,'f');
	std::cout << s2.c_str() << std::endl;
	
	//Opérateurs d'assignation
	String s4="Le gros chat";
	std::cout << "Longueur : " << s4.length() << std::endl;
	std::cout << "Capacité: " << s4.capacity() << std::endl;
	std::cout << s4.c_str() << std::endl;
	
	s2= "Bien le bonjour madame qui fait plus de vingt cinq char";
	
	std::cout << "Longueur : " << s2.length() << std::endl;
	std::cout << "Capacité: " << s2.capacity() << std::endl;
	std::cout << s2.c_str() << std::endl;
	
	s4=s2;
	std::cout << "Longueur : " << s4.length() << std::endl;
	std::cout << "Capacité: " << s4.capacity() << std::endl;
	std::cout << s4.c_str() << std::endl; 
	
	s4='f';
	std::cout << "Longueur : " << s4.length() << std::endl;
	std::cout << "Capacité: " << s4.capacity() << std::endl;
	std::cout << s4.c_str() << std::endl; 
	
	//Opérateurs plus
	
	s=*(new String("lol"))+"deuxieme morceau";
	std::cout << "Longueur : " << s.length() << std::endl;
	std::cout << "Capacité: " << s.capacity() << std::endl;
	std::cout << s.c_str() << std::endl;
	printf("%d \n",s.length()); 
	printf("%d \n",s.max_size()); 
	
	s=s+s4;
	std::cout << "Longueur : " << s.length() << std::endl;
	std::cout << "Capacité: " << s.capacity() << std::endl;
	std::cout << s.c_str() << std::endl;
	s.resize(20); 
	std::cout << s.c_str() << std::endl; 
	
	s="bla";
	std::cout << "Longueur : " << s.length() << std::endl;
	std::cout << "Capacité: " << s.capacity() << std::endl;
	std::cout << s.c_str() << std::endl;
	
	s4="Le gros chat";
	s="bla"+s4;
	std::cout << "Longueur : " << s.length() << std::endl;
	std::cout << "Capacité: " << s.capacity() << std::endl;
	std::cout << s.c_str() << std::endl;
	
}
