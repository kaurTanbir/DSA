#include "bsearch.h"
#include <math.h>

void* binarySearch( void* key, void* base, size_t totalElements, size_t elementSize, CompareFunc *compare){
    int start = 0,
    	end = totalElements - 1,
    	result,mid;
    void* midElement ;
    while(start<=end){
        mid = (start + end)/2;
        midElement =  base + (mid * elementSize);
        result = compare(key,midElement );
        if(!result)
            return midElement;
        if(result < 0)
            end = mid-1;
        else
            start = mid + 1;
    }
    return NULL;
}