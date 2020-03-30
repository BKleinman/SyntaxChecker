#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Checker{

  public:
    void Check(string file);

  private:
    char typeMatch(char d);

};


char Checker::typeMatch(char d){
  if(d == '('){
    return ')';
  }else if(d == '['){
    return ']';
  }else if(d == '{'){
    return '}';
  }else if(d == ')'){
    return '(';
  }else if(d == ']'){
    return '[';
  }else if(d == '}'){
    return '{';
  }else{
    return '\0';
  }
}

void Checker::Check(string file){
  GenStack<char> stack = new GenStack(128);
  char c;
  ifstream inFS;
  string line = "";
  inFS.open(file);


  while(!inFS.eof()){
    if (!inFS.fail()){
      inFS >> line;

      for(int i = 0; i < line.size(); ++i){
        //iterating through each DNA sequence to get the count of each nucleotide
        char c = line[i];
        if(c == '{' || c == '[' || c == '('){
          stack.push(c);
        }else if(c == '}' || c == ']' || c == ')'){
          if(stack.isEmpty()){
            cout << "Mismatched delimeters." << endl;//nothing to match with
            break;
          }if(stack.top() != typeMatch(c)){
            cout << "Mismatched delimeters." << endl; //wrong type
            break;
          }
          stack.pop();
        }

      }
      if(stack.isEmpty()){
        cout << "All delimeters are correct." << endl;
      }else{
        cout << "Mismatched delimeters." << endl;//some symbols were never matched
      }


  }
}
