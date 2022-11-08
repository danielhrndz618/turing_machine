#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "./../src/Symbol.cpp"


class Machine{
public:
  int pointer;
  std::vector<Symbol> symbols;
  std::vector<std::string> tokens;
  std::vector<std::string> reserved_words;
  Machine();
  void loadFile(std::string);
  void analyzer(std::string);
  void initializeSymbols(std::string, std::string, std::string); // method for create symbols with constrctor
  int getIndex(std::string, char);
  std::string trimString(int, int, std::string);
  std::vector<std::string> split(std::string);
};
