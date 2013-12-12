#include "linkList.h"
#include <stdlib.h>
DList* create(){
        DList* list;
        list = (DList*)malloc(sizeof(DList));
        list->head = NULL;
        list->length = 0;
        return list;
};

Node* createNode(Node *prevAddress, Node *nextAddress){
           Node *element = malloc(sizeof(Node));
    element->prev = prevAddress;
    element->next = nextAddress;
    return element;
}
int insertAtBegining(Node* newNode,Node* head,DList* list,void* data){
    newNode = createNode(NULL, NULL);
    if(NULL != head){
        newNode->next = head;
        head->prev = newNode;
    }
    list->head = newNode;
    newNode->data = data;
    list->length++;
    return 1;
}
int insertAtLast(Node* newNode,Node* head,DList* list,void* data){
    newNode = createNode(head, NULL);
    head->next = newNode;
    newNode->data = data;
    list->length++;
    return 1;
}
int insertAtSpecificIndex(Node* newNode,Node* head,DList* list,void* data){
    newNode = createNode(head->prev, head);        
    head->prev->next = newNode;
    newNode->data = data;
    list->length++;
    return 1;
}
int insertNode(DList *list, void *data, int index){
    Node *head,*newNode;
    int i;
    if(index <= -1 || index > list->length)
        return 0;
    head = list->head;
    for (i = 0; i < index ; ++i){
        if(head->next != NULL)
            head = head->next;
    }
    if(index == 0) 
        return insertAtBegining(newNode,head,list,data);                             
    if(index == list->length)
        return insertAtLast(newNode,head,list,data);
    return insertAtSpecificIndex(newNode,head,list,data);
};
int deleteFirstElement(DList *list,Node* head){
    list->head = list->head->next;
    free(head);
    list->length--;
    return 1;
}
int deleteLastElement(DList *list,Node* head){
    head->prev->next = NULL;
    free(head);
    list->length--;
    return 1;
}
int deleteAtGivenIndex(DList *list,Node* head){
    head->prev->next = head->next;
    head->next->prev = head->prev;
    free(head);
    list->length--;
    return 1;
}
int deleteNode(DList* list,int index){
    int i;
    Node *head, *deletedNode;
    if(index <= -1 || index >= list->length)
        return 0;
    head = list->head;
    for(i=0;i<index;i++){
        head = head->next;
    }
    if(i==0)
        return deleteFirstElement(list,head);
    if(i==list->length-1)
        return deleteLastElement(list,head);
    return deleteAtGivenIndex(list,head);            
};
