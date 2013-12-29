#include "b_sort.h"
#include <stdlib.h>
#include <memory.h>
void swapElement(void* element1 ,void* element2 ,int elementSize ,Compare compare){
    void* temp = calloc(1, elementSize);
        if(0 < compare(element1,element2)){
            memcpy(temp , element2 , elementSize);
            memcpy(element2, element1, elementSize);
            memcpy(element1, temp, elementSize);
        }
}


void sort(void* elements, int numberOfElements, int elementSize,Compare compareFunc) {
    int i, j;
    void* elementToCompare;
    void* nextElement;
    int comparisonResult;
    for (i = 1; i < numberOfElements; i++) {
        for (j = 0; j < numberOfElements - i; j++) {
            elementToCompare = elements + j * elementSize;
            nextElement = elements + (j + 1) * elementSize;
			swapElement(elementToCompare ,nextElement ,elementSize ,compareFunc);
        }
    }
}