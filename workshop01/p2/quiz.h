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

#ifndef QUIZZER_QUIZ_H
#define QUIZZER_QUIZ_H

namespace quizzer {
    const int MAX_QUESTIONS = 60;
    int LoadQuiz(const char *filename);
    int IsQuizValid();
    int HasMoreQuestions();
    void ShowNextQuestion();
    void ShowQuizResults();
}

#endif