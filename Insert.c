#include <stdio.h>
#include <stdlib.h>
 
int *insert(int *array, int length, int index, int value)
{
    // when array is empty
    if (length == 0)
    {
        // create a new array with size of an integer (because it will contain just one value)
        array = (int *)malloc(sizeof(int));
        array[0] = value;
        return array;
    }
    
    // when the array has at least 1 element
    else
    {
        // create a new array with the size of an int * (length + 1)
        int *newArray = (int *)malloc((length + 1) * sizeof(int*));
        
        // see if memory allocation failed
        if(newArray == NULL)
        {
          printf("malloc failed");
          exit(1);
        }
        
        int array_loc;
        // up until we hit the index, we just copy values from the old to new array as is
        for (array_loc = 0; array_loc < index; array_loc++)
            newArray[array_loc] = array[array_loc];
        
        // insert the value at the index
        newArray[index] = value;
        
        // after the index, the new array takes in the values from the old array's previous posistion
        for (int array_loc = index; array_loc < length + 1; array_loc++)
            newArray[array_loc + 1] = array[array_loc];
        
        // free memory taken by the old array considering we do not need it anymore
        free(array);
        return newArray;
    }
    return 0;
}

