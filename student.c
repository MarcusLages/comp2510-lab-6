//
// Created by marcu on 17/10/2024.
//
#include <string.h>
#include <stdlib.h>

#include "student.h"

# define STUDENT_STRING_LIMIT 50

Student getStudentFromLine(char *currLine) {
    Student student = getBlankStudent();
    char *studentInfo = strtok(currLine, " ");
    int dataCounter = DATA_FIRST_NAME;

    // Goes through every tokenized word in the line and stores the data
    // into its specific Student structure parameter
    while(studentInfo != NULL && dataCounter <= DATA_TOEFL) {
        switch(dataCounter) {
            case DATA_FIRST_NAME:
                student.info.domestic.firstName = studentInfo;
                break;
            case DATA_LAST_NAME:
                student.info.domestic.lastName = studentInfo;
                break;
            case DATA_GPA:
                student.info.domestic.GPA = atoi(studentInfo);
                break;
            case DATA_STATUS:
                student.isInternational = isStudentInternational(studentInfo);
                break;
            case DATA_TOEFL:
                student.info.international.TOEFL = atof(studentInfo);
                break;
            default:
                perror("Error on getting student info.");
                exit(EXIT_FAILURE);
        }

        studentInfo = strtok(NULL, " ");
        dataCounter++;
    }

    return student;
}

int isStudentInternational(const char *studentInfo) {
    if(studentInfo == NULL || studentInfo[0] == '\0') {
        perror("Student info not found. Cannot check if student is international.\n");
        exit(EXIT_FAILURE);
    }

    return (studentInfo[0] == 'I' || studentInfo[0] == 'i');
}

char* getStudentInformation(const Student student) {
    char *info = (char *) malloc(STUDENT_STRING_LIMIT * sizeof(char) + 1);

    if(!student.isInternational) {
        sprintf(info, "%s %s %.2f %c\n",
            student.info.domestic.firstName,
            student.info.domestic.lastName,
            student.info.domestic.GPA,
            'D');
    } else {
        sprintf(info, "%s %s %.2f %c %d\n",
            student.info.international.firstName,
            student.info.international.lastName,
            student.info.international.GPA,
            'I',
            student.info.international.TOEFL);
    }

    return info;
}

Student getBlankStudent() {
    return (Student) {
        .isInternational = -1,
        .info.international = (InternationalStudent) {
            .firstName = NULL,
            .lastName = NULL,
            .GPA = -1,
            .TOEFL = -1,
        }
    };
}