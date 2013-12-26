#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

int areNodesEqual(void* nodeData, void* parentData){
    return (*(int*)nodeData == *(int*)parentData);
}

//--------------------------------------create and insert-------------------------------------
void test_inserts_a_root_node_into_tree(){
    Tree tree = createTree(areNodesEqual);
    int number = 12;
    Iterator it;
    ASSERT(insertTreeNode(&tree, NULL, &number));
    it = getChildren(tree, &number);
    ASSERT(NULL == it.next(&it));

}
void test_inserts_a_child_of_root_into_tree(){
    Tree tree = createTree(areNodesEqual);
    int nums[2] = {12,25};
    Iterator it;
    ASSERT(insertTreeNode(&tree, NULL, &nums[0]));
    ASSERT(insertTreeNode(&tree, &nums[0], &nums[1]));
    it = getChildren(tree, &nums[0]);
    ASSERT(25 == *(int*)it.next(&it));
}

void test_inserts_children_to_different_level(){
    Tree tree = createTree(areNodesEqual);
    int nums[5] = {10,20,30,40,50};
    Iterator it;
    insertTreeNode(&tree, NULL, &nums[0]);
    insertTreeNode(&tree, &nums[0], &nums[1]);
    insertTreeNode(&tree, &nums[0], &nums[2]);
    ASSERT(insertTreeNode(&tree, &nums[1], &nums[3]));
    ASSERT(insertTreeNode(&tree, &nums[2], &nums[4]));
    it = getChildren(tree, &nums[1]);
    ASSERT(40 == *(int*)it.next(&it));
    ASSERT(NULL == it.next(&it));
    it = getChildren(tree, &nums[2]);
    ASSERT(50 == *(int*)it.next(&it));
    ASSERT(NULL == it.next(&it));
}
void test_gives_iterator_to_check_childrens_data_of_a_given_parent(){
    Tree tree = createTree(areNodesEqual);
    int nums[3] = {12,25,14};
    Iterator it;
    ASSERT(insertTreeNode(&tree, NULL, &nums[0]));
    ASSERT(insertTreeNode(&tree, &nums[0], &nums[1]));
    ASSERT(insertTreeNode(&tree, &nums[0], &nums[2]));
    it = getChildren(tree, &nums[0]);
    ASSERT(25 == *(int*)it.next(&it));
    ASSERT(14 == *(int*)it.next(&it));
}
//------------------------------search---------------------------------------------------
void test_searchs_the_given_data_in_list(){
    Tree tree = createTree(areNodesEqual);
    int num1 = 1,num2=2;
    insertTreeNode(&tree, NULL, &num1);
    insertTreeNode(&tree, &num1, &num2);
    ASSERT(searchInTree(tree, &num1));
    ASSERT(searchInTree(tree, &num2));
}
void test_search_fails_when_data_is_not_present(){
    Tree tree = createTree(areNodesEqual);
    int num1 = 1;
    ASSERT(0 == searchInTree(tree, &num1));
}
//-----------------------------delete---------------------------------------------------

void test_deletes_the_root_from_the_tree(){
    Tree tree = createTree(areNodesEqual);
    int number = 12;
    insertTreeNode(&tree, NULL, &number);
    ASSERT(searchInTree(tree, &number));
    ASSERT(1 == deleteFromTree(&tree, &number));
}

void test_deletion_failed_when_data_is_not_in_tree(){
    Tree tree = createTree(areNodesEqual);
    int number = 12;
    ASSERT(0 == deleteFromTree(&tree, &number));
}


void test_deletes_child_of_root(){
    Tree tree = createTree(areNodesEqual);
    int nums[3] = {1,2,3};
    insertTreeNode(&tree, NULL, &nums[0]);
    insertTreeNode(&tree, &nums[0], &nums[1]);
    insertTreeNode(&tree, &nums[0], &nums[2]);
    ASSERT(1 == searchInTree(tree, &nums[1]));
    ASSERT(1 == deleteFromTree(&tree, &nums[1]));
    ASSERT(0 == searchInTree(tree, &nums[1]));
}


void test_does_not_delete_node_with_children(){
    Tree tree = createTree(areNodesEqual);
    int nums[4] ={1,2,3,4};
    insertTreeNode(&tree, NULL, &nums[0]);
    insertTreeNode(&tree, &nums[0], &nums[1]);
    insertTreeNode(&tree, &nums[0], &nums[2]);
    insertTreeNode(&tree, &nums[2], &nums[3]);

    ASSERT(1 == searchInTree(tree, &nums[2]));
    ASSERT(0 == deleteFromTree(&tree, &nums[2]));

}

