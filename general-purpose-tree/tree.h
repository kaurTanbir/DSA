#include "./include/linkList.h"

typedef int Comparator(void* nodeData, void* parentData);
typedef struct{
        void* root;
        Comparator *areEqual;
}Tree;

Tree createTree(Comparator* areNodesEqual);

int insertTreeNode(Tree* ptree, void* parentData, void* dataToInsert);
Iterator getChildren(Tree tree, void* parentData);

int deleteFromTree(Tree* ptree, void* data);
int searchInTree(Tree tree, void *data);
