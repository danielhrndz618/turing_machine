#include <iostream>
#include "Machine.cpp"
using namespace std;

int main(int argc, char *argv[]){
  if(argc < 2){
    std::cout << "missing filename \n";
  }
  else{
    cout << "Machine running..." << endl;
    Machine machine = Machine();
    machine.loadFile(argv[1]); 
  }
}
