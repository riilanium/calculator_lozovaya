#include "../include/calculator.h"

char* decode_string(int *results, int count, int key) {
    char *decoded = (char*)malloc((count + 1) * sizeof(char));
    
    for (int i = 0; i < count; i++) {
        int ascii_value = results[i] - key;

        if (ascii_value < 32 || ascii_value > 255) {
            fprintf(stderr, "Error: Incorrect symbol after decode\n", ascii_value);
        }
        
        decoded[i] = (char)ascii_value;
    }
    
    decoded[count] = '\0';
    return decoded;
}

void free_memory(int *results, char *decoded_string) {
    if (results != NULL) {
        free(results);
    }
    if (decoded_string != NULL) {
        free(decoded_string);
    }
}