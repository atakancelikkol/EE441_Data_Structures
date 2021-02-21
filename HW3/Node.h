#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>

class Node
{
    private:

       Node *next;


    public:

        Node (const int &processID=0,const int &arrivalTime=0,const int &runTime=0,const int &priority=0, Node* ptrNext=0);
        void InsertAfter(Node *p);
        Node *DeleteAfter(void);
        Node *NextNode(void) const;

        int processID;      // Since there are no limitation the data are created as public.
        int arrivalTime;
        int runTime;
        int priority;


};

#endif // NODE_H
