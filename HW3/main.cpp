#include <iostream>
#include <fstream>
#include "Node.h"
#include "TreeNode.h"
using namespace std;

// This homework is actually about one thing. The average traversing of BST is very fast rather than Linked List.
// In BST we don't have to search all the elements in order to find specific element.

// In this homework i created RQ in Linked List implementation by sorting data. Therefore,
// I made Linked List's Search Algorithm Complexity as: O(1)
//      Therefore, LL's Insert Algorithm Complexity as: O(N).
// These complexities are both for average and worst cases in Linked List.

// Created BST's algorithm complexity is for search : O(N)
//                                       for insert : O(N)
// HOWEVER!!!!!!!!, these complexities are for worst cases.
// Average complexity of BST would be O(log(N)) for both.
// Therefore, BST Implementation is incredibly very fast implementation
// than the LL when we have high number of processes.

// When Process number is 100,

//                                  Linked List             BST
//#nodes visited for search            100                  393
//#nodes visited for insert            2006                 531

// When Process number is 500,

//                                  Linked List              BST
//#nodes visited for search             500                  3421
//#nodes visited for insert            37114                 4456

// When Process number is 1000,

//                                  Linked List              BST
//#nodes visited for search            1000                  8787
//#nodes visited for insert           157741                 11011





Node *GetNode(const int& procid,const int& arrtm,const int& runtm,const int& pri, Node *nextPtr=NULL)
{
// Simple dynamically created a new node
Node *newNode; //declare pointer
newNode=new Node(procid,arrtm,runtm,pri, nextPtr);
//allocate memory and pass item and next_ptr to the constructor which creates the object
//terminate program if allocation not successful
if (newNode==NULL)
{cerr<<"Memory allocation failed"<<endl;}
return newNode;
}

void InsertFront(Node* & head, int procid, int arrtm, int runtm,int pri)
// Basic Insert Front Function in Linked List Implementation
{head=GetNode(procid,arrtm,runtm,pri,head);}


void DeleteFront(Node* & head)
// Basic Delete Front Function in Linked List Implementation
{
    Node *p = head;
    if (head != NULL)
    {head = head->NextNode();delete p;}}


void InsertOrder(Node* & head, int procid, int arrtm, int runtm,int pri,int &c)
// The function that inserts nodes according to their priority
{   Node *currPtr, *prevPtr, *newNode;

	prevPtr = NULL;
    currPtr = head;
// cycle through the list and find insertion point
    while (currPtr != NULL)
    {c=c+1;
	// found insertion point if pri < current pri
	if (pri < currPtr->priority)
		break;
	// advance currPtr so prevPtr trails it
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();}
    // make the insertion
    if (prevPtr == 0)
	// if prevPtr == NULL, insert at front
        InsertFront(head,procid,arrtm,runtm,pri);
    else
    {
	// insert new node after previous
        newNode = GetNode(procid,arrtm,runtm,pri);
        prevPtr->InsertAfter(newNode);
    }
}

// Simple dynamically created a new tree node
TreeNode* GetTreeNode(TreeNode item, TreeNode* leftptr=0, TreeNode* rightptr=0)
{
    TreeNode* p;
    p=new TreeNode(item.processID,item.arrivalTime,item.runTime,item.priority,leftptr,rightptr);
    if(p==0)
    {cout<< "Memory allocation failed"<<endl;
    }
    return p;
}
// Simple destructor function
void FreeTreeNode(TreeNode *p)
{delete p;}

// The function that inserts tree nodes according to their priority
// to the Binary Search Tree. Its implementation is simple:
// For example we want to insert 50,40,80,30,15
// It takes root node as 50 by first if condition.
// and then according to first tree node's priority
// it puts the other nodes to first's nodes left or right.
void InsertTreeNode(TreeNode*& t,TreeNode added, int&c)
{
    TreeNode* currento=t;
    if(t==0)
    {   // base condition
        t=GetTreeNode(added);
    }
    else
    {
        c++;

        if(added.priority<currento->priority)
        {// if priority of added root is lower than the current node
         // insert it to its left
            InsertTreeNode(t->left,added,c);
        }
        else
        {// if priority of added root is lower than the current node
         // insert it to its right
            InsertTreeNode(t->right,added,c);
        }
    }
}

// The function that searches in Binary Search Tree minimum
// priority node.
TreeNode* SearchMinPriority(TreeNode*&t,int&c)
{
    TreeNode* minpriority;
    TreeNode* currnt;
    TreeNode* next;

    currnt=t;
    next=t->left;

    if(t==0)
    {   // if there is no root node it's an empty tree
        cout<< "Empty Tree !"<<endl;
        return 0;
    }
    else if(t->left==0)
    {
        // if a treenode's(current tree node's) left is empty then
        // the minpriority tree node is the exactly the current tree node.
        c++;
        minpriority=t;
        t=t->right;
        return minpriority;
    }
    else
    {
        c++;
        // if we have a left node of tree node
        // then we should find leftmost tree node
        while(next->left!=0)
        {
            c++;
            currnt=next;
            next=next->left;
        }
        // after this we could find the leftmost also
        // the min priority tree node
        minpriority=next;

        // if we have right child of next pointer,
        // after the foundation of minpriority, we should connect
        // BST again.
        if(next->right!=0)
        {
            c++;
            currnt->left=next->right;
            next->right=0;
        }
        // if we have not right child of next simply
        // we do not have to connect BST.
        else
        {
            currnt->left=0;
        }
        return minpriority;
    }
}



