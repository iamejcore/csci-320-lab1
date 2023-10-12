/*
 * Implement your solution in thi file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

char* readString(const char* fileName) {
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        fprintf("File Not Found");
        return NULL;
    }
}

