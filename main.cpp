#include "Checker.h"

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid number of command line arguments." << endl;
    return 1;
  }
  bool pass = false;

  Checker* c1 = new Checker(argv[1]);

  c1->Check();


  return 0;
}
