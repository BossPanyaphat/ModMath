// Name : Panyaphat Pipatsaraphan
// ID : 68070503438

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leaderboard.h"

#define SCORES_FILE "scores.csv"

int calculateTotalScores(UserScore users[], int maxUsers) {
    FILE *file = fopen(SCORES_FILE, "r");
    if (file == NULL) {
        return 0;
    }
    
    char line[200];
    char username[50];
    char topic[50];
    int score, attempts;
    int userCount = 0;
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%d,%d", username, topic, &score, &attempts);
        
        // Find if user already exists in array
        int found = -1;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0) {
                found = i;
                break;
            }
        }
        
        if (found >= 0) {
            //If user exists, add to their score 
            users[found].totalScore += score;
            users[found].totalAttempts += 1;
        } else {
            //If new user, add to array 
            if (userCount < maxUsers) {//ensure the number of user isn't reach the limit
                strcpy(users[userCount].username, username);
                users[userCount].totalScore = score;
                users[userCount].totalAttempts = 1;
                userCount++;
            }
        }
    }
    
    fclose(file);
    return userCount;
}

// Sort users by total score (descending) using Bubble Sort 
void sortUsersByScore(UserScore users[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (users[j].totalScore < users[j + 1].totalScore) {
                // Swap 
                UserScore temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}


void displayLeaderboard() {
    UserScore users[MAX_USERS];
    int userCount = calculateTotalScores(users, MAX_USERS);
    
    printf("========================================\n");
    printf("   LEADERBOARD\n");
    printf("========================================\n\n");
    
    if (userCount == 0) {
        printf("No scores recorded yet.\n");
        printf("Complete some quizzes to appear here!\n");
        return;
    }
    
    // Sort users by score 
    sortUsersByScore(users, userCount);
    
    // Display top rankings 
    printf("%-5s %-20s %-12s %-10s\n", "Rank", "Username", "Total Score", "Attempts");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < userCount && i < 10; i++) {
        printf("%-5d %-20s %-12d %-10d\n", 
               i + 1, 
               users[i].username, 
               users[i].totalScore, 
               users[i].totalAttempts);
    }
    
    printf("\n========================================\n");
}

