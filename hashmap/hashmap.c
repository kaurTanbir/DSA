#include "include/linkList.h"
#include "hashmap.h"
#include <stdlib.h>

typedef struct hashNode {
    void* key;
    void* value;
}HashData;

HashMap createMap(hash hashGenerator, compare compareKey){
	HashMap map;
	int i;
	map.bucket = malloc(sizeof(DList) * 10);
	for(i = 0;i<10 ;i++)
		map.bucket[i] = create();
	map.hashGenerator = hashGenerator;
	map.cmp = compareKey;
    return map;
}

HashData* createdata(void* key,void* value){
	HashData* data = malloc(sizeof(HashData));
	data->key = key;
	data->value = value;
	return data;
}
int put(HashMap* map, void* key, void* value){
	HashData* data;
	DList * list;
	int bucketToInsertIn = map->hashGenerator(key);
	bucketToInsertIn = bucketToInsertIn % 10;
    list = map->bucket[bucketToInsertIn];
    data = createdata(key, value);
    insertNode(list, data, list->length);
    return 1;
}
