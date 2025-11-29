#include "../include/calculator.h"

int validate_arguments(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Error: Malo argumentov");
        return 0;
    }

    int has_flag = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-k") == 0) {
            has_flag = 1;
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: Net klyucha\n");
                return 0;
            }

            for (int j = 0; argv[i + 1][j] != '\0'; j++) {
                if (!isdigit(argv[i + 1][j]) && argv[i + 1][j] != '-') {
                    fprintf(stderr, "Error: Klyuch incorrect\n");
                    return 0;
                }
            }
            break;
        }
    }

    if (!has_flag) {
        fprintf(stderr, "Error: Net flag\n");
        return 0;
    }

    int i = 1;
    while (i < argc && strcmp(argv[i], "-k") != 0) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j]) && argv[i][j] != '-') {
                fprintf(stderr, "Error: Incorrect left operand\n", argv[i]);
                return 0;
            }
        }

        i++;

        if (i >= argc || strcmp(argv[i], "-k") == 0) {
            fprintf(stderr, "Error: Incorrect input\n");
            return 0;
        }

        if (strlen(argv[i]) != 1 || !is_valid_operator(argv[i][0])) {
            fprintf(stderr, "Error: Incorrect operator\n", argv[i]);
            return 0;
        }

        i++;

        if (i >= argc || strcmp(argv[i], "-k") == 0) {
            fprintf(stderr, "Error: Incorrect input\n");
            return 0;
        }

        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j]) && argv[i][j] != '-') {
                fprintf(stderr, "Error: Incorrect right operand\n", argv[i]);
                return 0;
            }
        }

        i++;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (!validate_arguments(argc, argv)) {
        return EXIT_FAILURE;
    }

    int *results = NULL;
    int result_count = 0;

    int flag_index = process_expressions(argc, argv, &results, &result_count);

    int key = atoi(argv[flag_index + 1]);

    print_results(results, result_count);

    char *decoded_string = decode_string(results, result_count, key);
    if (decoded_string != NULL) {
        printf("Result string: %s\n", decoded_string);
    }

    free_memory(results, decoded_string);

    return EXIT_SUCCESS;
}