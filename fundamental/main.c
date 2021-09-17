#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int *insert(int *array, int length, int index, int value);

int main(int argc, const char * argv[])
{

    int INSERTS_PER_READING = 1000;

    // start with an empty array
    int *array = NULL;
    int length = 0;

    // take 60 readings
    printf("Array Length\tSeconds Per Insert\n");
    for (int reading = 0; reading < 60; reading++)
    {
        // current time
        clock_t startTime;
        startTime = clock();

        // loop INSERTS_PER_READING times
        for (int num_insert = 0; num_insert < INSERTS_PER_READING; num_insert++)
        {
            srand((unsigned int)time(NULL));
            int index = rand() % (length + 1);
            int value = rand();

            array = insert(array, length, index, value);
            length++;
        }

        clock_t stopTime;
        stopTime = clock();
        double timePerInsert = ((double)(stopTime - startTime) / CLOCKS_PER_SEC)/INSERTS_PER_READING;

        printf("\t%d\t\t\t%f", length, timePerInsert);
        printf("\n");

    }

    free(array);
    return 0;
}


//check to see if array returns as expected
//int main(int argc, const char * argv[])
//{
//    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//    int *arr1;
//    arr1 = insert(arr, 10, 3, 40);
//    for (int i = 0; i < 11; i++)
//    {
//        printf("%d\n", arr1[i]);
//    }
//}
