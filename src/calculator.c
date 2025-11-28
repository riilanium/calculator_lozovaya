#include "../include/calculator.h"

int is_valid_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '%';
}

int calculate_expression(int left, char op, int right) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '%':
            if (right == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return left % right;
        default:
            return 0;
    }
}

int process_expressions(int argc, char *argv[], int **results, int *result_count) {
    int i = 1;
    int count = 0;
    int flag_index = -1;

    while (i < argc) {
        if (strcmp(argv[i], "-k") == 0) {
            flag_index = i;
            break;
        }

        count++;
        i += 3;
    }

    *results = (int*)malloc(count * sizeof(int));

    i = 1;
    for (int j = 0; j < count; j++) {
        int left = atoi(argv[i]);
        char op = argv[i + 1][0];
        int right = atoi(argv[i + 2]);
        
        (*results)[j] = calculate_expression(left, op, right);
        i += 3;
    }
    
    *result_count = count;
    return flag_index;
}

void print_results(int *results, int count) {
    for (int i = 0; i < count; i++) {
        printf("Ответ №%d: %d\n", i + 1, results[i]);
    }
}