typedef struct{
        int running;
        int wait;
        int end;
} Status;
typedef struct process{
        char processName[256];
        int processTime;
        Status processStatus;
        int processPriority;
        struct process *next;
} Process;

typedef struct{
        Process *head;
        int length;
} Scheduler;

Scheduler* create();
int insertProcess(Scheduler *queue,Process *process);
int removeProcess(Scheduler *queue);
void dispose(Scheduler *queue);