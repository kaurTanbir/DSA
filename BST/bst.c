#include "bst.h"
#include <stdlib.h>

typedef struct Node{
    void* value;
    struct Node* parent;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

BST createTree(Compare *comp){
    BST tree ;
    tree.root = NULL;
    tree.comparator = comp;
    return tree;
}


Node* createNode(void* dataToInsert, Node* data){
    Node* node = malloc(sizeof(Node));
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->value = dataToInsert;
    node->parent = data;
    return node;
}

int insertInTree(BST *tree, void *dataToInsert){
    if(!tree->root){
        tree->root = createNode(dataToInsert, NULL);
        return 1;
    }
    return 0;
}

void* getRootData(BST tree){
    Node *node = tree.root;
    return node->value;
}