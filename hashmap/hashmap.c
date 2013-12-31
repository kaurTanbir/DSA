#include "include/linkList.h"
#include "hashmap.h"
#include <stdlib.h>

typedef struct {
    void* key;
    void* value;
}HashData;

typedef struct {
    void* data;
    int index;
}Matched_Data;

void rehash(HashMap* map);


void createBuckets(HashMap map,int capacity){
    int i;
    for(i = 0; i < capacity ;i++)
        map.bucket[i] = create();
}

HashMap createMap(hash hashGenerator, compare compareKey, int capacity){
	HashMap map;
    map.bucket = malloc(sizeof(DList) * capacity);
    createBuckets(map,capacity);
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

void rehashIfNeeded(HashMap* map){
    Iterator bucket = getIterator((DList*)map->bucket);
    HashData* data;
    int i = 1;
    while(bucket.hasNext(&bucket)){
        data = (HashData*)bucket.next(&bucket);
        if(i > 2){
            rehash(map);
            return;            
        }
        i++;
    }
}
int putHashData(HashMap* map, void* key, void* value){
	HashData* data;
	DList *list;
    if(map == NULL || key == NULL) return 0;
    list = getBucket(map, key);
    data = createdata(key, value);
    rehashIfNeeded(map);
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

void* getHashValue(HashMap *map , void* key){
    Matched_Data matched_element;
    if(map == NULL || key == NULL) return NULL;
    matched_element = doesKeyMatch(*map, key);
    if(matched_element.data == NULL)
    	return NULL; 
    return matched_element.data;
}

int removeHashValue(HashMap* map, void* key){
    Matched_Data elementFound ;
    DList *list;
    if(key == NULL || map == NULL) return 0;
    elementFound = doesKeyMatch(*map, key);
	list = getBucket(map, key);
    return deleteNode(list, elementFound.index);
};


void *getNextKey(Iterator *it){
    HashData *map;
    Iterator ListIterator = getIterator(it->list);
    ListIterator.position = it->position;
    map = ListIterator.next(&ListIterator);
    it->position++;
    if(map) return map->key;
    return NULL;
};

Iterator getAllKeys(HashMap map){
    int i;
    Iterator it, listIt;
    DList *listOfHashData = create();
    for(i = 0; i < map.capacity; i++){
        listIt = getIterator((DList*)map.bucket);
        while(listIt.hasNext(&listIt))
            insertNode(listOfHashData,listIt.next(&listIt),0);
    }
    it = getIterator(listOfHashData);
    it.next = getNextKey;
    return it;
};


void collectAllKeys(HashMap* hash, DList* keysList){
    Iterator bucketList = getIterator((DList*)hash->bucket);
    Iterator linkList;
    HashData* data;
    while(bucketList.hasNext(&bucketList)){
        data = bucketList.next(&bucketList);
        linkList = getIterator(data->value);
        while(linkList.hasNext(&linkList)){
            insertNode(keysList, linkList.next(&linkList), keysList->length);
        }
    }
}

void resetHash(HashMap* hash, DList* keyList){
    Iterator list = getIterator(keyList);
    HashData* element;
    while(list.hasNext(&list)){
        element = list.next(&list);
        removeHashValue(hash, element->key);
    }
}

void increaseBucket(HashMap* map){
    int capacity = map->capacity *2;
    createBuckets(*map,capacity);
}

void reinsertEachElement(HashMap* map, DList* keysList){
    Iterator itList = getIterator(keysList);
    HashData* element;
    while(itList.hasNext(&itList)){
        element = itList.next(&itList);
        putHashData(map, element->key, element->value);
    }
}

void rehash(HashMap* map){
    DList *keysList = create();
    collectAllKeys(map, keysList);
    resetHash(map, keysList);
    increaseBucket(map);
    reinsertEachElement(map, keysList);
    dispose(keysList);
}

void disposeMap(HashMap *map){
    int i;
    DList *listOfHashObjects;
    for(i=0;i<map->capacity;i++){
        listOfHashObjects = (DList*)map->bucket[i];
        dispose(listOfHashObjects);
    };
    free(map->bucket);
};
