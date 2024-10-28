//
// Created by marcu on 17/10/2024.
//
#ifndef STUDENT_IO_H
#define STUDENT_IO_H

#define MAX_LINE_SIZE   256

#include <stdio.h>
#include "student.h"

void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, char *option);
void appendStudentTo(Student *currStudent, FILE *ptrOut, char *option);
void closeFiles(FILE *ptrIn, FILE *ptrOut);

#endif //STUDENT_IO_H
