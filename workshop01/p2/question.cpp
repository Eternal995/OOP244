/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : May 22, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "question.h"
#include <iostream>

using namespace std;
using namespace quizzer;

namespace quizzer {
    void ReadQuestion(FILE *file, Question *question) {

        char temp = fgetc(file); // this part make sure code work for first question in the quiz
        if (temp != '{')
            ungetc(temp, file);

        fscanf(file, "%2[A-Za-z]}", question->QuestionType);

        fscanf(file, " %[^\n]\n", question->QuestionBody);

        int i = 0;

        while (fgetc(file) == '[') {
            fscanf(file, "%[^\n]\n", question->answers[i].AnswerBody);
            if (question->answers[i].AnswerBody[0] == 'X')
                question->answers[i].CorrectAnswer = true;
            i++;
        }
    }

    int IsQuestionValid(Question *question) {

        int count = 0;
        int i = 0;

        for (i = 0; question->answers[i].AnswerBody[0] != '\0'; i++) {
            if (question->answers[i].AnswerBody[0] == 'X')
                count++;
        }

        cout << "Question " << question->QuestionNumber;

        if ((question->QuestionType[1] == 'a' && count >= 1) || (question->QuestionType[1] == 'c' && count == 1)) {
            // cout << "Question " << question->QuestionNumber << " -> OK" << endl;
            cout << " -> OK" << endl;
            return 0;
        }

        else {
            // cout << "Question " << question->QuestionNumber << " -> ERROR" << endl;
            cout << " -> ERROR" << endl;
            return 1;
        }
    }

    void DisplayAnswerBody(char AnswerBody[]) {

        for (int i = 3; AnswerBody[i] != '\0'; i++) {
            cout << AnswerBody[i];
        }

        cout << endl;
    }
}
