#include "./include/iterator.h"

typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
typedef struct {
    void **bucket;
    hash hashGenerator;
    compare cmp;
} HashMap;

HashMap createMap(hash hashGenerator, compare compareKey);
int put(HashMap* map, void* key, void* value);
