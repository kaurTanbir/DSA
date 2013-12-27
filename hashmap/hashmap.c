#include "include/linkList.h"
#include "hashmap.h"
#include <stdlib.h>

typedef struct hashNode {
    void* key;
    void* value;
}HashData;

HashMap createMap(hash hashGenerator, compare compareKey){
	HashMap map;
	map.bucket = malloc(sizeof(DList) * 10);
	map.hashGenerator = hashGenerator;
	map.cmp = compareKey;
    return map;
}

HashData* createdata(void* key,void* value){
	HashData* data = malloc(sizeof(HashData));
	data->key = (int*)key;
	data->value = (int*)value;
	return data;
}
int put(HashMap* map, void* key, void* value){
	HashData* data;
	int bucketToInsertIn = map->hashGenerator(key);
    DList *list = map->bucket[bucketToInsertIn];
    data = createdata(key,value);
    insertNode(list, data, list->length);
    return 1;
}
