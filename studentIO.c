#include <stdlib.h>
#include "studentIO.h"

#define ERROR_MSG_SIZE 25

void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, int option) {
    char *currLine = NULL;

    while(fgets(currLine, MAX_LINE_SIZE, ptrIn)) {
        const Student currStudent = getStudentFromLine(currLine);
        appendStudentTo(currStudent, ptrOut, option);
    }
}

void appendStudentTo(Student currStudent, FILE *ptrOut, int option) {
    switch(option) {
        case OPTION_ONLY_DOMESTIC:
            if(!currStudent.isInternational) {
                char *info = getStudentInformation(currStudent);
                fputs(info, ptrOut);
                free(info);
                info = NULL;
            }
            break;
        case OPTION_ONLY_INTERNATIONAL:
            if(currStudent.isInternational) {
                char *info = getStudentInformation(currStudent);
                fputs(info, ptrOut);
                free(info);
                info = NULL;
            }
            break;
        case OPTION_ALL:
            char *info = getStudentInformation(currStudent);
            fputs(info, ptrOut);
            free(info);
            info = NULL;
            break;
        default:
            perror("Error appending student to output file.");
            exit(EXIT_FAILURE);
    }
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