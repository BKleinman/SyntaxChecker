/*
  Brandon Kleinman - 2291703
  Assignment 3 - Syntax Checker
  A definition for an exception of an empty stack
 */
#include <string>

using namespace std;

class EmptyStackException{
  public:

    EmptyStackException(const string& err){errMSG = err;}//constructor for the exception
    ~EmptyStackException(){}//destructor

    string getError() { return errMSG; }//this function returns the exception message

  private:
    string errMSG;//exception message

};
