#include "./../include/Symbol.h"


Symbol::Symbol(std::string s, std::string w, int c){
  this->symbol = s;
  this->write_symbol = w;
  this->command = c;
}

Symbol::Symbol(std::string s){
  this->symbol = s;
}




