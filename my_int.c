#include "my_int.h"
#include <stdio.h>
#include <stdlib.h>


type_int *int_define(int value){
    type_int *number = (type_int*)malloc(sizeof(type_int));
    number -> digit = value;
    return number;
}


type_int *int_input(){
    int value = 0;
    printf("Value : ");
    scanf("%d",&value);
    type_int *number = int_define(value);
    return number;
}


void int_output(type_int *number){
    if (number == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d ", number -> digit);
}


type_int *int_sum(type_int *num1, type_int *num2){
    if (num1 == NULL || num2 == NULL)  {  return NULL;  }
    type_int* number = int_define(num1 -> digit + num2 -> digit);
    return number;
}


type_int *int_multi(type_int *num1, type_int *num2){
    if (num1 == NULL || num2 == NULL)  {  return NULL;  }
    type_int* number = int_define(num1 -> digit * num2 -> digit);
    return number;
}


type_int *int_subtract(type_int *num1, type_int *num2){
    if (num1 == NULL || num2 == NULL){
        return NULL;
    }
    type_int *number = int_define(num1 -> digit - num2 -> digit);
    return number;
}

int int_compare(type_int *num1, type_int *num2){
    if (num1 == NULL || num2 == NULL)  {  return 0;  }
    return (num1->digit > num2->digit) - (num1->digit < num2->digit);
}


void int_free_struct(type_int *num){
    free(num);
}


type_int *int_copy(type_int *num){
    if (num == NULL)  {  return NULL;  }
    type_int *number = (type_int *)malloc(sizeof(type_int));
    number -> digit = num -> digit;
    return number;
}

