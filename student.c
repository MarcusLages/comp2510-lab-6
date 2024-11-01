//
// Created by marcu on 17/10/2024.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "student.h"

#define STUDENT_STRING_LIMIT 50
#define BASE_10 10
#define TOKEN_DELIMITERS " \t\n\v\f\r"

Student getStudentFromLine(char *currLine) {
    Student student = getBlankStudent();
    char *studentInfo = strtok(currLine, TOKEN_DELIMITERS);
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
                char *gpaError;
                student.info.domestic.GPA = strtod(studentInfo, &gpaError);
                if((*gpaError != '\n') && (*gpaError != '\0' || gpaError == studentInfo)) {
                    student.info.domestic.GPA = STUDENT_ERROR_CODE;
                    errno = 0;
                }
                break;
            case DATA_STATUS:
                student.isInternational = isStudentInternational(studentInfo);
                break;
            case DATA_TOEFL:
                char *toeflError;
                student.info.international.TOEFL = strtol(studentInfo, &toeflError, BASE_10);
                if((*toeflError != '\n') && (*toeflError != '\0' || toeflError == studentInfo)) {
                    student.info.international.TOEFL = STUDENT_ERROR_CODE;
                    errno = 0;
                }
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

    if (studentInfo[0] == 'I' || studentInfo[0] == 'i') {
        return 1;
    }

    if(studentInfo[0] == 'D' || studentInfo[0] == 'd') {
        return 0;
    }

    // If not I/i or D/d, then send error code.
    return STUDENT_ERROR_CODE;
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
        .isInternational = STUDENT_ERROR_CODE,
        .info.international = (InternationalStudent) {
            .firstName = NULL,
            .lastName = NULL,
            .GPA = STUDENT_ERROR_CODE,
            .TOEFL = STUDENT_ERROR_CODE,
        }
    };
}