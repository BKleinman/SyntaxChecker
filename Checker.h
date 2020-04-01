#include "GenStack.h"
#include <fstream>


class Checker{

  public:
    Checker(string file);
    ~Checker();
    void Check();

  private:
    char typeMatch(char d);
    string m_file;
    //GenStack<char>* m_stack;

};
