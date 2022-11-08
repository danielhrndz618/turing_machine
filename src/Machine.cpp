#include "./../include/Machine.h"
#include <iterator>
#include <vector>


Machine::Machine(){
  this->pointer = 0; this->reserved_words.push_back("Estados");
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
    this->run();
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
  std::vector<std::string> words;
  std::string aux = "";
  for(int i = 0; i < line.length(); i++){
    if(line[i] != ',' && i != line.length()-1){
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
    if(line[i] == '(' || line[i] == '['){
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
        this->tokens.push_back(words[i]);
    }
  }

  if(aux == "MT"){
    int x = this->getIndex(line, '[');
    int y = this->getIndex(line, ']');
    std::string ref_line = line;
    std::string mc_string = line.substr(x+1, y-1);
    std::vector<std::string> words = this->split(mc_string);
    std::string symbol_ref = words[1];
    words = std::vector<std::string>();
    int x1 = this->getIndex(line,'(');
    int y1 = this->getIndex(line,')');
    words = this->split(ref_line.substr(x1+1, y1-1));
    this->initializeSymbols(symbol_ref,words[1],words[2]);
  }
}

void Machine::initializeSymbols(std::string symbol, std::string symbol_to_write, std::string move){
  int m = 0;
  if(move == "D") m = 1;
  if(move == "I") m = -1;
  Symbol sim = Symbol(symbol, symbol_to_write, m);
  this->symbols.push_back(sim);   
}


void Machine::run(){
  this->listen();
  for(this->pointer = 0; this->pointer < this->tape.length(); this->pointer++){
    std::string s(1, this->tape[this->pointer]);
    Symbol symbol = this->getSymbol(s);
    std::cout << "Symbolo: " << s << " write: " << symbol.write_symbol << " m: " << symbol.command << std::endl;
  }
}


void Machine::listen(){
  std::cout << "Write your string: ";
  std::cin >> this->tape;
}


Symbol Machine::getSymbol(std::string ref){
  for(Symbol sym : this->symbols){
    if(ref == sym.symbol){
      return sym;
    }
  }
  return Symbol("", "", 0);
}

