// an exception for an empty Stack
#include <string>

using namespace std;

class EmptyStackException{
  public:
    EmptyStackException(const string& err)
      : errMSG(err) { }
    string getError() { return errMSG; }

  private:
    string errMSG;

};
