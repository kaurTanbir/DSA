typedef struct {
        void** base;
        int top;
        int length;
}Stack;

typedef char String[256];

Stack* create(int length);

int push(Stack* stack,void* element);

void* pop(Stack* stack);
void* peek(Stack* stack);

int isEmpty(Stack* stack);
int isFull(Stack* stack);