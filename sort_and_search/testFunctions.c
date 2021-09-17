#include <stdio.h>
#include <string.h>

#include "Car.h"

int compareCarsByMakeThenModel(const void *key1, const void *key2);
int compareCarsByDescendingMPG(const void *key1, const void *key2);
int compareCarsByMakeThenDescendingMPG(const void *key1, const void *key2);
void display(Car *someCar, int numCars);
int qksort(void *data, int size, int esize, int i, int k,
           int (*compare)(const void *key1, const void *key2));

int main()
{
    Car cars[] =
    {
       { "Toyota", "Camry", 33 },
       { "Ford", "Focus", 40 },
       { "Honda", "Accord", 34 },
       { "Ford", "Mustang", 31 },
       { "Honda", "Civic", 39 },
       { "Toyota", "Prius", 48 },
       { "Honda", "Fit", 35 },
       { "Toyota", "Corolla", 35 },
       { "Ford", "Taurus", 28 }
    };
    
     int start_index = 0;
     int numCars = sizeof(cars)/sizeof(Car);

     // print an unsorted list of cars (as given)
     printf("Unsorted list of Cars\n");
     display(cars, numCars);

     // print cars sorted in ascending order of makes, then models
     printf("\nCars Sorted in an Ascending order of Makes, then Models\n");
     qksort(cars, sizeof(cars), sizeof(Car), start_index, numCars - 1,
            compareCarsByMakeThenModel);
     display(cars, numCars);

     // print cars sorted in descending order of mpgs
     printf("\nCars Sorted in a Descending order of miles per gallon\n");
     qksort(cars, sizeof(cars), sizeof(Car), start_index, numCars - 1,
            compareCarsByDescendingMPG);
     display(cars, numCars);
    
     // print cars sorted in ascending order of makes
     // then descending order of mpgs
     printf("\nCars Sorted in an Ascending then Descending orders of Makes then MPGs\n");
     qksort(cars, sizeof(cars), sizeof(Car),
            start_index, numCars - 1, compareCarsByMakeThenDescendingMPG);
     display(cars, numCars);
     return 0;
}




