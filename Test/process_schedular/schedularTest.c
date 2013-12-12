#include "testUtils.h"
#include "schedular.h"
#include <string.h>
#include <stdlib.h>

	Queue *queue;
	PS* process;
 
void test_1_create_a_process(){
	String one = "one";
	process = create_process(process,1, one, 20);
	ASSERT(20 == process->Ptime);
	ASSERT(1 == process->priority);
	ASSERT(strcmp("one",process->name) == 0);
}
void test_2_inserts_an_process_in_queue(){
	String one = "one";
    queue = create(sizeof(PS), 3);
	process = create_process(process,1, one, 20);
    enqueue(queue,&process);
    ASSERT(1 == queue->length);
}
