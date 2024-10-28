//
// Created by marcu on 17/10/2024.
//
#ifndef STUDENT_IO_H
#define STUDENT_IO_H

#define MAX_LINE_SIZE   256

#include <stdio.h>
#include "student.h"

/**
 * Function used to filter an input file containing Student information and store it into
 * an output file.
 * 
 * @param ptrIn input file that will be filtered
 * @param ptrOut output file that will be written with the filtered version of the input file
 * @param option filtering mode of the input file
 *               (1 if only domestic students,
 *               2 if only international students,
 *               3 if all students)
 */
void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, char *option);

/**
 * Function used to append (save) a Student structure to a .txt file.
 *
 * @param currStudent Student data to be appended to
 * @param ptrOut file which student will be appended to
 * @param option filtering mode of the output file
 *               (1 if only domestic students,
 *               2 if only international students,
 *               3 if all students)
 */
void appendStudentTo(Student *currStudent, FILE *ptrOut, char *option);

/**
 * Function used to return a new and empty output file in append mode.
 *
 * @param outputFile name of the output file
 * @return pointer to a FILE buffer of the output file.
 *         Returns null if there was an error cleaning or oppening the file.
 */
FILE* openOutputFile(char *outputFile);

/**
 * Function used to close and deallocate memory for input and output files.
 *
 * @param ptrIn input file
 * @param ptrOut output file
 */
void closeFiles(FILE *ptrIn, FILE *ptrOut);

#endif //STUDENT_IO_H
