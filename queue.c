#include "queue.h"

//ring buffer
//one slot in the array is intentionally set aside to mark if the queue is full
/*
typedef struct{
    volatile element_type data[MAX_QUEUE_SIZE + 1];
    volatile int head;
    volatile int tail;
} queue_type;
*/
//head指向刚刚插入的位于对手的元素
//tail指向紧靠位于队尾的待取的元素的左边的空位

extern void init_queue(queue_type * queue){
    queue->head = 0;
    queue->tail = 0;
}

//block until the element is pushed into the queue
extern void push(queue_type * queue, const element_type* element){
    int head = queue->head;
    //spin when the queue is full
    while(1){
            if(queue->head != (head + 1) % MAX_QUEUE_SIZE)
                break;
    }
    //push
    queue->data[head + 1] = *element;
    queue->head = (head + 1)%(MAX_QUEUE_SIZE + 1); 
}

//block until an element is popped out of the queue
extern void pop(queue_type * queue, element_type* element){
    int tail = queue->tail;
    while(1){
        if(queue->head != tail)
            break;
    }
    //pop
    *element = queue->data[tail+1];
    queue->tail = (tail + 1)%(MAX_QUEUE_SIZE + 1);
}