#include "schedular.h"
#include <string.h>
#include <stdlib.h>
PS* create_process(PS* process, int priority, char *name, int Ptime){
	process->Ptime = Ptime;
	process->priority= priority;
	strcpy(process->name,name);
	return process;
}
int compareFunc(const void* a,const void* b){
	return ((PS*)b)->priority - ((PS*)a)->priority;
}

void sortProcess(PS* process){
	qsort(process, sizeof(int),sizeof(PS),compareFunc);
}