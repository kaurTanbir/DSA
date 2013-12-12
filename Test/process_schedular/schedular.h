#include "../queue/circular_queue/circular_queue.h"

typedef struct{
	int priority;
	String name;
	int Ptime;
}PS;

PS* create_process(PS* process, int priority,String name,int Ptime);
PS* sortByPriority(PS* process);