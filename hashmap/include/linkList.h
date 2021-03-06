#include "./iterator.h"
typedef struct node{
    struct node* next;
    struct node* prev;
    void* data;
}Node;

typedef struct list{
    Node* head;
    int length;
}DList;

DList* create();
Node* createNode(Node *prevAddress, Node *nextAddress);
int insertNode(DList* list,void* data,int index);
int deleteNode(DList* list,int index);
Iterator getIterator(DList *dList);
void dispose(DList *dList);
