#include "String.h"

//Constructeurs

String::String (String copy){ //constructeur par copie
  self.tab=copy.tab;
  self.length_=copy.length_;
}
