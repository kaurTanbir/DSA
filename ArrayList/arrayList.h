#include "../Iterator/iterator.h"
typedef struct {
        void** base;
        int capacity;
        int length;
} ArrayList;
typedef int (*compare)(void* element1,void *element2);
typedef void ForEach(void* data);

ArrayList createArrayList(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list, void* data);

void* getArrayListData(ArrayList list, int index);

int searchIndex(ArrayList *list, void *searchElement, compare cmpFun);

int removeArrayListData(ArrayList* list, int index);

Iterator getIteratorForArraylist(ArrayList* list);
void iterate(ArrayList list, ForEach* forEach);

void dispose(ArrayList *list);