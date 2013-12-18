typedef struct {
    void** base;
    int top;
    int length;
}Stack;

Stack* create(int length);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* peek(Stack stack);