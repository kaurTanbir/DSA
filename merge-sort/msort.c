#include "msort.h"
#include <stdlib.h>
void merge(void **destination,  void** leftArr, void** rightArr, int leftLength,
                         int rightLength, Compare* compare){
    int i = 0,j = 0,k = 0;
    for(; i < leftLength && j < rightLength;){
        if(compare(leftArr[i], rightArr[j]) < 0){
            destination[k] = leftArr[i];
            i++;
        }
        else{
            destination[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < leftLength){
        destination[k] = leftArr[i];
        i++;k++;
    }
    while(j < rightLength){
        destination[k] = rightArr[i];
        j++;k++;
    }
}

void sort(void** base, int noOfElements, Compare* comparator){
    int mid = noOfElements/2,
    	leftLength = mid,
    	rightLength = noOfElements - mid,
    	i;

    void** leftArr = calloc(leftLength, sizeof(void*));
    void** rightArr = calloc(rightLength, sizeof(void*));

    if(noOfElements <= 1) return;

    for(i = 0; i < leftLength ;i++)
        leftArr[i] = base[i];
    for(i = mid; i < noOfElements ;i++)
        rightArr[i-mid] = base[i];

    sort(leftArr, leftLength, comparator);
    sort(rightArr, rightLength, comparator);

    merge(base, leftArr, rightArr, leftLength, rightLength, comparator);

    free(leftArr);
    free(rightArr);
}