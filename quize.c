#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"
#include "menu.h"

#define QUIZ_FILE "quiz.csv"
#define SCORES_FILE "scores.csv"
#define MAX_QUESTIONS 50

//Get current attempt number for user and topic 
int getAttemptNumber(const char *username, const char *topic) {
    FILE *file = fopen(SCORES_FILE, "r");
    if (file == NULL) {
        //if there is not thing in the CSV file that mean it is the first attempt 
        return 1; 
    }
    
    char line[200];
    char storedUsername[50];
    char storedTopic[50];
    int maxAttempt = 0;
    int score, attempts;
    
    while (fgets(line, sizeof(line), file)) {
        //collect the info in the CSV file
        sscanf(line, "%[^,],%[^,],%d,%d", storedUsername, storedTopic, &score, &attempts);
        //find the student and topic that we want to get attempt
        if (strcmp(storedUsername, username) == 0 && strcmp(storedTopic, topic) == 0) {
            //find the hightest attempts ,it mean the last one
            if (attempts > maxAttempt) {
                maxAttempt = attempts;
            }
        }
    }
    
    fclose(file);
    return maxAttempt + 1; //return the current attempt
}

// Save quiz score to scores.csv 
void saveScore(const char *username, const char *topic, int score) {
    FILE *file = fopen(SCORES_FILE, "a");
    if (file == NULL) {
        printf("\nError: Could not save score!\n");
        return;
    }
    int attempts = getAttemptNumber(username, topic); //current attempts
    fprintf(file, "%s,%s,%d,%d\n", username, topic, score, attempts);//store data in CSV file
    fclose(file);
}

// Load questions from quiz.csv for specific topic
int loadQuestions(const char *topic, char questions[][200], char answers[][50], int maxQuestions) {
    FILE *file = fopen(QUIZ_FILE, "r");
    if (file == NULL) {
        printf("\nError: Could not open quiz file!\n");
        return 0;
    }
    
    char line[300];
    char storedTopic[50];
    int count = 0;
    
    while (fgets(line, sizeof(line), file) && count < maxQuestions) {
        //Get the part of the string before the first comma. token = topic
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(storedTopic, token);
            if (strcmp(storedTopic, topic) == 0) {
                // Get question
                //NULL = continue from the last one. token = question
                token = strtok(NULL, ",");
                if (token != NULL) {
                    //store question in the array
                    strcpy(questions[count], token);
                    
                    // Get answer
                    //NULL = continue from the last one. token = answer
                    token = strtok(NULL, "\n");
                    if (token != NULL) {
                        //store answer in the array
                        strcpy(answers[count], token);
                        count++;
                    }
                }
            }
        }
    }
    
    fclose(file);
    return count;
}


int startQuiz(const char *username, const char *topic) {
    char questions[MAX_QUESTIONS][200];
    char answers[MAX_QUESTIONS][50];
    char userAnswer[50];
    int score = 0;
    
    clearScreen();
    printf("========================================\n");
    printf("   %s QUIZ\n", topic);
    printf("========================================\n\n");
    
    int questionCount = loadQuestions(topic, questions, answers, 5);
    
    if (questionCount == 0) {
        printf("Error: No questions available for this topic!\n");
        return 0;
    }
    
    // Limit to 5 questions per topic
    if (questionCount > 5) {
        questionCount = 5;
    }
    
    // Ask each question 
    for (int i = 0; i < questionCount; i++) {
        //print the question that we get from loadQuestion function
        printf("Question %d: %s\n", i + 1, questions[i]);
        printf("Your answer: ");
        scanf("%s", userAnswer);
        while (getchar() != '\n');
        
        // Check answer
        if (strcmp(userAnswer, answers[i]) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %s\n\n", answers[i]);
        }
    }
    
    // Save score
    saveScore(username, topic, score);
    
    return score;
}
