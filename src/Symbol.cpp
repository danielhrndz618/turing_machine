#include "./../include/Symbol.h"


Symbol::Symbol(char s, char w, int c){
  this->symbol = s;
  this->write_symbol = w;
  this->command = c;
}

Symbol::Symbol(char s){
  this->symbol = s;
}




