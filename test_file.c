#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_int.h"
#include "my_complex.h"
#include "RingInfo.h"
#include "array.h"


void test_complex(){

    type_complex *test1 = complex_define(484.91, 636.64);
    type_complex *test2 = complex_define(19.79, 74.12);
    type_complex *test3 = complex_define(320.23, 820.34);
    type_complex *test4 = complex_define(-935.95, -745.99);
    type_complex *test5 = complex_define(-120.36, 382.73);
    type_complex *test6 = complex_define(703.41, -101.25);
    assert(test1->Re == 484.91);
    assert(test1->Im == 636.64);
    assert(test2->Re == 19.79);
    assert(test2->Im == 74.12);
    assert(test3->Re == 320.23);
    assert(test3->Im == 820.34);
    assert(test4->Re == -935.95);
    assert(test4->Im == -745.99);
    assert(test5->Re == -120.36);
    assert(test5->Im == 382.73);
    assert(test6->Re == 703.41);
    assert(test6->Im == -101.25);

    assert(complex_compare(test1,test2) == 1);
    assert(complex_compare(test3,test4) == -1);
    assert(complex_compare(test5,test6) == -1);

    test2 = complex_sum(test1,test2);
    test4 = complex_sum(test3,test4);
    test6 = complex_sum(test5,test6);
    assert(test2->Re == 504.7);
    assert(test2->Im  == 710.76);
    assert(test4->Re  == -615.72);
    assert(test4->Im  == 74.35);
    assert(test6->Re  == 583.05);
    assert(test6->Im  == 281.48);

    test2 = complex_subtract(test1,test2);
    test4 = complex_subtract(test3,test4);
    test6 = complex_subtract(test5,test6);
    assert(test2->Re == -19.79);
    assert(test2->Im == -74.12);
    assert(test4->Re == 935.95);
    assert(test4->Im == 745.99);
    assert(test6->Re == -703.41);
    assert(test6->Im == 101.25);

    test2 = complex_multi(test1,test2);
    test4 = complex_multi(test3,test4);
    test6 = complex_multi(test5,test6);
    assert(test2->Re == -9596.3689);
    assert(test2->Im == -47187.7568);
    assert(test4->Re == 299719.2685);
    assert(test4->Im == 611965.4366);
    assert(test6->Re == 84662.4276);
    assert(test6->Im == 38751.4125);

    complex_free_struct(test1);
    complex_free_struct(test2);
    complex_free_struct(test3);
    complex_free_struct(test4);
    complex_free_struct(test5);
    complex_free_struct(test6);
    printf("Complex test was passed successfully.\n");
}



void test_int(){

    type_int *test1 = int_define(43);
    type_int *test2 = int_define(12);
    type_int *test3 = int_define(57);
    type_int *test4 = int_define(-97);
    type_int *test5 = int_define(19);
    type_int *test6 = int_define(55);
    assert(test1->digit == 43);
    assert(test2->digit == 12);
    assert(test3->digit == 57);
    assert(test4->digit == -97);
    assert(test5->digit == 19);
    assert(test6->digit == 55);

    assert(int_compare(test1,test2) == 1);
    assert(int_compare(test3,test4) == 1);
    assert(int_compare(test5,test6) == -1);

    test2 = int_sum(test1,test2);
    test4 = int_sum(test3,test4);
    test6 = int_sum(test5,test6);
    assert(test2->digit == 55);
    assert(test4->digit == -40);
    assert(test6->digit == 74);

    test2 = int_subtract(test1,test2);
    test4 = int_subtract(test3,test4);
    test6 = int_subtract(test5,test6);
    assert(test2->digit == -12);
    assert(test4->digit == 97);
    assert(test6->digit == -55);

    test2 = int_multi(test1,test2);
    test4 = int_multi(test3,test4);
    test6 = int_multi(test5,test6);
    assert(test2->digit == -516);
    assert(test4->digit == 5529);
    assert(test6->digit == -1045);

    int_free_struct(test1);
    int_free_struct(test2);
    int_free_struct(test3);
    int_free_struct(test4);
    int_free_struct(test5);
    int_free_struct(test6);
    printf("Int test was passed successfully.\n");
}


