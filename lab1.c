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
    
    // Find the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size > 99) {
        printf("File size is greater than 99.");
        fclose(file);
        return NULL;
    }

}

