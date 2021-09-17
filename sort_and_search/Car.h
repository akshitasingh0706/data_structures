/*
 * list.h
 */
#ifndef CAR_H
#define CAR_H

#include <stdlib.h>

#define MAX_STRING_LENGTH 500

typedef struct Car_ {
    char make[MAX_STRING_LENGTH];
    char model[MAX_STRING_LENGTH];
    int mpg;
} Car;

#endif
