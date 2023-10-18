
#ifndef LABA1_2SEM_MY_COMPLEX_H
#define LABA1_2SEM_MY_COMPLEX_H

typedef struct type_complex{
    double Re;
    double Im;
}type_complex;

type_complex *complex_define(double Re, double Im);
type_complex *complex_input();
void complex_output(type_complex *number);
type_complex *complex_sum(type_complex *num1, type_complex *num2);
type_complex *complex_subtract(type_complex *num1, type_complex *num2);
int complex_compare(type_complex *num1, type_complex *num2);
void complex_free_struct(type_complex *num);
type_complex *complex_copy(type_complex *num);
type_complex *complex_multi(type_complex *num1, type_complex *num2);

#endif //LABA1_2SEM_MY_COMPLEX_H
