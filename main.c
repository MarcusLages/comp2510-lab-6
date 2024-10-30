#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "studentIO.h"

/**
 * Program's main entry point.
 *
 * @param argc quantity of arguments from the command line
 * @param argv arguments string array
 * @return 0 if program is successful
 */
int main(int argc, char **argv) {

    if(argc < MIN_ARGS) {
        perror("Not enough arguments for the program");
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[ARG_INPUT_FILE];
    char *outputFile = argv[ARG_OUTPUT_FILE];
    const int option = atoi(argv[ARG_OPTION]);

    FILE *ptrIn = fopen(inputFile, "r");
    FILE *ptrOut = openOutputFile(outputFile);

    if(ptrIn == NULL) {
        perror("Input file not found.");
        return EXIT_FAILURE;
    }

    IOStudentsFiles(ptrIn, ptrOut, option);

    closeFiles(ptrIn, ptrOut);

    return EXIT_SUCCESS;
}
