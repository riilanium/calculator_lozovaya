#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate_expression(int left, char op, int right);
int process_expressions(int argc, char *argv[], int **results, int *result_count);
void print_results(int *results, int count);

// Функции дешифратора
char* decode_string(int *results, int count, int key);
void free_memory(int *results, char *decoded_string);

// Вспомогательные функции
int is_valid_operator(char op);
int validate_arguments(int argc, char *argv[]);

#endif