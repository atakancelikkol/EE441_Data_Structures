#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    public:
        Stack()
        {
        siz=100;
        data=new T[siz];
        top=0;
        }
    void push(T item);
    T peek();
    T pop();
    bool isEmpty();
    ~Stack();

private:
    T* data;
    int top;
    int siz;
    void resiz();
    bool needToResize();

};

#endif // STACK_H






