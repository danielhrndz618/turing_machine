#include "./../include/Machine.h"


Machine::Machine(){
  this->pointer = 0;
}

void Machine::loadFile(std::string filename){
  std::ifstream file;
  std::string cadena, substring;
  file.open(filename, std::ios::in);
  if(file.is_open()){
    while(!file.eof()){
      getline(file, cadena);
      std::cout << "Cadena: " << cadena << std::endl;
    }
    file.close();
  }
  else{
    std::cout << "No se pudo abrir \n";
  }
}
