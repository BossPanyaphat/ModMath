#ifndef QUIZ_H
#define QUIZ_H

/* Start a quiz for the given topic */
int startQuiz(const char *username, const char *topic);

/* Load questions from quiz.csv for specific topic */
int loadQuestions(const char *topic, char questions[][200], char answers[][50], int maxQuestions);

/* Save quiz score to scores.csv */
void saveScore(const char *username, const char *topic, int score);

/* Get current attempt number for user and topic */
int getAttemptNumber(const char *username, const char *topic);

#endif