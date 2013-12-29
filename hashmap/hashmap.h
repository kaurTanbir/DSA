#include "./include/iterator.h"

typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
typedef struct {
    void **bucket;
    hash hashGenerator;
    compare compareKeys;
} HashMap;

HashMap createMap(hash hashGenerator, compare compareKey);
int put(HashMap* map, void* key, void* value);
void* get(HashMap map, void* key);
int remove(HashMap* map,void* data);
