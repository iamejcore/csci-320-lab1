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





/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str) {
    size_t strLength = strlen(str);
    size_t finalStrLength = (strLength * (strLength + 1) / 2) + 1;
    char* resultStr = (char*)malloc(finalStrLength); // Allocate memory for the result string

    if (resultStr == NULL) {
        fprintf(stderr, "Memory allocation failed.");
        return NULL;
    }

    resultStr[0] = '\0'; // Initialize the result str as an empty string

    size_t resultIndex = 0; // Track the current position in resultStr

    for (size_t i = 0; i < strLength; i++) { // Outer Loop
        for (size_t j = 0; j <= i; j++) {    // Inner Loop
            resultStr[resultIndex++] = str[j]; // Copying chars over, 1 by 1
        }
        resultStr[resultIndex] = '\0'; // Updating the null-termination of the C string
    }

    return resultStr;
}

