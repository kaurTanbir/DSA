#include "privateTree.h"
#include <stdlib.h>

//-----------------------------create-------------------------------------------------------
Tree createTree(Comparator *areNodesEqual){
    Tree tree = {NULL,areNodesEqual};
    return tree;
};

TreeNode* createTreeNode(TreeNode* parent, void* data){
    TreeNode* Node = malloc(sizeof(TreeNode));
    Node->children = create();
    Node->parent = parent;
    Node->data = data;
    return Node;
};
//------------------------------------insert----------------------------------------------
int insertTreeNode(Tree* tree, void *parentData, void *dataToInsert){
    TreeNode *parentNode, *nodeToInsert;
    if(parentData == NULL){                                        // create root node
        tree->root = createTreeNode(NULL, dataToInsert);
        return 1;
    }
    parentNode = getTreeNode(*tree, parentData);
    if(!parentNode) return 0;
    nodeToInsert = createTreeNode(parentNode, dataToInsert);
    return insertNode(parentNode->children, nodeToInsert, parentNode->children->length);
};

TreeNode* getTreeNode(Tree tree, void *nodeData){
    TreeNode* root = tree.root;
    if(NULL == nodeData || NULL == root)
        return NULL;
    if(tree.areEqual(root->data, nodeData)) return root;
    return checkEachNodes(root->children, nodeData, tree.areEqual);
}

TreeNode* checkEachNodes(DList *list, void* nodeData, Comparator* areEqual){
    Iterator it = getIterator(list);
    DList *tempList = create();
    TreeNode *Node;
    while(it.hasNext(&it)){
        Node = (TreeNode*)it.next(&it);
        if(areEqual(Node->data,nodeData)){
            return Node;
        }
        getAllChildren(Node, tempList);
    }
    if(tempList->length)
        return checkEachNodes(tempList, areEqual, nodeData);
    return NULL;
};
void getAllChildren(TreeNode* Node, DList *list){
    Iterator it_child;
    it_child = getIterator(Node->children);
    while(it_child.hasNext(&it_child)){
        insertNode(list, it_child.next(&it_child), list->length);
    }
}
//----------------------------iterator-----------------------------------------------------
Iterator getChildren(Tree tree, void *parentData){
    TreeNode* parentNode = getTreeNode(tree, parentData);
    Iterator it;
    if(!parentNode) {
        it = getIterator(NULL);
        return it;
    }
    it = getIterator(parentNode->children);
    it.next = &getNextChildData;
    return it;
}


void* getNextChildData(Iterator* it){
    TreeNode *node;
    Iterator treeIterator = getIterator(it->list);
    treeIterator.position = it->position;
    node = treeIterator.next(&treeIterator);
    if(!node) return node;
    it->position++;
    return node->data;
}
//---------------------------------------search-------------------------------------------

int searchInTree(Tree tree, void *data){
    return getTreeNode(tree, data)!=NULL;
}
//------------------------delete---------------------------------------------------


int getChildIndex(DList list,void* childData, Comparator* areEqual){
    Iterator it = getIterator(&list);
    TreeNode *Node;
    int result;
    while(it.hasNext(&it)){
        Node = it.next(&it);
        result = areEqual(Node->data, childData);
        if(result) return it.position - 1;
    }
    return -1;
}

int hasChildren(TreeNode Node){
    return Node.children->head != NULL;
}

int deleteFromTree(Tree *tree, void *data){
    TreeNode *Node = getTreeNode(*tree, data);
    TreeNode *parentNode;
    int index;
    if(!Node) return 0;
    if(hasChildren(*Node)) return 0;
    parentNode = Node->parent;
    if(!parentNode){
        free(Node);
        return 1;                
    }
    index = getChildIndex(*parentNode->children, Node->data, tree->areEqual);
    return deleteNode(parentNode->children, index);
}