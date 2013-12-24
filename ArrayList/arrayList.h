#include "../Iterator/iterator.h"
typedef struct {
        void** base;
        int capacity;
        int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list, void* data);

void* get(ArrayList list, int index);

int remove(ArrayList* list, int index);

Iterator getIterator(ArrayList* list);

void dispose(ArrayList *list);