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

#ifndef QUIZZER_QUESTION_H
#define QUIZZER_QUESTION_H

#include <cstdio>

namespace quizzer {
    const int MAX_TEXT_QUESTION = 1024;
    const int MAX_TEXT_ANSWER = 128;
    const int MAX_ANSWERS = 10;

    struct Answers {
        char AnswerBody[MAX_TEXT_ANSWER];
        bool CorrectAnswer;
    };

    struct Question {
        int QuestionNumber;
        char QuestionType[3];
        char QuestionBody[MAX_TEXT_QUESTION];
        int UserAnswer;
        Answers answers[MAX_ANSWERS];
    };

    void ReadQuestion(FILE *file, struct Question *question);
    int IsQuestionValid(Question *question);
    void DisplayAnswerBody(char AnswerBody[]);
}

#endif