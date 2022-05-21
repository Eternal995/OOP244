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
#include "quiz.h"
#include "question.h"
#include <cstdio>
#include <iostream>

using namespace std;
using namespace quizzer;

namespace quizzer {

    Question question[MAX_QUESTIONS] = {0};

    int CurrentQuestion = 0;

    int LoadQuiz(const char *filename) {

        Question zeros = {0}; // resetting the question structure array

        for (int i = 0; question[i].QuestionNumber != 0; i++) {
            question[i] = zeros;
        }

        CurrentQuestion = 0; // resetting the current display question

        FILE *fp = nullptr;

        fp = fopen(filename, "r");

        int i = 0;

        if (fp != NULL) {
            while (!feof(fp)) {
                ReadQuestion(fp, &question[i]);
                question[i].QuestionNumber = i + 1;
                i++;
            }
            fclose(fp);
        }

        else {
            return 1; // return 1 if unable to load file
        }

        return 0;
    }

    int IsQuizValid() {

        if (question[4].QuestionNumber == 0)
            return 0; // return 0 if quiz contain less than 5 questions

        int count = 0;
        int i = 0;

        for (i = 0; question[i].QuestionNumber != 0; i++) {
            count += IsQuestionValid(&question[i]);
        }

        if (count == 0)
            return 1;
        else
            return 0;
    }

    int HasMoreQuestions() {
        if (question[CurrentQuestion].QuestionNumber != 0)
            return 1;

        else
            return 0;
    }

    void ShowNextQuestion() {

        cout << question[CurrentQuestion].QuestionBody << endl;

        for (int i = 0; question[CurrentQuestion].answers[i].AnswerBody[0] != '\0'; i++) {
            cout << i + 1 << ". ";
            DisplayAnswerBody(question[CurrentQuestion].answers[i].AnswerBody);
        }

        cout << "Your answer? ";

        cin >> question[CurrentQuestion].UserAnswer;

        CurrentQuestion++;
    }

    void ShowQuizResults() {

        if (question[CurrentQuestion].QuestionNumber == 0) {
            int score = 0;
            int total = 0;

            for (int i = 0; question[i].QuestionNumber != 0; i++) {

                if (question[i].answers[question[i].UserAnswer - 1].CorrectAnswer)
                    score++;

                total++;
            }

            cout << "QUIZ RESULTS: your score is " << score << "/" << total << "." << endl;
        }
    }
}