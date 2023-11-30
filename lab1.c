/*
 * Implement your solution in thi file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

#define MAX_LINE_LEN 256

char* readString(char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }

    char *buffer = (char *)malloc(MAX_LINE_LEN * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return NULL;
    }

    if (fgets(buffer, MAX_LINE_LEN, file) == NULL) {
        printf("Error reading file!\n");
        fclose(file);
        free(buffer);
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    printf("%s\n", buffer);

    fclose(file);
    return buffer;
}

int calculateSize(const char *str) {
    int length = strlen(str);
    int size = (length * (length + 1)) / 2; // Calculate the size directly
    return size;
}

char* mysteryExplode(const char *str) {
    int size = calculateSize(str);

    char *buffer = (char *)malloc((size + 1) * sizeof(char)); // +1 for null terminator
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j <= i; j++) {
            buffer[index++] = str[j];
        }
    }

    buffer[index] = '\0'; // Add null terminator at the end

    return buffer;
}
