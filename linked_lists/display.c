#include <stdio.h>

#include "list.h"

void display(List *pPolynomial)
{
    int power;
    ListElmt *variable;

    // declare 2 pointers for the current and next coefficient values
    double *coeff;
    double *coeff_next;
    // dynamically allocate memory to the coefficients
    coeff = (double *)malloc(sizeof(double));
    coeff_next = (double *)malloc(sizeof(double));

    // start with the term with the highest power
    // which in our case, by default, would be the head
    variable = list_head(pPolynomial);

    // calculate the highest power
    power = list_size(pPolynomial) - 1;

    // ensure that there are more variables to this polynomial
    while (list_next(variable) != NULL)
    {
        while (power > 0)
        {
            coeff = (double *)list_data(variable);
            coeff_next = (double *)list_data(list_next(variable));
            // only print if the coefficient is non-zero (i.e the variable exists)
            if (*coeff != 0)
            {
                if (power > 1)
                {
                    // printing the term when coefficient is negative
                    if (*coeff_next <= 0)
                        printf("%.4fx^%d ", *coeff, power);
                    // printing the term when coefficient is positive
                    else
                        printf("%.4fx^%d + ", *coeff, power);
                    variable = list_next(variable);
                }
                else
                {
                    // printing the term when coefficient is negative
                    if (*coeff_next <= 0)
                        printf("%.4fx ", *coeff);
                    // printing the term when coefficient is positive
                    else
                        printf("%.4fx + ", *coeff);
                    variable = list_next(variable);
                }
            }
            else
            {
                variable = list_next(variable);
            }
            power--;
        }

        // just move the variable and coefficient to the tail
        variable = list_tail(pPolynomial);
        coeff = (double *)list_data(variable);
        // see if the coefficient is not equal to zero
        // i.e the polynomial does contain a constant term
        if (*coeff != 0)
        {
            // printing a negative constant term
            if (*coeff < 0)
                printf(" %.4f", *coeff);
            // printing a positive number
            else
                printf(" %.4f", *coeff);
            
        }
    }
    printf("\n");
}
