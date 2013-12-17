#include "schedular.h"
#include <stdlib.h>
#include <string.h>
Scheduler* create(){
    Scheduler *queue = calloc(sizeof(Scheduler),1);
    return queue;
}
int insertAtStart(Scheduler *queue, Process *process){
    if(queue->head == NULL)
        process->next = NULL;
    else process->next = queue->head;
    queue->head = process;
    queue->length++;
    return queue->length;        
}
int insertProcessInBetween(Scheduler *queue,Process *previous,Process *process ,Process *next){
    previous->next = process;
    process->next = next;
    return ++queue->length;
}
int insertProcess(Scheduler *queue, Process *process){
    Process *previous,*next,*temp;int i = 0;
    temp = queue->head;
    if(queue->length == 0)                
        return insertAtStart(queue, process);
    if(process->processPriority < temp->processPriority)
        return insertAtStart(queue, process);
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->processPriority < next->processPriority)
            return insertProcessInBetween(queue ,previous, process ,next);
    };
    temp->next = process;
    process->next = NULL;
    return ++queue->length;
}
int removeProcessInBetween(Scheduler *queue,Process *previous ,Process *next){
    previous->next = next->next;
    return --queue->length;
}

int removeProcess(Scheduler *queue){
    Process *temp,*previous,*next;int i = 0;
    temp = queue->head;

    if(queue->length == 1){
        if(temp->processTime == 0)
            queue->head = NULL;
        return --queue->length;
}
	if(temp->processTime == 0)
        queue->head = temp->next;
	for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->processTime == 0)
            return removeProcessInBetween(queue ,previous ,next);
    }
    if(NULL == temp->next){
        previous->next = NULL;
        return --queue->length;
    };
    return 0;
}
void dispose(Scheduler *queue){
    free(queue);
}