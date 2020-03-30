#include "GenStack.h"

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid number of command line arguments." << endl;
    return 1;
  }

  GenStack<char>* myStack = new GenStack<char>(10);
  cout << myStack->pop() << endl;

  return 0;
}
