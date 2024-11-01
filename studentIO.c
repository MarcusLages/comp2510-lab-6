#include <stdlib.h>
#include "studentIO.h"

void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, const int option) {
    char currLine[MAX_LINE_SIZE];

    while(fgets(currLine, MAX_LINE_SIZE, ptrIn)) {
        const Student currStudent = getStudentFromLine(currLine);
        appendStudentTo(currStudent, ptrOut, option);
    }
}

void appendStudentTo(const Student currStudent, FILE *ptrOut, const int option) {
    // Checks if a student should be printed out depending on the option
    // Appends the student information to the output file
    switch(option - 1) {
        case OPTION_ONLY_DOMESTIC:
            if(!currStudent.isInternational) {
                char *info = getStudentInformation(currStudent);
                if(!checkErrors(currStudent, ptrOut)) {
                    fputs(info, ptrOut);
                }
                free(info);
                info = NULL;
            }
            break;
        case OPTION_ONLY_INTERNATIONAL:
            if(currStudent.isInternational) {
                char *info = getStudentInformation(currStudent);
                if(!checkErrors(currStudent, ptrOut)) {
                    fputs(info, ptrOut);
                }
                free(info);
                info = NULL;
            }
            break;
        case OPTION_ALL:
            char *info = getStudentInformation(currStudent);
            if(!checkErrors(currStudent, ptrOut)) {
                fputs(info, ptrOut);
            }
            free(info);
            info = NULL;
            break;
        default:
            perror("Error appending student to output file.");
            exit(EXIT_FAILURE);
    }
}

FILE* openOutputFile(char *outputFile) {
    // Removes file so it can be written using append
    // It is inefficient , but this avoids having to keep track of the
    // data using an array
    remove(outputFile);

    FILE *ptrOut = fopen(outputFile, "a");

    return ptrOut;
}

int checkErrors(const Student student, FILE *errorOutput) {
    if(student.isInternational == STUDENT_ERROR_CODE) {
        fputs("ERROR: Invalid status.\n", errorOutput);
        exit(EXIT_FAILURE);
        // return 1;
    }

    if(student.info.domestic.GPA <= STUDENT_ERROR_CODE) {
        fputs("ERROR: Invalid GPA.\n", errorOutput);
        exit(EXIT_FAILURE);
        // return 1;
    }
    if(student.info.international.TOEFL == STUDENT_ERROR_CODE) {
        fputs("ERROR: Invalid TOEFL grade\n", errorOutput);
        exit(EXIT_FAILURE);
        // return 1;
    }

    return 0;
}

void closeFiles(FILE *ptrIn, FILE *ptrOut) {
    fclose(ptrIn);
    ptrIn = NULL;

    fclose(ptrOut);
    ptrOut = NULL;
}