#include "queue.h"

#include<stdexcept>
#include <iostream>
using namespace std;

template <class T>
void Queue<T>::Qinsert(const T& item)
{
// terminate if queue is full
if(needToResizeq())
        {
        resizq();
        }
//increment count, assign item to qlist and update rear
//c++;
qdata[ rear] =item;
rear=(rear+1);
}

template <class T>
Queue<T>::~Queue()
{
    delete []qdata;
}

template <class T>
T Queue<T>::QDelete(void)
{
T temp;
// if qlist is empty, terminate the program
    if (frnt==rear)
{
cout<<"Deleting from an empty queue!"<<endl;
}
//record value at the front of the queue
temp=qdata[frnt];
//decrement count, advance front and return former front
//c --;
frnt=(frnt+1) ;
return temp;
}

template <class T>
int Queue<T>::QLength()
{
    return rear-frnt;
}

template <class T>
bool Queue<T>::QEmpty()
{
    if (rear==frnt)
    {
        return true;
    }
    else return false;
}

template <class T>
bool Queue<T>::needToResizeq()
{
    return (rear==sz);
}

template <class T>
void Queue<T>::resizq()
{
    T* newdataq=new T[2*sz];
    for(int i =0 ; i<sz;i++)

        newdataq[i]=qdata[i];
        qdata=newdataq;
        sz*=2;


    /*  T*newdata=new T[2*siz];
    for(int i =0 ; i<siz;i++)
        newdata[i]=data[i];
    data=newdata;
    siz*=2;
    */
}




template class Queue<int>;
template class Queue<string>;
template class Queue<double>;
template class Queue<char>;

