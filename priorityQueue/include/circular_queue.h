typedef struct{
    void* base;
    int length;
    int elementSize;
    int rear;
    int front;
}Queue;

int enqueue(Queue* queue, void* element);
Queue* create(int elementSize,int length);
void* dequeue(Queue* queue);
int queueIsEmpty(Queue* queue);
int queueIsFull(Queue* queue);