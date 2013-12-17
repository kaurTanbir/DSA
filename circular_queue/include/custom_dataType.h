typedef char String[256];
typedef struct{
    void* base;
    int length;
    int elementSize;
    int rear;
    int front;
}Queue;