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
  std::vector<bool> spaces;
  std::string tape;
  std::vector<std::string> result;

  Machine();
  void loadFile(std::string);
  void analyzer(std::string);
  void initializeSymbols(std::string, std::string, std::string); // method for create symbols with constrctor
  void run();
  void listen();
  int getIndex(std::string, char);
  std::string trimString(int, int, std::string);
  std::vector<std::string> split(std::string);
  Symbol getSymbol(std::string);
  int getSize();
  void print();
  int getIndex(std::string, char);
  std::string trimString(int, int, std::string);
};
