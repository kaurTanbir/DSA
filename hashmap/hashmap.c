#include "include/linkList.h"
#include "hashmap.h"
#include <stdlib.h>

typedef struct hashNode {
    void* key;
    void* value;
}HashData;

typedef struct {
    void* data;
    int index;
}Matched_Data;
// HashMap map;
//         int i;
//         List *listOfHashObjects;
//         ArrayList listOfBuckets = createArrayList(capacity);
//         map.getHashCode = getHashCode;
//         map.compare = cmp;
//         map.capacity = capacity;
//         map.buckets = calloc(1,sizeof(ArrayList));
//         *(ArrayList*)map.buckets = listOfBuckets;
//         for(i=0;i<capacity;i++)
//                 addInArrayList(map.buckets, create());
//         return map;
HashMap createMap(hash hashGenerator, compare compareKey, int capacity){
	HashMap map;
	int i;
	map.bucket = malloc(sizeof(DList) * capacity);
	for(i = 0; i < capacity ;i++)
		map.bucket[i] = create();
	map.hashGenerator = hashGenerator;
	map.compareKeys = compareKey;
    map.capacity = capacity;
    return map;
}

HashData* createdata(void* key,void* value){
	HashData* data = malloc(sizeof(HashData));
	data->key = key;
	data->value = value;
	return data;
}

DList* getBucket(HashMap* map, void* key){
	DList * list;
	int bucketToInsertIn = map->hashGenerator(key);
	bucketToInsertIn = bucketToInsertIn % 10;
    list = map->bucket[bucketToInsertIn];
    return list;

} 

int put(HashMap* map, void* key, void* value){
	HashData* data;
	DList *list;
    if(map == NULL || key == NULL) return 0;
    list = getBucket(map, key);
    data = createdata(key, value);
    insertNode(list, data, list->length);
    return 1;
}


Matched_Data doesKeyMatch(HashMap map, void* key){
    Matched_Data result = {NULL,-1};
 	Iterator it;
    HashData *currentElement;
	DList *list = getBucket(&map, key);
    it = getIterator(list);
    while(it.hasNext(&it)){
        currentElement = it.next(&it);
        if(map.compareKeys(currentElement->key, key)){
            result.data = currentElement->value;
            result.index = it.position - 1;
        }
    }
    return result;
}

void* get(HashMap map , void* key){
    Matched_Data matched_element = doesKeyMatch(map, key);
    if(matched_element.data == NULL)
    	return NULL; 
    return matched_element.data;
}
int remove(HashMap* map, void* key){
    Matched_Data elementFound ;
    DList *list;
    if(key == NULL || map == NULL) return 0;
    elementFound = doesKeyMatch(*map, key);
	list = getBucket(map, key);
    return deleteNode(list, elementFound.index);
};

