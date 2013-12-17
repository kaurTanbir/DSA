typedef char String[256];
typedef int (*compare)(void* first, void* second);
typedef struct {
    void* data;
    int priority;
}data_specification;

