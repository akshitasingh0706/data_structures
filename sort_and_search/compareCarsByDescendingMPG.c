/*
 return a value that will cause qksort to sort an array of cars in descending order (from largest to smallest) by mpg
 */
#include <stdio.h>
#include <string.h>

#include "Car.h"

int compareCarsByDescendingMPG(const void *key1, const void *key2)
{
    Car *Car1 = (Car *)key1;
    Car *Car2 = (Car *)key2;

    // Sort by alphabetical car make
    if (Car1->mpg < Car2->mpg)
        return 1;
    else if (Car1->mpg > Car2->mpg)
        return -1;
    else
        return 0;
}







//
//int compareCarsByDescendingMPG(const void *key1,const void *key2){
//   Car *c1 = (Car*)key1;
//   Car *c2 = (Car*)key2;
//   /*sort by descending mpg*/
//   if (c1->mpg > c2->mpg)
//       return -1;
//   else if (c1->mpg < c2->mpg)
//       return 1;
//   else
//       return 0;
//
//}
