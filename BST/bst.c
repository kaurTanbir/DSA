#include "bst.h"
#include <stdlib.h>

typedef struct Node{
    void* value;
    struct Node* parent;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
int insertAsChild(Node* node, void* dataToInsert, Compare* comp);

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

int insertAtLeft(Node* node, void* dataToInsert, Compare* comp){
    if(!node->leftChild){
        node->leftChild = createNode(dataToInsert, node);
        return 1;
    }
    return insertAsChild(node->leftChild, dataToInsert, comp);
}

int insertAtRight(Node* node, void* dataToInsert, Compare* comp){
    if(!node->rightChild){
        node->rightChild = createNode(dataToInsert, node);
        return 1;
    }
    return insertAsChild(node->rightChild, dataToInsert, comp);
}

int insertAsChild(Node* node, void* dataToInsert, Compare* comp){
    int compareResult = comp(node->value, dataToInsert);
    if(compareResult == 0) return 0;
    if(compareResult < 0)
        return insertAtRight(node, dataToInsert, comp);
    return insertAtLeft(node, dataToInsert, comp);        
}

int insertInTree(BST *tree, void *dataToInsert){
    if(!tree->root){
        tree->root = createNode(dataToInsert, NULL);
        return 1;
    }
    return insertAsChild(tree->root, dataToInsert, tree->comparator);;
}

void* getRootData(BST tree){
    Node *node = tree.root;
    return node->value;
}
Node* checkAllNode(Node* node,void* data, Compare comp){
    int compareResult;
    compareResult = comp(node->value, data);
    if(!compareResult) return node;
    if(compareResult > 0)
        return checkAllNode(node->rightChild, data,comp);
    return checkAllNode(node->leftChild, data,comp);
}

Node* getNode(BST tree, void* data){
    Node *root = (Node*)(tree.root);
    if(!root) return root;
    return checkAllNode(root, data, tree.comparator);
}
Child_data getChildData(BST tree, void *parentData){
    Child_data result ;
    Node* node = getNode(tree, parentData);
    if(!node) return result;
    if(node->leftChild)
        result.left = node->leftChild->value;
    if(node->rightChild)
        result.right = node->rightChild->value;
    return result;
}
