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

    char* contents = (char*)malloc(file_size + 1);  // +1 for null terminator

    if (contents == NULL) {
        fprintf(stderr, "Error in dynamically allocating memory for contents.");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(contents, 1, file_size, file);
    contents[bytes_read] = '\0'; // Null-terminate the string

    fclose(file);

    return contents;
}

