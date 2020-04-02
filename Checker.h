/*
  Brandon Kleinman - 2291703
  Assignment 3 - Syntax Checker
  Header file for a helper class
 */
#include "GenStack.h"
#include <fstream>


class Checker{

  public:
    Checker(string file);
    ~Checker();
    void Check();

  private:
    string m_file;


};
