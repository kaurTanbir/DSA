#include "./include/iterator.h"

typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
typedef struct {
    void **bucket;
    int capacity;
    hash hashGenerator;
    compare compareKeys;
} HashMap;

HashMap createMap(hash hashGenerator, compare compareKey,int capacity);
int putHashData(HashMap* map, void* key, void* value);
void* getHashValue(HashMap *map, void* key);
int removeHashValue(HashMap* map,void* data);
Iterator getAllKeys(HashMap map);
void disposeMap(HashMap* map);