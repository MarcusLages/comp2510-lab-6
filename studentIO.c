#include <stdlib.h>
#include "studentIO.h"

#define ERROR_MSG_SIZE 25

void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, char *option) {
    char *currLine = NULL;

    while(fgets(currLine, MAX_LINE_SIZE, ptrIn)) {
        Student *currStudent = getStudentFromLine(currLine);
        appendStudentTo(currStudent, ptrOut, option);

        free(currStudent);
    }
}

void appendStudentTo(Student *currStudent, FILE *ptrOut, char *option) {

}

FILE* openOutputFile(char *outputFile) {
    if(remove(outputFile) != EXIT_SUCCESS) {
        perror("Error cleaning output file.%n");
        return NULL;
    }

    FILE *ptrOut = fopen(outputFile, "a");

    return ptrOut;
}

void closeFiles(FILE *ptrIn, FILE *ptrOut) {
    fclose(ptrIn);
    ptrIn = NULL;

    fclose(ptrOut);
    ptrOut = NULL;
}