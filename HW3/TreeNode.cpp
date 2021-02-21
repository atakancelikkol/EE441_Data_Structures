#include "TreeNode.h"

TreeNode::TreeNode(const int& procid,const int& arrtm,const int& runtm,const int& pri,TreeNode *lptr, TreeNode *rptr):
                    processID(procid),arrivalTime(arrtm),runTime(runtm),priority(pri),left(lptr), right(rptr)
{}