int main()
{
    ifstream processesFile;

    processesFile.open ("processes.txt");

    int numProcesses; /* number of processes */

    processesFile >> numProcesses; /* read from file */
    cout << "# of Processes:"<< numProcesses << endl;

    Node process[numProcesses];
    TreeNode process2[numProcesses];
    int processID, arrivalTime, runTime, priority;
    for(int i=0; i<numProcesses; ++i)
{
    processesFile >> processID >> arrivalTime >> runTime >> priority;

    process[i] = Node(processID, arrivalTime, runTime, priority);
    process2[i]=TreeNode(processID, arrivalTime, runTime, priority);

 }
 processesFile.close();

    int time=0; // CPU Time
    bool CPUBusy=false;

    int currentProcess[4]; // Since current process is created just for showing us the what is the current process,
                           // it is created as just 4 integer data of the nodes.

    Node*RQ=0;  // head pointer of Linked List RQ Implementation

    int counter1=0; // visited node counter in the insertion process in Linked List Implementation
    int counter2=0;// visited node counter in the searching process in Linked List Implementation
    int k=0;  // process index



    // And this part is just the translation of the given Pseudo Code for Linked List implementation.
    while(k<numProcesses || RQ!=0 || CPUBusy==true)
    {
        if(k<numProcesses)   // there are processes not inserted into RQ
        {
            if(process[k].arrivalTime==time)
            {


                InsertOrder(RQ,process[k].processID,process[k].arrivalTime,process[k].runTime,process[k].priority,counter1);
                k=k+1;
            }
        }
        if(CPUBusy==true)
        {
            currentProcess[2]=currentProcess[2]-1 ;

            if(currentProcess[2]==0)
            {
                cout<<currentProcess[0]<<endl;
                CPUBusy=false;
            }
        }
        if(CPUBusy==false && RQ!=0)
        {
            counter2++;

            currentProcess[0]=RQ->processID;
            currentProcess[1]=RQ->arrivalTime;
            currentProcess[2]=RQ->runTime;
            currentProcess[3]=RQ->priority;
            DeleteFront(RQ);
            CPUBusy=true;
        }
    time=time+1;
    }


    cout<<" " <<endl;
    cout<<"End of Linked List Implementation of Ready Queue"<<endl;
    cout<<" " <<endl;

    int currentProcess2[4];// Since current process is created just for showing us the what is the current process,
                           // it is created as just 4 integer data of the nodes.(BST)

    int time2=0; // CPU Time
    bool CPUBusy2=false;
    int u=0; // Process index of BST Implementation
    TreeNode*TRQ=0; // Tree Node of BST
    TreeNode*x;
    int counter3=0; // Number of visited nodes in insertion process -BST-
    int counter4=0;// Number of visited nodes in searching process -BST-


    // Pseudo Code translation
    while((u<numProcesses || TRQ!=0 || CPUBusy2==true))
    {
        if(u<numProcesses)   // there are processes not inserted into TRQ
        {
            if(process2[u].arrivalTime==time2)
            {
                InsertTreeNode(TRQ,process2[u],counter3);
                u=u+1;
            }
        }
        if(CPUBusy2==true)
        {
            currentProcess2[2]=currentProcess2[2]-1 ;

            if(currentProcess2[2]==0)
            {
                cout<<currentProcess2[0]<<endl;
                CPUBusy2=false;
            }
        }
        if(CPUBusy2==false && TRQ!=0)
        {
            counter4++;
            x=SearchMinPriority(TRQ,counter4);
            currentProcess2[0]=x->processID;
            currentProcess2[1]=x->arrivalTime;
            currentProcess2[2]=x->runTime;
            currentProcess2[3]=x->priority;
            FreeTreeNode(x);
            CPUBusy2=true;
        }
    time2=time2+1;
    }
        cout<<"End of Binary Search Tree Implementation of Ready Queue"<<endl;
        cout<<" " <<endl;
        cout<<counter2<< "# nodes visited for searching in Linked List"<<endl;
        cout<<counter1<< "# nodes visited for insertion in Linked List"<<endl;
        cout<<" " <<endl;
        cout<<counter4<< "# nodes visited for searching in Binary Search Tree"<<endl;
        cout<<counter3<< "# nodes visited for insertion in Binary Search Tree"<<endl;
    return 0;
}







