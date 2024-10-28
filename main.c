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

    char *inputFile = argv[ARG_INPUT_FILE];
    char *outputFile = argv[ARG_OUTPUT_FILE];
    char *option = argv[ARG_OPTION];

    // Can we check if the file is already created so we don't append to an already created already?
    FILE *ptrIn = fopen(inputFile, "r");
    FILE *ptrOut = fopen(outputFile, "w");

    if(ptrIn == NULL) {
        perror("Input file not found.");
        return EXIT_FAILURE;
    }

    IOStudentsFiles(ptrIn, ptrOut, option);

    closeFiles(ptrIn, ptrOut);

    return EXIT_SUCCESS;
}
