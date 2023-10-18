
#ifndef LABA1_2SEM_MY_INT_H
#define LABA1_2SEM_MY_INT_H


typedef struct type_int{
    int digit;
}type_int;

type_int *int_define(int value);
type_int *int_input();
void int_output(type_int *number);
type_int *int_sum(type_int *num1, type_int *num2);
type_int *int_subtract(type_int *num1, type_int *num2);
int int_compare(type_int *num1, type_int *num2);
void int_free_struct(type_int *num);
type_int *int_copy(type_int *num);
type_int *int_multi(type_int *num1, type_int *num2);

#endif //LABA1_2SEM_MY_INT_H
