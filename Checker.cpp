#include "Checker.h"

Checker::Checker(string file){
  m_file = file;
  m_stack = new GenStack<char>(20);
}

Checker::~Checker(){
  delete m_stack;
}


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
    cout << "Weird return" << endl;
    return '\0';
  }
}

void Checker::Check(){
  char c;
  ifstream inFS;
  string line = "";
  int lineCount = 0;
  inFS.open(m_file);

  while(!inFS.eof()){
    getline(inFS, line);
    //if (!inFS.fail()){

      cout << line << endl;
      for(int i = 0; i < line.size(); ++i){
        char c = line[i];

        if(c == '{' || c == '[' || c == '('){
          m_stack->push(c);
          cout << "Pushing: " << c << endl;
          cout << "Size: " << m_stack->getSize() << endl;
        }else{
          //switch(c){
            //case ')':
            if(c == ')'){
              if(m_stack->isEmpty()){
                cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
                inFS.close();
                exit(1);
              }if(m_stack->peek() != typeMatch(c)){
                cout << "Mismatched delimeters on line: " << lineCount << endl; //wrong type
                cout << "Opener: " << m_stack->peek() << " Closer: " << c << endl;
                inFS.close();
                exit(1);
              }
              cout << "Popping: " << m_stack->peek() << endl;
              m_stack->pop();
            //  break;
            }else if(c == ']'){
            //case ']':
              if(m_stack->isEmpty()){
                cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
                inFS.close();
                exit(1);
              }if(m_stack->peek() != typeMatch(c)){
                cout << "Mismatched delimeters on line: " << lineCount << endl; //wrong type
                cout << "Opener: " << m_stack->peek() << " Closer: " << c << endl;
                inFS.close();
                exit(1);
              }
              cout << "Popping: " << m_stack->peek() << endl;
              m_stack->pop();
              //break;
            }else if(c == '}'){
            //case '}':
              if(m_stack->isEmpty()){
                cout << "Extra " << c << " on line: " << lineCount << endl;//nothing to match with
                inFS.close();
                exit(1);
              }if(m_stack->peek() != typeMatch(c)){
                cout << "Mismatched delimeters on line: " << lineCount << endl; //wrong type
                cout << "Opener: " << m_stack->peek() << " Closer: " << c << endl;
                inFS.close();
                exit(1);
              }
              cout << "Popping: " << m_stack->peek() << endl;
              m_stack->pop();
              //break;
            }
            //default://almost forgot about this
              //break;
          //}
        }
      }
      lineCount++;
    //}
  }
  if(m_stack->isEmpty()){
    cout << "All delimeters are correct." << endl;
  }else{
    cout << "Mismatched delimeters." << endl;//some symbols were never matched
  }
}
