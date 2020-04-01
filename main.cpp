#include "Checker.h"

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid number of command line arguments." << endl;
    return 1;
  }

  Checker* c1 = new Checker(argv[1]);
  c1->Check();

  char yesNo = '\0';
  string fileName = "";
  bool pass = true;
  while(pass){
    cout << "Would you like to process another file for syntax checking?(y/n)" << endl;
    cin >> yesNo;
    yesNo = tolower(yesNo);
    if(yesNo == 'n'){
      cout << "Thank you. Please come again." << endl;
      pass = false;
      break;
    }else if(yesNo == 'y'){
      cout << "Please provide the name of the file you would like to have checked." << endl;
      cin >> fileName;
      Checker* c2 = new Checker(fileName);
      cout << "Processing file." << endl;
      c2->Check();
    }else{
      cout << "Invalid input. Please try again." << endl;
    }
  }


  return 0;
}
