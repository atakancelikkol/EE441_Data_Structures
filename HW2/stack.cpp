#include "stack.h"
#include<stdexcept>
using namespace std;

template <class T>
void Stack<T>::push(T item)
{
    if(needToResize())
        resiz();
    data[top]=item;
    top++;
}

template <class T>
Stack<T>::~Stack()
{
    delete []data;
}

template <class T>
T Stack<T>::peek()
{
    if(top<=0)
        throw out_of_range("Attempted to peek an empty stack");
        return data[top-1];
}

template <class T>
T Stack<T>::pop()
{
    if(top<=0)
        throw out_of_range("Attempted to pop an empty stack");
        top--;
        return data[top];
}

template <class T>
bool Stack<T>::needToResize()
{
    return(top==siz);
}

template <class T>
void Stack<T>::resiz()
{
    T*newdata=new T[2*siz];
    for(int i =0 ; i<siz;i++)
        newdata[i]=data[i];
    data=newdata;
    siz*=2;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if(top==0) return true;
    else
        {
        return false;
    }
}

//

template class Stack<int>;
template class Stack<string>;
template class Stack<double>;
template class Stack<char>;








