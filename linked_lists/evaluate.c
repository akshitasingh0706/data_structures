#include <stdio.h>

#include "list.h"

// create a function to calculate the exponent
double exponent(double base, int power)
{
    double result = 1;
    if (power == 0)
        return result;
    else
    {
        for (; power > 0; power--)
            result = result * base;
        return result;
    }
}

double evaluate(List *pPolynomial, double x)
{
    ListElmt *variable;
    double *coeff;
    coeff = (double *)malloc(sizeof(double));
    double sum = 0;
    
    int power = list_size(pPolynomial) - 1;
    
    //initialize the variable to the head
    variable = list_head(pPolynomial);
    
    // loop through the polynomial till the end
     while (list_next(variable) != NULL)
     {
         //extract exact data value from the data pointer
         coeff = (double *)list_data(variable);
         double term = (*coeff)*(exponent(x, power));
         sum = sum + term;
         // move to the next element in the list
         variable = list_next(variable);
         power--;
     }
    
    // adding the last constant term
    variable = list_tail(pPolynomial);
    coeff = (double *)list_data(variable);
    sum = sum + *coeff;
    
    return sum;
}
