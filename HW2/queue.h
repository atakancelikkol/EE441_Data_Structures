#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
    public:
        Queue()
        {
         sz=100;

         rear=0;
         frnt=0;
         qdata= new T[sz];
        }
        void Qinsert(const T& item);
        T QDelete(void);
        int QLength();
        bool QEmpty();
        ~Queue();

    private:
        T *qdata;

        int rear;
        int frnt;
        int sz;
        void resizq();
        bool needToResizeq();
};

#endif // QUEUE_H
