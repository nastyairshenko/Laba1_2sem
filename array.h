#ifndef LABA1_2SEM_ARRAY_H
#define LABA1_2SEM_ARRAY_H

#include "RingInfo.h"

typedef int(*Func)(void* , void*, RingInfo*);


typedef struct dynamic{
    size_t size;
    void **arr;
}dynamic;


typedef void* (*mapfun)(void* , void*);
dynamic *create_array(RingInfo *ring, int len);
dynamic *input_array(RingInfo *ring);
dynamic *concat(dynamic *arr1, dynamic *arr2, RingInfo *ring);
void print_array(dynamic *data, RingInfo *ring);
void free_array(dynamic *array, RingInfo *ring);
dynamic* map(dynamic *array, RingInfo *ring, mapfun func, dynamic *val);
dynamic *where(dynamic *Array, RingInfo *ring, Func Function, dynamic *val);
int compare1(void* thing , void *key, RingInfo *ring);
int compare2(void* thing, void* key, RingInfo *ring);
int compare3(void* thing, void* key, RingInfo *ring);


#endif //LABA1_2SEM_ARRAY_H
