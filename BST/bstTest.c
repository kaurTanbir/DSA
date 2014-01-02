#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

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
void test_insert_leftchild_and_rightchild_to_root(){
    BST tree = createTree(compareNodes);
    int num[3] = {10,20,5};
    Child_data res;
    insertInTree(&tree, &num[0]);
    insertInTree(&tree,&num[1]);
    insertInTree(&tree,&num[2]);
    res = getChildData(tree,&num[0]);  
    ASSERT(&num[1] == res.right );
    ASSERT(&num[2] == res.left );
}
void test_does_not_insert_duplicate_value_in_tree(){
    BST tree = createTree(compareNodes);
    int num[2] = {10,10};
    Child_data res;
    insertInTree(&tree, &num[0]);
    ASSERT(&num[0] == getRootData(tree));
    ASSERT( 0 == insertInTree(&tree,&num[1])) ;
}
void test_insert_multiple_node_to_tree(){
    BST tree = createTree(compareNodes);
    int num[6] = {10,20,5,7,25,21};
    Child_data res;

    insertInTree(&tree, &num[0]);
    insertInTree(&tree,&num[1]);
    insertInTree(&tree,&num[2]);
    insertInTree(&tree,&num[3]);
    insertInTree(&tree,&num[4]);
    insertInTree(&tree,&num[5]);
    
    res = getChildData(tree,&num[4]);  
    ASSERT(&num[5] == res.left );
    ASSERT(NULL == res.right );
}