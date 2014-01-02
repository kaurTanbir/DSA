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
void test_insert_child_to_root(){
	BST tree = createTree(compareNodes);
    int num[2] = {10,20};
    Child_data res;
    insertInTree(&tree, &num[0]);
    ASSERT(&num[0] == getRootData(tree));
    insertInTree(&tree,&num[1]);
    res = getChildData(tree,&num[0]);  
	ASSERT(&num[1] == res.right );
}
