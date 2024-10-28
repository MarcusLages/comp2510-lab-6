//
// Created by marcu on 17/10/2024.
//
#ifndef STUDENT_H
#include <stdio.h>

// STEPS
// 1. STRUCTURES
// 2. parsesStudentInfo / processStudent
// 3. Read each line of input.txt
// 4. statements to filter and select options 1-3
// 5. read from file and call function read/write
// 6.

// ---------------------------------
// Structures and Unions

/**
 * Structure that represents a Domestic student information.
 */
struct DomesticStudent {
    char *firstName;
    char *lastName;
    float GPA;
    char status;
};

/**
 * Structure that represents an International student information.
 */
struct InternationalStudent {
    char *firstName;
    char *lastName;
    float GPA;
    char status;
    int TOEFL;
};

typedef struct DomesticStudent DomesticStudent;
typedef struct InternationalStudent InternationalStudent;

/**
 * Union used to store information of a Domestic or International student information.
 */
union StudentInfo {
    DomesticStudent domestic;
    InternationalStudent international;
};

typedef union StudentInfo StudentInfo;

/**
 * Structure used to store information about a student information.
 * The student's information is different based if they are international or not, which
 * is represented by the StudentInfo union, which you must check the variable "isInternational"
 * to be able to determine the type of the student first.
 */
struct Student {
    int isInternational;
    StudentInfo stuInfo;
};

typedef struct Student Student;

// ---------------------------------
// Function prototypes

/**
 *
 * @param currLine a string line
 * @return Student object represented by that line
 */
Student* getStudentFromLine(char *currLine);

#define STUDENT_H

#endif //STUDENT_H
