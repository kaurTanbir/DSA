#include "../Link_list/linkList.h"
typedef int Comparator(void* nodeData, void* parentData);
typedef struct{
        void* root;
        Comparator *areEqual;
}Tree;

Tree createTree(Comparator* areNodesEqual);
