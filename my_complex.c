#include <stdio.h>
#include <stdlib.h>
#include "my_complex.h"
#include <math.h>

type_complex *complex_define(double Re, double Im){
    type_complex *number = (type_complex*)malloc(sizeof(type_complex));
    number->Re = round(Re*10000)/10000;
    number->Im = round(Im*10000)/10000;
    return number;
}


type_complex *complex_input(){
    double Re, Im;
    printf("Re : ");
    scanf("%lf",&Re);
    printf("Im : ");
    scanf("%lf",&Im);
    type_complex *number = complex_define(Re, Im);
    return number;
}


void complex_output(type_complex *number){
    if (number == NULL){
        printf("NULL\n");
        return;
    }
    printf("%f + i * %f \n", number -> Re, number -> Im);
}


type_complex *complex_sum(type_complex *num1, type_complex *num2){
    if (num1 == NULL || num2 == NULL)  {  return NULL;  }
    type_complex* number = complex_define((num1->Re + num2->Re),(num1->Im + num2->Im));
    return number;

}


type_complex *complex_multi(type_complex *num1, type_complex *num2){
    if (num1 == NULL || num2 == NULL)  {  return NULL;  }
    type_complex* number = complex_define(num1->Re * num2->Re,num1->Im * num2->Im);
    return number;

}


type_complex *complex_subtract(type_complex *num1, type_complex *num2){
    if (num1 == NULL || num2 == NULL)  {  return NULL;  }
    type_complex *number = complex_define(num1->Re - num2->Re,num1->Im - num2->Im);
    return number;

}


int complex_compare(type_complex *num1, type_complex *num2){
    double mag1 = (*num1).Re * (*num1).Re + (*num1).Im * (*num1).Im;
    double mag2 = (*num2).Re * (*num2).Re + (*num2).Im * (*num2).Im;
    if (mag1 > mag2) {  return 1;  }
    else if (mag1 < mag2) {  return -1;  }
    else {  return 0;  }
}


void complex_free_struct(type_complex *num){
    free(num);
}


type_complex *complex_copy(type_complex *num){
    if (num == NULL){
        return NULL;
    }
    type_complex *number = (type_complex *)malloc(sizeof(type_complex));
    number -> Re = num -> Re;
    number -> Im = num -> Im;
    return number;
}





