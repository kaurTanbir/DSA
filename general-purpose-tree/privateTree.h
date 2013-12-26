#include "tree.h"

typedef struct TreeNode{
    struct TreeNode* parent;
    DList* children;
    void* data;
}TreeNode;
TreeNode* checkEachNodes(DList *list, void* parentData, Comparator* areEqual);
TreeNode* searchParentNode(Tree tree, void *parentData);
TreeNode* getTreeNode(Tree tree,void *dataToFind);
void* getNextChildData(Iterator* it);
void getAllChildren(TreeNode* Node, DList *list);