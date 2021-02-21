#ifndef TREENODE_H
#define TREENODE_H


class TreeNode
{



    public:
        TreeNode(const int &processID=0,const int &arrivalTime=0,const int &runTime=0,const int &priority=0,TreeNode*left=0,TreeNode*right=0);

        TreeNode *left;         // Since there is no limitation to ease implementation
        TreeNode *right;        // left and right pointers created as public.
        int processID;
        int arrivalTime;
        int runTime;
        int priority;


};

#endif // TREENODE_H
