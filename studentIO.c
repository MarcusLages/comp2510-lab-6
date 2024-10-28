#include <stdlib.h>
#include "studentIO.h"

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

void closeFiles(FILE *ptrIn, FILE *ptrOut) {
    fclose(ptrIn);
    ptrIn = NULL;

    fclose(ptrOut);
    ptrOut = NULL;
}