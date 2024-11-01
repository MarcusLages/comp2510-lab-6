//
// Created by marcu on 17/10/2024.
//
#ifndef STUDENT_IO_H
#define STUDENT_IO_H

#define MAX_LINE_SIZE   256

#include <stdio.h>
#include "student.h"

enum StudentOutputOption {
   OPTION_ONLY_DOMESTIC,
   OPTION_ONLY_INTERNATIONAL,
   OPTION_ALL
};
typedef enum StudentOutputOption StudentOutputOption;

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
void IOStudentsFiles(FILE *ptrIn, FILE *ptrOut, int option);

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
void appendStudentTo(Student currStudent, FILE *ptrOut, int option);

/**
 * Function used to return a new and empty output file in append mode.
 *
 * @param outputFile name of the output file
 * @return pointer to a FILE buffer of the output file.
 *         Returns null if there was an error cleaning or oppening the file.
 */
FILE* openOutputFile(char *outputFile);

/**
 * Check for errors in the Student structure and prints to the file the error
 * accordingly.
 *
 * @param student student to check for errors
 * @param errorOutput buffer for outputting errors
 * @return 1 if there's any errors
 */
int checkErrors(const Student student, FILE *errorOutput);

/**
 * Function used to close and deallocate memory for input and output files.
 *
 * @param ptrIn input file
 * @param ptrOut output file
 */
void closeFiles(FILE *ptrIn, FILE *ptrOut);

#endif //STUDENT_IO_H
