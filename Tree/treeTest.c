#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include "../Iterator/iterator.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areNodesEqual(void* childData, void* parentData){
        return (*(int*)childData == *(int*)parentData);
}

void test_inserts_a_root_node_into_tree(){
        Tree tree = createTree(areNodesEqual);
        int number = 12;
        Iterator it;
        //DList *list = create();
        ASSERT(insertInTree(&tree, NULL, &number));
        it = getChildren(tree, &number);
        ASSERT(NULL == it.next(&it));
}
