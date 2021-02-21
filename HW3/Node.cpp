#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

Node ::Node(const int& procid,const int& arrtm,const int& runtm,const int& pri, Node* ptrnext):
     processID(procid),arrivalTime(arrtm),runTime(runtm),priority(pri), next(ptrnext)
{}


Node *Node ::NextNode(void) const
    {
    return next;
    }






void Node::InsertAfter(Node *p)
{
p->next=next;
next=p;
}

Node *Node::DeleteAfter(void)
{
Node  *tempPtr=next;

if (next==NULL) return NULL;
next=tempPtr->next;
return tempPtr;
}




//Node::~Node()
//{
//    //dtor
//}




