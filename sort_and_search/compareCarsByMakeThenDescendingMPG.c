/*
 return a value that will cause qksort to sort an array of cars in ascending order by make and, when two cars have the same make, in descending order by mpg
 */
#include <stdio.h>
#include <string.h>

#include "Car.h"

int compareCarsByMakeThenDescendingMPG(const void *key1, const void *key2)
{
    int MakeThenMPG;

    Car *Car1 = (Car *)key1;
    Car *Car2 = (Car *)key2;

    MakeThenMPG = strcmp(Car1->make,Car2->make);
    // Sort by alphabetical car make
    if (MakeThenMPG > 0)
        return 1;
    else if (MakeThenMPG < 0)
        return -1;
    // if the car make is identical, sort by alphabetical car model
    else
    {
        if (Car1->mpg < Car2->mpg)
            return 1;
        else if (Car1->mpg > Car2->mpg)
            return -1;
        else
            return 0;
    }
    return 0;
}







//
//
//int compareCarsByMakeThenDescendingMPG(const void *key1, const void *key2){
//Car *c1 = (Car*)key1;
//Car *c2 = (Car*)key2;
//int strcmpResult = strcmp(c1->make,c2->make);
///*Sort by alphabetical car make*/
//if (strcmpResult > 0)
//    return 1;
//else if (strcmpResult < 0)
//    return -1;
//else{
//    /*if the car make is identical, sort by descending mpg*/
//    if (c1->mpg > c2->mpg)
//        return -1;
//    else if (c1->mpg < c2->mpg)
//        return 1;
//    else
//        return 0;
//}
