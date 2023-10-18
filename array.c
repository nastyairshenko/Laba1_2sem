#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "RingInfo.h"

int compare1(void* thing , void *key, RingInfo *ring){
    if (ring->compare(thing, key) >= 0) { return 1; }
    else { return 0; }
}

int compare2(void* thing, void* key, RingInfo *ring){
    if (ring->compare(thing, key) <= 0) { return 1; }
    else { return 0;}
}

int compare3(void* thing, void* key, RingInfo *ring){
    if (ring->compare(thing, key) == 0) { return 1; }
    else { return 0; }
}

dynamic *create_array(RingInfo *ring, int len){
    dynamic *array = (dynamic *) malloc( sizeof(dynamic));
    array -> size = len;
    array -> arr =(void **) malloc((array -> size) * (ring -> size));
    return array;
}


dynamic *input_array(RingInfo *ring){
    printf("Please, input len of array : ");
    int len = 0;
    while (scanf("%d", &len) != 1 ){
        scanf("%*[^\n]");
        printf("Try again.");
    }
    printf("\n");
    dynamic *data = create_array(ring, len);
    printf("Input your array. \n");
    for(size_t i = 0; i < data->size; i++){
        data -> arr[i]  = ring -> input();
    }
    printf("\n");
    return data;
}


void print_array(dynamic *data, RingInfo *ring){
    for(int i = 0; i < data->size; i++){
        ring -> output(data->arr[i]);
    }
}


dynamic *concat(dynamic *arr1, dynamic *arr2, RingInfo *ring){
    arr1->size += arr2->size;
    arr1->arr = (void **) realloc(arr1->arr, arr1->size * ring->size);
    size_t k = 0;
        for(size_t i = arr1->size - arr2->size; i<arr1->size; i++){
            arr1->arr[i] = ring->copy(arr2->arr[k]);
            k++;
        }
    return arr1;
}


dynamic *where(dynamic *array, RingInfo *ring, Func Function, dynamic *val){
    dynamic *res = (dynamic*) malloc(sizeof(dynamic));
    res->size = 0;
    res->arr = (void **) malloc(array->size * ring->size);
    int j = 0;
    for (int i = 0; i < array->size; ++i) {
        if(Function(array->arr[i], val->arr[0], ring) == 1){
            res->arr[j] = array->arr[i];
            res->size++;
            j++;
        }
        else{
            ring->free_struct(array->arr[i]);
        }
    }
    res->arr = (void **) realloc(res->arr, res->size * ring->size);
    free(array);
    return res;
}


dynamic* map(dynamic *array, RingInfo *ring, mapfun func, dynamic *val){
    for (int i = 0; i < array->size; ++i){
        array->arr[i] = func(array->arr[i], val->arr[0]);
    }
    return array;
}


void free_array(dynamic *array, RingInfo *ring){
    ring->free_struct(array);
}