void test_of_complex(){
    RingInfo *ring = CreateRing((void *(*)(void *)) complex_define,(void * (*)(void *)) complex_input,(void * (*)(void *)) complex_copy,
                                (void (*)(void *)) complex_output, (int (*)(void *, void *)) complex_compare,(void *(*)(void *, void *)) complex_sum,
                                (void *(*)(void *, void *)) complex_multi,(void * (*)(void *, void *))  complex_subtract,
                                (void (*)(void *)) complex_free_struct, sizeof(void *));


    type_complex *test1 = complex_define(484.91, 636.64);
    type_complex *test2 = complex_define(19.79, 74.12);
    type_complex *test3 = complex_define(320.23, 820.34);
    type_complex *test4 = complex_define(-935.95, -745.99);
    type_complex *test5 = complex_define(-120.36, 382.73);
    type_complex *test6 = complex_define(703.41, -101.25);

    dynamic *arr1 = create_array(ring, 6);
    arr1->arr[0] = test1;
    arr1->arr[1] = test2;
    arr1->arr[2] = test3;
    arr1->arr[3] = test4;
    arr1->arr[4] = test5;
    arr1->arr[5] = test6;

    dynamic *arr2 = create_array(ring, 6);
    arr2->arr[0] = test6;
    arr2->arr[1] = test5;
    arr2->arr[2] = test4;
    arr2->arr[3] = test3;
    arr2->arr[4] = test2;
    arr2->arr[5] = test1;

    arr1 = concat(arr1,arr2,ring);
    assert(complex_compare(arr1->arr[0],arr1->arr[11]) == 0);
    assert(complex_compare(arr1->arr[1],arr1->arr[10]) == 0);
    assert(complex_compare(arr1->arr[2],arr1->arr[9]) == 0);
    assert(complex_compare(arr1->arr[3],arr1->arr[8]) == 0);
    assert(complex_compare(arr1->arr[4],arr1->arr[7]) == 0);
    assert(complex_compare(arr1->arr[5],arr1->arr[6]) == 0);

    // map
    dynamic *arr3 = create_array(ring, 6);
    arr3->arr[0] = test6;
    arr3->arr[1] = test5;
    arr3->arr[2] = test4;
    arr3->arr[3] = test3;
    arr3->arr[4] = test2;
    arr3->arr[5] = test1;

    dynamic* val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = complex_define(2000, 2000);
    arr3 = map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);

    val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = complex_define(-40, -40);
    arr3 =  map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);

    val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = int_define(3);
    arr3 =map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);
    assert(complex_compare(arr3->arr[0],test6) == 0);
    assert(complex_compare(arr3->arr[1],test5) == 0);
    assert(complex_compare(arr3->arr[2],test4) == 0);
    assert(complex_compare(arr3->arr[3],test3) == 0);
    assert(complex_compare(arr3->arr[4],test2) == 0);
    assert(complex_compare(arr3->arr[5],test1) == 0);

    // where
    arr3 = create_array(ring, 6);
    arr3->arr[0] = test6;
    arr3->arr[1] = test5;
    arr3->arr[2] = test4;
    arr3->arr[3] = test3;
    arr3->arr[4] = test2;
    arr3->arr[5] = test1;

    dynamic *value = (dynamic *) malloc (sizeof(dynamic));
    value->size = 1;
    value-> arr = (void **) malloc(value->size * ring->size);
    value->arr[0] = complex_define(484.91, 636.64);
    arr3 = where(arr3, ring, compare3, value);
    free_array(value, ring);
    assert(arr3->size == 1);


    free_array(arr1, ring);
    free_array(arr2,ring);
    free_array(arr3, ring);
    printf("Test of functions with complex was passed successfully.\n");
}




