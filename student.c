//
// Created by marcu on 17/10/2024.
//
#include <string.h>
#include <stdlib.h>

#include "student.h"


Student getStudentFromLine(char *currLine) {
    Student student = getBlankStudent();
    char *studentInfo = strtok(currLine, " ");
    int dataCounter = DATA_FIRST_NAME;

    while(studentInfo != NULL && dataCounter <= DATA_TOEFL) {
        // TODO: I might need to duplicate the strings instead of just assigning them.
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
                break;
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