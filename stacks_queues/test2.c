//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#include "stack.h"
//
//void addLargeNumbers(const char *pNum1, const char *pNum2)
//{
//    // create 3 stacks
//    Stack stack1, stack2, result;
//
//    // initialize the 3 stacks
//    stack_init(&stack1, free);
//    stack_init(&stack2, free);
//    stack_init(&result, free);
//        
//    /*
//     For pNum1 and pNum2
//     1) convert the string into an integer using atoi
//     2) create an array that takes each digit of the integer as an input
//     3) reverse the order of the digits
//     (so that the unit's digit is on the top of the stack)
//     4) push each digit from the array into the stack
//     */
//    int num1 = atoi(pNum1);
//    int len1 = (int) strlen(pNum1);
//    int arr1[len1];
//    
//    int rev_num1 = 0;
//    while(num1 > 0)
//    {
//        // reverse digits so that unitsDigit digit in stack is least significant digit
//        rev_num1 = rev_num1 * 10 + num1 % 10;
//        num1 /= 10;
//    }
//    num1 = rev_num1;
//    
//    for (int i = 0; i < len1; i++)
//    {
//        int unitsDigit = num1 % 10;
//        arr1[i] = unitsDigit;
//        const void *digitPtr = &arr1[i];
//        
//        num1 /= 10;
//        stack_push(&stack1, digitPtr);
//    }
//    printf("\n");
//    // do the same for num2
//    int num2 = atoi(pNum2);
//    int len2 = (int) strlen(pNum2);
//    int arr2[len2];
//
//    int rev_num2 = 0;
//    while(num2 > 0)
//    {
//        // reverse digits so that unitsDigit digit in stack is least significant digit
//        rev_num2 = rev_num2 * 10 + num2 % 10;
//        num2 /= 10;
//    }
//    num2 = rev_num2;
//    
//    for (int i = 0; i < len2; i++)
//    {
//        int unitsDigit = num2 % 10;
//        arr2[i] = unitsDigit;
//        const void *digitPtr = &arr2[i];
//        
//        num2 /= 10;
//        stack_push(&stack2, digitPtr);
//    }
//    printf("\n");
//    
//    /*
//     1) initiate the carry variable which takes any carry overs
//     2) initiate variables to loop through digits of the integers
//     3) declare a void pointer which we use for popping digits
//     */
//    int carry = 0;
////    int p1 = 0;
////    int p2 = 0;
//    void *pop;
//    
//    /*
//     1) while either stack 1 or stack 2 are not empty
//     2) get digits from both numbers one place at a time (p1, p2)
//     3) pop digits after extraction
//     4) get the sum by adding the digits with any carry
//     5) push the units place of this sum into the result stack
//     6) ten's place of the sum gives the new carry value
//     */
//    
//    // while stack1 or stack2 are not empty...
//    while (stack_peek(&stack1) || stack_peek(&stack2))
//    {
//        int p1;
//        int p2;
//        
//        // pop next did of stack1 if not empty, or else use value 0
//        if (stack_peek(&stack1))
//        {
//            p1 = *((int *)stack_peek(&stack1));
//            stack_pop(&stack1, &pop);
//        }
//        else
//        {
//            p1 = 0;
//        }
//        // pop next did of stack2 if not empty, or else use value 0
//        if (stack_peek(&stack2))
//        {
//            p2 = *((int *)stack_peek(&stack2));
//            stack_pop(&stack2, &pop);
//        }
//        else
//        {
//            p2 = 0;
//        }
//        
//        // sum of digits and carry;
//        int sum = p1 + p2 + carry;
//        stack_push(&result, sum % 10);
//        // assign ten's place of sum to carry
//        carry = (sum/10) % 10;
//    }
//    // add any leftover carry term in the end
//    if (carry == 1)
//        stack_push(&result, carry);
//    
//    /*
//     print the result by peeking and popping through the loop
//     */
//    // while result not empty
//    while(stack_peek(&result) != NULL)
//    {
//        printf("%d", (int) stack_peek(&result));
//        stack_pop(&result, &pop);
//    }
//    
//    printf("\n");
//    return;
//}
//
