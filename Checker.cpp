#include "Checker.h"

Checker::Checker(string file, GenStack<char>* stack){
  m_file = file;
  m_stack = stack;
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
    if (!inFS.fail()){
      inFS >> line;

      for(int i = 0; i < line.size(); ++i){
        char c = line[i];

        if(c == '{' || c == '[' || c == '('){
          m_stack->push(c);
          cout << "Pushing: " << c << endl;
        }else{
          switch(c){
            case ')':
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
              break;

            case ']':
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
              break;

            case '}':
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
              break;

            default://almost forgot about this
              break;
          }
        }
      }
      lineCount++;
    }
  }
  if(m_stack->isEmpty()){
    cout << "All delimeters are correct." << endl;
  }else{
    cout << "Mismatched delimeters." << endl;//some symbols were never matched
  }
}
