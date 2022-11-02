#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "./../src/Symbol.cpp"


class Machine{
public:
  int pointer;
  std::vector<Symbol> symbols;
  Machine();
  void loadFile(std::string);
};
