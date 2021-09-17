#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void display(List *pPolynomial);
double evaluate(List *pPolynomial, double x);

int main()
{
    List poly1, poly2, poly3, poly4;

    // create the polynomials
    list_init(&poly1, NULL); // -x + 1.0
    list_init(&poly2, NULL); // x^2 - 1.0
    list_init(&poly3, NULL); // -3.0x^3 + 0.5x^2 - 2.0x
    list_init(&poly4, NULL); // -0.3125x^4 - 9.915x^2 - 7.75x - 40.0

    // variable for the coefficient index
    int coeff_index;

    // polynomial 1 expressions: -x + 1.0
    double coeffs_array1[] = {-1,1};
    int coeffs_len1 = sizeof(coeffs_array1)/sizeof(coeffs_array1[0]);
    double *coeffs_poly1 = NULL;
    coeffs_poly1 = (double *)malloc(coeffs_len1 * sizeof(double));

    for (coeff_index = 0; coeff_index < coeffs_len1; coeff_index++)
    {
        *(coeffs_poly1 + coeff_index) = coeffs_array1[coeff_index];
        list_ins_next(&poly1, list_tail(&poly1), (coeffs_poly1 + coeff_index));
    }

    // polynomial 2 expressions: x^2 - 1.0
    double coeffs_array2[] = {1, 0, -1};
    int coeffs_len2 = sizeof(coeffs_array2)/sizeof(coeffs_array2[0]);
    double *coeffs_poly2 = NULL;
    coeffs_poly2 = (double *)malloc(coeffs_len2 * sizeof(double));

    for (coeff_index = 0; coeff_index < coeffs_len2; coeff_index++)
    {
        *(coeffs_poly2 + coeff_index) = coeffs_array2[coeff_index];
        list_ins_next(&poly2, list_tail(&poly2), (coeffs_poly2 + coeff_index));
    }

    // polynomial 3 expressions: -3.0x^3 + 0.5x^2 - 2.0x
    double coeffs_array3[] = {-3 , .5, -2, 0};
    int coeffs_len3 = sizeof(coeffs_array3)/sizeof(coeffs_array3[0]);
    double *coeffs_poly3 = NULL;
    coeffs_poly3 = (double *)malloc(coeffs_len3 * sizeof(double));

    for (coeff_index = 0; coeff_index < coeffs_len3; coeff_index++)
    {
     *(coeffs_poly3 + coeff_index) = coeffs_array3[coeff_index];
     list_ins_next(&poly3, list_tail(&poly3), (coeffs_poly3 + coeff_index));
    }

    // polynomial 4 expressions: -0.3125x^4 - 9.915x^2 - 7.75x - 40.0
    double coeffs_array4[] = {-0.3125 , 0 , - 9.915 , - 7.75 , -40};
    int coeffs_len4 = sizeof(coeffs_array4)/sizeof(coeffs_array4[0]);
    double *coeffs_poly4 = NULL;
    coeffs_poly4 = (double *)malloc(coeffs_len4 * sizeof(double));

    for (coeff_index = 0; coeff_index < coeffs_len4; coeff_index++)
    {
     *(coeffs_poly4 + coeff_index) = coeffs_array4[coeff_index];
     list_ins_next(&poly4, list_tail(&poly4), (coeffs_poly4 + coeff_index));
    }

    printf("Polynomial 1: ");
    display(&poly1);
    printf("Value of poly1 when x = 1.0 is %.4f\n\n", evaluate(&poly1, 1.0));

    printf("Polynomial 2: ");
    display(&poly2);
    printf("Value of poly2 when x = 2.03 is %.4f\n\n", evaluate(&poly2, 2.03));

    printf("Polynomial 3: ");
    display(&poly3);
    printf("Value of poly3 when x = 05.0 is %.4f\n\n", evaluate(&poly3, 05.0));

    printf("Polynomial 4: ");
    display(&poly4);
    printf("Value of poly3 when x = 123.45 is %.4f\n\n", evaluate(&poly4, 123.45));

    list_destroy(&poly1);
    list_destroy(&poly2);
    list_destroy(&poly3);
    list_destroy(&poly4);

    free(coeffs_poly1);
    free(coeffs_poly2);
    free(coeffs_poly3);
    free(coeffs_poly4);

    return EXIT_SUCCESS;
}



//
//// testing appendTerm
//void appendTerm(List* pPolynomial, double constant);
//void display(List *pPolynomial);
//
//int main()
//{
//    List poly1;
//
//    // create the polynomials
//    list_init(&poly1, NULL); // -x + 1.0
//
//    // variable for the coefficient index
//    int coeff_index;
//
//    // polynomial 1 expressions: -x + 1.0
//    double coeffs_array1[] = {-1,0};
//    int coeffs_len1 = sizeof(coeffs_array1)/sizeof(coeffs_array1[0]);
//    double *coeffs_poly1 = NULL;
//    coeffs_poly1 = (double *)malloc(coeffs_len1 * sizeof(double));
//
//    for (coeff_index = 0; coeff_index < coeffs_len1; coeff_index++)
//    {
//        *(coeffs_poly1 + coeff_index) = coeffs_array1[coeff_index];
//        list_ins_next(&poly1, list_tail(&poly1), (coeffs_poly1 + coeff_index));
//    }
//
//    appendTerm(&poly1, -3);
//    appendTerm(&poly1, 2);
//    display(&poly1);
//}
