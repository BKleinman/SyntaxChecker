#include <iostream>
using namespace std;

template <typename T>
class GenStack
{
  public:
    GenStack(); //default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();// destructor

    //core functions
    void push(T data); //insert
    T pop(); //remove top

    //aux helper functions
    T peek();
    bool isEmpty();
    bool isFull();

    int m_top; //index of top element
    int m_size; //size of stack

    T* myArray;
};

template<typename T>
GenStack::GenStack(){ //default
  myArray = new T[128];
  m_size = 128;
  m_top = -1;

}
template<typename T>
GenStack::GenStack(int maxSize){ //overloaded
  myArray = new T[maxSize];
  m_size = maxSize;
  m_top = -1;

}

template<typename T>
GenStack::~GenStack(){//destructor
  delete myArray;
}

template<typename T>
void GenStack::push(T data){
  if(isFull()){
    T* newStack = new T[m_size * 2];//creating a new array that is double the size of the old one(I think this is how they do vectors?)
    for(int i = 0; i < m_size; ++i){
      newStack = myArray[i];
    }
    delete myArray;
    myArray = newStack;
    m_size *= 2;
  }else{
    myArray[++m_top] = data;
  }
}

template<typename T>
T GenStack::pop(){
  //try{
    if(isEmpty()){

    }
  //}catch (){

  //}
  return myArray[m_top--];
}

template<typename T>
T GenStack::peek(){
  if(isEmpty()){
    cout << "Stack is empty." << endl;
  }else{
    return myArray[m_top];
  }

}

bool GenStack::isFull(){
  return (m_top == m_size - 1);
}

bool GenStack::isEmpty(){
  return(m_top == -1);
}
