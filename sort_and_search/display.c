/* function to display outputs of Car array*/

#include <stdio.h>
#include <string.h>
#include "Car.h"

void display(Car *someCar, int length)
{
  
    printf("%9.9s\t\t%9.9s\t\t%5.5s\n", "Make","Model","MPG");
    printf("------------------------------------------"
           "\n------------------------------------------\n");
    for (int carIndex = 0 ; carIndex < length ; carIndex++)
       printf("%10.10s\t\t%10.10s\t\t%5d\n",
                        someCar[carIndex].make, someCar[carIndex].model, someCar[carIndex].mpg);
    return;
}
