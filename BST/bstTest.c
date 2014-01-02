#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct{
    int acc_no;
    double balance;
}Account;
int compareNodes(void* first, void* second){
    return *(int*)first - *(int*)second;
}
int compareAccounts(void* first, void* second){
    Account* firstAccount = (Account*)first;
    Account* secondAccount = (Account*)second;
    return firstAccount->acc_no - secondAccount->acc_no;
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
void test_insert_multiple_node_to__left_of_tree(){
    BST tree = createTree(compareNodes);
    int num[5] = {20,15,10,5,0};
    Child_data res;

    insertInTree(&tree, &num[0]);
    insertInTree(&tree,&num[1]);
    insertInTree(&tree,&num[2]);
    insertInTree(&tree,&num[3]);
    insertInTree(&tree,&num[4]);
    
    res = getChildData(tree,&num[3]);  
    ASSERT(&num[4] == res.left );
    ASSERT(NULL == res.right );
}
void test_insert_multiple_node_to__right_of_tree(){
    BST tree = createTree(compareNodes);
    int num[5] = {20,15,10,5,0};
    Child_data res;

    insertInTree(&tree,&num[4]);
    insertInTree(&tree,&num[3]);
    insertInTree(&tree,&num[2]);
    insertInTree(&tree,&num[1]);
    insertInTree(&tree, &num[0]);
    
    res = getChildData(tree,&num[1]);  
    ASSERT(&num[0] == res.right );
    ASSERT(NULL == res.left );
}
void test_insert_struct_as_root_of_the_tree(){
    BST tree = createTree(compareAccounts);
    Account acc1 = {1,100};
    ASSERT(insertInTree(&tree, &acc1));
    ASSERT(&acc1 == getRootData(tree));        
}
void test_insert_struct_as_child_to_root(){
    BST tree = createTree(compareAccounts);
    Child_data res;
    Account acc1 = {1,100},
            acc2 = {2,10};
    ASSERT(insertInTree(&tree, &acc1));
    ASSERT(&acc1 == getRootData(tree)); 
    insertInTree(&tree,&acc2);
    res = getChildData(tree,&acc1);  
    ASSERT(&acc2 == res.right );
}