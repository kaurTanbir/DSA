#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeysEqual(void* key1 , void* key2 ){
    return *(int*)key1 - *(int*)key2;
}
int hashGenerator(void *key){
    return *(int*)key;
};

typedef struct{
    int key;
    char value[20];
} Intern;
Intern tanbirka = {15450,"tanbirka"};

void test_add_an_element_to_hashmap(){
	int res;
    HashMap map = createMap(hashGenerator, areKeysEqual);
    res = put(&map, &tanbirka.key, &tanbirka.value);
    ASSERT(1 == res);
}
