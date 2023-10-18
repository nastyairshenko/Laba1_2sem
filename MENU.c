#include <stdio.h>
#include <stdlib.h>
#include "MENU.h"

dynamic *where_menu(dynamic *array, RingInfo *ring){
    int value = 0;
    dynamic *val = (dynamic *) malloc (sizeof(dynamic));
    while (value != 4) {
        printf("\n...............................\n");
        printf("1. >= \n");
        printf("2. <= \n");
        printf("3. == \n");
        printf("4. Back \n");
        printf("\n...............................\n");
        while(scanf("%d", &value) != 1){
            scanf("%*[^\n]");
            printf("Incorrect value\n");
        }
        switch (value) {
            case 1:{
                val->size = 1;
                val-> arr = (void **) malloc( val->size * ring->size );
                val->arr[0] = ring->input();
                array = where(array, ring, compare1, val);
                free_array(val, ring);
                return array;
            }
            case 2:{
                val->size = 1;
                val-> arr = (void **) malloc( val->size * ring->size );
                val->arr[0] = ring->input();
                array = where(array,ring,compare2,  val);
                free_array(val, ring);
                return array;
            }
            case 3:{
                val->size = 1;
                val-> arr = (void **) malloc( val->size * ring->size );
                val->arr[0] = ring->input();
                array = where(array,ring,compare3, val);
                free_array(val, ring);
                return array;
            }
            case 4:{
                return array;
            }
        }
    }
    return NULL;
}



dynamic *map_menu(dynamic *array, RingInfo *ring){
    int key = 0;
    dynamic *val = (dynamic *) malloc (sizeof(dynamic));
    while(key != 4) {
        printf("\n...............................\n");
        printf("1. +\n");
        printf("2. -\n");
        printf("3. *\n");
        printf("4. First array");
        printf("\n...............................\n");
        printf("Input value : ");
        while(scanf("%d", &key) != 1){
            scanf("%*[^\n]");
            printf("Try again.\n");
        }
        switch (key) {
            case 1:{
                val->size = 1;
                val-> arr = (void **) malloc(val->size * ring->size);
                val->arr[0] = ring->input();
                array = map(array, ring,  ring->sum, val);
                free_array(val, ring);
                return array;
            }
            case 2:{
                val->size = 1;
                val-> arr = (void **) malloc(val->size * ring->size);
                val->arr[0] = ring->input();
                array = map(array, ring, ring->subtract, val);
                free_array(val, ring);
                return array;
            }
            case 3:{
                val->size = 1;
                val-> arr = (void **) malloc(val->size * ring->size);
                val->arr[0] = ring->input();
                array = map(array, ring, ring->multi, val);
                free_array(val, ring);
                return array;
            }
            case 4:{
                return array;
            }
        }
    }
    return NULL;
}




RingInfo *menu() {
    int value = 0;
    printf("\n\n..........Type..........\n");
    printf("\n 1. Complex\n 2. Int\n 3. Exit\n");
    printf("\n........................\n\nInput value, please : ");
    while ((scanf("%d", &value)) != 1){
        scanf("%*[^\n]");
        printf("Try again!\n");
    }
    switch (value) {
        case 1 : {
            return CreateRing((void *(*)(void *)) complex_define,(void * (*)(void *)) complex_input,(void * (*)(void *)) complex_copy,
                              (void (*)(void *)) complex_output, (int (*)(void *, void *)) complex_compare,(void *(*)(void *, void *)) complex_sum,
                              (void *(*)(void *, void *)) complex_multi,(void * (*)(void *, void *))  complex_subtract,
                              (void (*)(void *)) complex_free_struct, sizeof(void *));
        }
        case 2 : {
            return CreateRing((void *(*)(void *)) int_define, (void * (*)(void *)) int_input,(void * (*)(void *)) int_copy,
                              (void (*)(void *)) int_output, (int (*)(void *, void *)) int_compare,(void *(*)(void *, void *)) int_sum,
                              (void *(*)(void *, void *)) int_multi,(void * (*)(void *, void *))  int_subtract,
                              (void (*)(void *)) int_free_struct, sizeof(void *));
        }
        case 3 : {
            exit(0);
        }
        default : {
            break;
        }
    }
    return NULL;
}


void print_MENU(){
    printf("\n\n.....................MENU.....................\n\n");
    printf("1. Input new array.\n");
    printf("2. Create new ring.\n");
    printf("3. Concat array.\n");
    printf("4. Map.\n");
    printf("5. Where.\n");
    printf("6. Print array.\n");
    printf("7. Exit.\n");
    printf("\n..............................................\n\n");
}


void MENU(){
    RingInfo *ring = menu();
    dynamic *data = input_array(ring);
    print_array(data, ring);
    int value = 0;
    while(value != 7){
        print_MENU();
        printf("Input value. \n>");
        while(scanf("%d", &value) != 1){
            scanf("%*[^\n]");
            printf("Try again\n");
        }
        switch (value) {
            case 1 : {
                free_array(data, ring);
                data = input_array(ring);
                break;
            }
            case 2 : {
                free_array(data, ring);
                free_ring(ring);
                ring = menu();
                data = input_array(ring);
                break;
            }
            case 3 : {
                dynamic *array = input_array(ring);
                printf("Array : \n");
                data = concat(data, array, ring);
                print_array(data, ring);
                printf("\n");
                free(array);
                break;
            }
            case 4 : {
                data = map_menu(data, ring);
                print_array(data, ring);
                break;
            }
            case 5: {
                data = where_menu(data, ring);
                print_array(data, ring);
                break;
            }
            case 6 : {
                print_array(data, ring);
                break;
            }
            case 7 : {
                free_ring(ring);
                free_array(data, ring);
                break;
            }
            default : { break; }
        }
    }
}
