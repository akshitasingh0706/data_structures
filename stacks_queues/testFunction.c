#include <stdio.h>
#include "list.h"
#include "stack.h"
 
void addLargeNumbers(const char *pNum1, const char *pNum2);
 
int main(int argc, const char * argv[])
{
    printf("The sum of the first pair of large numbers is: ");
    addLargeNumbers("83042934", "10394304");
    printf("The sum of the first pair of large numbers is: ");
    addLargeNumbers("4239024", "9420932");
    printf("The sum of the first pair of large numbers is: ");
    addLargeNumbers("49230", "23949");
    return 0;
}
