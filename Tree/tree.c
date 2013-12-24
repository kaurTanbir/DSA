#include "tree.h"
#include <stdlib.h>

typedef struct Tree_Node{
    struct Tree_Node* parent;
    DList* child;
    void* data;
}Tree_Node;

// Tree_Node* getChildByIndex(Tree_Node tNode, int index);
Tree_Node* checkEachNodes(Tree_Node* tNode, Comparator* areEqual,void* parentData);
Tree_Node* searchParentNode(Tree tree, void *parentData);


Tree createTree(Comparator *areNodesEqual){
    Tree tree = {NULL,areNodesEqual};
    return tree;
};

Tree_Node* createTreeNode(Tree_Node* parent, void* data){
    Tree_Node* treeNode = malloc(sizeof(Tree_Node));
    treeNode->child = create();
    treeNode->parent = parent;
    treeNode->data = data;
    return treeNode;
};

int insertInTree(Tree* tree, void *parentData, void *dataToInsert){
    Tree_Node* parentNode;
    if(NULL == parentData){
        tree->root = createTreeNode(NULL, dataToInsert);
        return 1;
    }
    parentNode = searchParentNode(*tree, parentData);
    return insertNode(parentNode->child, parentNode->child->length,dataToInsert);
};

