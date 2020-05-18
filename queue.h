#define MAX_QUEUE_SIZE 5000

typedef int element_type;

//ring buffer
//one slot is intentially set aside to mark if the buffer is full
typedef struct{
    volatile element_type data[MAX_QUEUE_SIZE + 1];
    volatile int head;
    volatile int tail;
} queue_type;

extern void init_queue(queue_type * queue);

//block until the element is pushed into the queue
extern void push(queue_type * queue, const element_type* element);

//block until an element is popped out of the queue
extern void pop(queue_type * queue, element_type* element);