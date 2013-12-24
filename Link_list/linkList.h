#include "./include/custom_dataType.h"
#include "../Iterator/iterator.h"
DList* create();
Node* createNode(Node *prevAddress, Node *nextAddress);
int insertNode(DList* list,void* data,int index);
int deleteNode(DList* list,int index);
Iterator getIterator(DList *dList);