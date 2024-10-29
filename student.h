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
// Enumerations
enum StudentDataOrder {
    DATA_FIRST_NAME,
    DATA_LAST_NAME,
    DATA_GPA,
    DATA_STATUS,
    DATA_TOEFL
};
typedef enum StudentDataOrder StudentDataOrder;

// ---------------------------------
// Structures and Unions

/**
 * Structure that represents a Domestic student information.
 */
struct DomesticStudent {
    char *firstName;
    char *lastName;
    float GPA;
};

/**
 * Structure that represents an International student information.
 */
struct InternationalStudent {
    char *firstName;
    char *lastName;
    float GPA;
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
    StudentInfo info;
};

typedef struct Student Student;

// ---------------------------------
// Function prototypes

/**
 * Function used to get data from a string into a Student structure.
 *
 * @param currLine a string line
 * @return Student object data created from the data in the given line
 */
Student getStudentFromLine(char *currLine);

/**
 * Function that checks if a student is international or domestic.
 *
 * @param studentInfo string containing information about the student's status
 * @return 0 if student is domestic,
 *         != 0 if student is international
 */
int isStudentInternational(const char *studentInfo);

/**
* Function that returns a string with information about the input student.
*
* @param student student structure that will have its
*/
char* getStudentInformation(const Student student);

/**
 * Function that returns a student with blank/dummy information used for
 * initialization.
 *
 * @attention isInternational, .info.international.GPA and .TOEFL fields are initialized as -1,
 *
 * @return blank student with dummy information
 */
Student getBlankStudent();

#define STUDENT_H

#endif //STUDENT_H
