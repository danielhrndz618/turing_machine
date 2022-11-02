#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "./../src/Symbol.cpp"


class Machine{
public:
  int pointer;
  std::vector<Symbol> symbols;
  std::vector<std::string> reserved_words;
  Machine();
  void loadFile(std::string);
  void analyzer(std::string);
};
