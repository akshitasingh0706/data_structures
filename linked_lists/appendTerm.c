#include <stdio.h>

#include "list.h"

void appendTerm(List* pPolynomial, double constant)
{
    // declare a double pointer and allocate space for it dynamically
    double *new_const;
    new_const = (double *)malloc(sizeof(double));
    // assign the parameterer to be stored in the pointer we declare
    *new_const = constant;
    // call the insert function to insert the constant to the end of the list
    list_ins_next(pPolynomial, list_tail(pPolynomial), new_const);
}
