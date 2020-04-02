/*
  Brandon Kleinman - 2291703
  Assignment 3 - Syntax Checker
  Main method
 */
#include "Checker.h"

using namespace std;

int main(int argc, char** argv){
  if(argc < 2){
    cout << "Invalid number of command line arguments." << endl;
    return 1;
  }

  Checker* c1 = new Checker(argv[1]);//creating a checker object that will check the file passed in the command line
  c1->Check();//checking

  char yesNo = '\0';
  string fileName = "";
  bool pass = true;
  while(pass){//when the initial check is done the user is prompted as to whether or not they want to process another file
    cout << "Would you like to process another file for syntax checking?(y/n)" << endl;
    cin >> yesNo;
    yesNo = tolower(yesNo);
    if(yesNo == 'n'){//if the user does not want to process another file
      cout << "Thank you. Please come again." << endl;
      pass = false;
      break;
    }else if(yesNo == 'y'){//if the user wants to process another file
      cout << "Please provide the name of the file you would like to have checked." << endl;//prompting the user for another file
      cin >> fileName; //taking in the file name
      Checker* c2 = new Checker(fileName);//checking the second file which the user entered
      cout << "Processing file." << endl;
      c2->Check();//performing the check
    }else{
      cout << "Invalid input. Please try again." << endl;
    }
  }


  return 0;
}
