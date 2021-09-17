/*
 return a value that will cause qksort to sort an array of cars in ascending order (from smallest to largest) by make and, when two cars have the same make, in ascending order by model.
 */

#include <stdio.h>
#include <string.h>

#include "Car.h"

int compareCarsByMakeThenModel(const void *key1, const void *key2)
{
    int MakeThenModel;

    Car *Car1 = (Car *)key1;
    Car *Car2 = (Car *)key2;

    MakeThenModel = strcmp(Car1->make,Car2->make);
    // Sort by alphabetical car make
    if (MakeThenModel > 0)
        return 1;
    else if (MakeThenModel < 0)
        return -1;
    // if the car make is identical, sort by alphabetical car model
    else
    {
        MakeThenModel = strcmp(Car1->model,Car2->model);
        if (MakeThenModel > 0)
            return 1;
        else if (MakeThenModel < 0)
            return -1;
        else
            return 0;
    }
    return 0;
}



































//
//int compareCarsByMakeThenModel(const void *key1, const void *key2){
//   Car *c1 = (Car*)key1;
//   Car *c2 = (Car*)key2;
//   int MakeThenModel = strcmp(c1->make,c2->make);
//   /*Sort by alphabetical car make*/
//   if (MakeThenModel > 0)
//       return 1;
//   else if (MakeThenModel < 0)
//       return -1;
//   /*if the car make is identical, sort by alphabetical car model*/
//   else{
//       MakeThenModel = strcmp(c1->model,c2->model);
//       if (MakeThenModel > 0)
//           return 1;
//       else if (MakeThenModel < 0)
//           return -1;
//       else
//           return 0;
//   }
//}
