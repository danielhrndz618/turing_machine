#include "./../include/Machine.h"
#include <iterator>


Machine::Machine(){
  this->pointer = 0;
  this->reserved_words.push_back("Estados");
  this->reserved_words.push_back("Inicial");
  this->reserved_words.push_back("Ha");
  this->reserved_words.push_back("He");
  this->reserved_words.push_back("Alfabeto");
  this->reserved_words.push_back("MT");
}

void Machine::loadFile(std::string filename){
  std::ifstream file;
  std::string cadena, substring;
  file.open(filename, std::ios::in);
  if(file.is_open()){
    while(!file.eof()){
      getline(file, cadena);
      /* cadena.erase(remove(cadena.begin(), cadena.end(), ' ')); */
      std::cout << "Cadena: " << cadena << std::endl;
      this->analyzer(cadena);
    }
    file.close();
  }
  else{
    std::cout << "No se pudo abrir \n";
  }
}

int Machine::getIndex(std::string ref, char c){
  auto it = std::find(ref.begin(), ref.end(), c);
  if(it != ref.end()){
    return std::distance(ref.begin(), it);
  }
  return -1;
}

std::string Machine::trimString(int x, int y, std::string ref){
  return ref.substr(0, x) + ref.substr(y, ref.length()-1);
}


std::vector<std::string> Machine::split(std::string line){
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  std::cout << "linea sin espacios: " << line << std::endl;
  std::vector<std::string> words;
  std::string aux = "";
  for(int i = 0; i < line.length(); i++){
    if(line[i] != ',' && line[i] != ')'){
      aux += line[i];
    }
    else{
      words.push_back(aux);
      aux = "";
    }
  }
  return words;
}


void Machine::analyzer(std::string line){
  std::string aux = "";
  for(int i = 0; i < line.length(); i++){
    if(line[i] == '('){
      break;
    }
    else{
      if(line[i] != ' '){
        aux += line[i];
      }
    }
  }
  
  if(aux == "Alfabeto"){
    int x = this->getIndex(line, '(');
    int y = this->getIndex(line, ')');
    std::string substring = line.substr(x+1, y);
    std::vector<std::string> words = this->split(substring);
    for(int i = 0; i < words.size(); i++)
    {
      std::cout << "palabra: " << words[i] << std::endl;
    }
  }





  /* std::cout << "Filtered Line: " << aux << std::endl; */
}







