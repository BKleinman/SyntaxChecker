#include <iostream>
#include "StackEmpty.cpp"


template <typename T>
class GenStack
{
  public:
    GenStack(); //default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();// destructor

    //core functions
    void push(T data); //insert
    T pop() throw(EmptyStackException); //remove top

    //aux helper functions
    T peek();
    bool isEmpty();
    bool isFull();
    int getSize();

    int m_top; //index of top element
    int m_size; //size of stack

    T* myArray;
};

template<typename T>
GenStack<T>::GenStack(){ //default
  myArray = new T[128];
  m_size = 128;
  m_top = -1;

}
template<typename T>
GenStack<T>::GenStack(int maxSize){ //overloaded
  myArray = new T[maxSize];
  m_size = maxSize;
  m_top = -1;

}

template<typename T>
GenStack<T>::~GenStack(){//destructor
  delete myArray;
}

template<typename T>
void GenStack<T>::push(T data){
  if(isFull()){
    T* newStack = new T[m_size * 2];//creating a new array that is double the size of the old one(I think this is how they do vectors?)
    for(int i = 0; i < m_size; ++i){
      newStack[i] = myArray[i];
    }
    delete myArray;
    myArray = newStack;
    m_size *= 2;
    myArray[++m_top] = data;
  }else{
    myArray[++m_top] = data;
  }
}

template<typename T>
T GenStack<T>::pop() throw(EmptyStackException){
  try{
    if(isEmpty()){
      throw(EmptyStackException("Trying to pop for an empty stack.\n"));
    }
  }catch (EmptyStackException& e){
    e.getError();
    exit(1);
  }
  return myArray[m_top--];
}

template<typename T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout << "Stack is empty." << endl;
  }else{
    return myArray[m_top];
  }

}

template<typename T>
bool GenStack<T>::isFull(){
  return (m_top == m_size - 1);
}

template<typename T>
bool GenStack<T>::isEmpty(){
  return(m_top == -1);
}

template<typename T>
int GenStack<T>::getSize(){
  return m_size;
}
