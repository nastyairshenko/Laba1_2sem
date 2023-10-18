#include<stdlib.h>
#include"RingInfo.h"


struct RingInfo* CreateRing(void *(*define)(void *), void *(*input)(),  void * (*copy)(void *), void (*output)(void *), int (*compare)(void *, void *),
        void *(*sum)(void*, void*), void * (*multi)(void *, void *), void *(*subtract)(void *, void *), void (*free_struct)(void*), size_t size){

    RingInfo *ring = (RingInfo *) malloc(sizeof(RingInfo));
    ring -> define = define;
    ring -> sum = sum;
    ring -> multi = multi;
    ring -> copy = copy;
    ring -> compare = compare;
    ring -> input = input;
    ring -> subtract = subtract;
    ring -> output = output;
    ring -> free_struct = free_struct;
    ring -> size = size;
    return ring;
}

void free_ring(RingInfo *ring){
    free(ring);
}