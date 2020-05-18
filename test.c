#include "queue.h"

#include <stdio.h>
#include <pthread.h>

queue_type queue;

void * producer_thread(void * args){
    for(int i = 0; i < 100000; ++i){
        push(&queue, &i);
    }
    return NULL;
}

void * consumer_thread(void * args){
    int element;
    while(1){
        pop(&queue, &element);
        printf("%d\n", element);
    }
    return NULL;
}

int main(){
    init_queue(&queue);
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, (void *)producer_thread, NULL)){
        printf("Fail to create the producer thread.\n");
        return 1;
    }
    if(pthread_create(&t2, NULL, (void *)consumer_thread, NULL)){
        printf("Fail to create the consumer thread.\n");
        return 1;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}