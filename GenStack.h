/*
  Brandon Kleinman - 2291703
  Assignment 3 - Syntax Checker
  Class definition for a stack using template classes
 */
#include <iostream>
#include "StackEmpty.cpp"


template <typename T>//template class is allowing for any data type
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

    int m_top; //index of top element
    int m_size; //size of stack

    T* myArray;//this array is what we will use to store elements in the stack
};

template<typename T>//template class is allowing for any data type
GenStack<T>::GenStack(){ //default
  myArray = new T[128];
  m_size = 128;
  m_top = -1;

}
template<typename T>//template class is allowing for any data type
GenStack<T>::GenStack(int maxSize){ //overloaded
  myArray = new T[maxSize];
  m_size = maxSize;
  m_top = -1;

}

template<typename T>//template class is allowing for any data type
GenStack<T>::~GenStack(){//destructor
  delete myArray;
}

template<typename T>//template class is allowing for any data type
void GenStack<T>::push(T data){
  if(isFull()){//if the user wants to push to a full stack we will double the size and create a new stack
    T* newStack = new T[m_size * 2];//creating a new array that is double the size of the old one(I think this is how they do vectors?)
    for(int i = 0; i < m_size; ++i){//iterating through the array
      newStack[i] = myArray[i];//copying over
    }
    delete myArray;//delete the old array
    myArray = newStack;//reassigning
    m_size *= 2;//doubling the size
    myArray[++m_top] = data;
  }else{
    myArray[++m_top] = data;
  }
}

template<typename T>
T GenStack<T>::pop() throw(EmptyStackException){
  try{
    if(isEmpty()){
      throw(EmptyStackException("Trying to pop from an empty stack."));
    }
  }catch (EmptyStackException& e){
    cout << e.getError() << endl;
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
