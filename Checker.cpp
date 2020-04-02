/*
  Brandon Kleinman - 2291703
  Assignment 3 - Syntax Checker
  Method Implementation for a helper class
 */
#include "Checker.h"

Checker::Checker(string file){
  m_file = file;
  //myStack = new GenStack<char>(20);
}

Checker::~Checker(){
  //delete myStack;
}


void Checker::Check(){
  GenStack<char>* myStack = new GenStack<char>(20);
  char c;
  ifstream inFS;
  string line = "";
  int lineCount = 0;
  inFS.open(m_file);

  while(!inFS.eof()){
    getline(inFS, line);
    
    for(int i = 0; i < line.size(); ++i){
      char c = line[i];

      if(c == '{' || c == '[' || c == '('){
        myStack->push(c);
      }else{
        switch(c){
          case ')':
            if(myStack->isEmpty()){
              cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
              inFS.close();
              exit(1);
            }if(myStack->peek() != '('){
              cout << "Mismatched Delimiters on line: " << lineCount << endl; //wrong type
              cout << "Opener: " << myStack->peek() << " Closer: " << c << endl;
              inFS.close();
              exit(1);
            }
            myStack->pop();
            break;

          case ']':
            if(myStack->isEmpty()){
              cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
              inFS.close();
              exit(1);
            }if(myStack->peek() != '['){
              cout << "Mismatched Delimiters on line: " << lineCount << endl; //wrong type
              cout << "Opener: " << myStack->peek() << " Closer: " << c << endl;
              inFS.close();
              exit(1);
            }
            myStack->pop();
            break;

          case '}':
            if(myStack->isEmpty()){
              cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
              inFS.close();
              exit(1);
            }if(myStack->peek() != '{'){
              cout << "Mismatched Delimiters on line: " << lineCount << endl; //wrong type
              cout << "Opener: " << myStack->peek() << " Closer: " << c << endl;
              inFS.close();
              exit(1);
            }
            myStack->pop();
            break;

          default://almost forgot about this
            break;
        }
      }
    }
    lineCount++;
  }
  if(myStack->isEmpty()){
    cout << "All Delimiters are correct." << endl;
  }else{
    cout << "Mismatched Delimiters." << endl;//some symbols were never matched
  }
}
