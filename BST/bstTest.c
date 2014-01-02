#include "testUtils.h"
#include "bst.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareNodes(void* first, void* second){
    return *(int*)first - *(int*)second;
}

void test_insert_root_of_the_tree(){
    BST tree = createTree(compareNodes);
    int number = 10;
    ASSERT(insertInTree(&tree, &number));
    ASSERT(&number == getRootData(tree));        
}

