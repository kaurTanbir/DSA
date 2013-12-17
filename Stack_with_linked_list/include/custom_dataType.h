typedef char String[256];
typedef struct node{
        struct node* next;
        struct node* prev;
        void* data;
}Node;

typedef struct list{
        Node* head;
        int length;
}DList;