void test_of_int(){
    RingInfo *ring = CreateRing((void *(*)(void *)) int_define, (void * (*)(void *)) int_input,(void * (*)(void *)) int_copy,
                                (void (*)(void *)) int_output, (int (*)(void *, void *)) int_compare,(void *(*)(void *, void *)) int_sum,
                                (void *(*)(void *, void *)) int_multi,(void * (*)(void *, void *))  int_subtract,
                                (void (*)(void *)) int_free_struct, sizeof(void *));


    type_int *test1 = int_define(43);
    type_int *test2 = int_define(-12);
    type_int *test3 = int_define(57);
    type_int *test4 = int_define(-97);
    type_int *test5 = int_define(19);
    type_int *test6 = int_define(55);

    dynamic *arr1 = create_array(ring, 6);
    arr1->arr[0] = test1;
    arr1->arr[1] = test2;
    arr1->arr[2] = test3;
    arr1->arr[3] = test4;
    arr1->arr[4] = test5;
    arr1->arr[5] = test6;

    dynamic *arr2 = create_array(ring, 6);
    arr2->arr[0] = test6;
    arr2->arr[1] = test5;
    arr2->arr[2] = test4;
    arr2->arr[3] = test3;
    arr2->arr[4] = test2;
    arr2->arr[5] = test1;

    arr1 = concat(arr1,arr2,ring);
    assert(int_compare(arr1->arr[0],arr1->arr[11]) == 0);
    assert(int_compare(arr1->arr[1],arr1->arr[10]) == 0);
    assert(int_compare(arr1->arr[2],arr1->arr[9]) == 0);
    assert(int_compare(arr1->arr[3],arr1->arr[8]) == 0);
    assert(int_compare(arr1->arr[4],arr1->arr[7]) == 0);
    assert(int_compare(arr1->arr[5],arr1->arr[6]) == 0);


    //map
    dynamic *arr3 = create_array(ring, 6);
    arr3->arr[0] = test6;
    arr3->arr[1] = test5;
    arr3->arr[2] = test4;
    arr3->arr[3] = test3;
    arr3->arr[4] = test2;
    arr3->arr[5] = test1;

    dynamic* val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = int_define(2000);
    arr3 = map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);

    val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = int_define(-40);
    arr3 =  map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);

    val = (dynamic *) malloc (sizeof(dynamic));
    val->size = 1;
    val-> arr = (void **) malloc(val->size * ring->size);
    val->arr[0] = int_define(3);
    arr3 =map(arr3, ring, ring->sum, val);
    arr3 = map(arr3, ring, ring->subtract, val);
    free_array(val, ring);

    assert(int_compare(arr3->arr[0],test6) == 0);
    assert(int_compare(arr3->arr[1],test5) == 0);
    assert(int_compare(arr3->arr[2],test4) == 0);
    assert(int_compare(arr3->arr[3],test3) == 0);
    assert(int_compare(arr3->arr[4],test2) == 0);
    assert(int_compare(arr3->arr[5],test1) == 0);


    // where
    arr3 = create_array(ring, 6);
    arr3->arr[0] = test6;
    arr3->arr[1] = test5;
    arr3->arr[2] = test4;
    arr3->arr[3] = test3;
    arr3->arr[4] = test2;
    arr3->arr[5] = test1;

    dynamic *value = (dynamic *) malloc (sizeof(dynamic));
    value->size = 1;
    value-> arr = (void **) malloc(value->size * ring->size);
    value->arr[0] = int_define(55);
    arr3 = where(arr3, ring, compare3, value);
    free_array(value, ring);
    assert(arr3->size == 1);

    free_array(arr1, ring);
    free_array(arr2,ring);
    free_array(arr3,ring);
    free_ring(ring);
    printf("Test of functions with int was passed successfully.\n");
}


void TEST() {
    test_complex();
    test_int();
    test_of_complex();
    test_of_int();
    printf("That is all.\n");
    getchar();
}

