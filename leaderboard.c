// Name : Nattaya Seangon
// ID : 68070503420
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leaderboard.h"

#define SCORES_FILE "scores.csv"

int calculateTotalScores(UserScore users[], int maxUsers, const char *topic) {
    FILE *file = fopen(SCORES_FILE, "r");
    if (file == NULL) {
        return 0;
    }
    
    char line[200];
    char username[50];
    char storedTopic[50];
    int score, attempts;
    int userCount = 0;
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%d,%d", username, storedTopic, &score, &attempts);
        
        // Skip if topic doesn't match 
        if (strcmp(topic, "All") != 0 && strcmp(storedTopic, topic) != 0) {
            continue;
        }
        
        // Find if user already exists 
        int found = -1;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0) {
                found = i;
                break;
            }
        }
        
        if (found >= 0) {
            // User exists, add to their score           users[found].totalScore += score;
            users[found].totalAttempts += 1;
        } else {
            // New user, add to array 
            if (userCount < maxUsers) {
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

// Sort users by total score (Bubble Sort)
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
    int choice;
    const char *selectedTopic = NULL;
    
    printf("\n========================================\n");
    printf("   SELECT LEADERBOARD TOPIC\n");
    printf("========================================\n");
    printf("1. All Topics (Overall)\n");
    printf("2. Arithmetic\n");
    printf("3. Algebra\n");
    printf("4. Number Theory\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    
    switch (choice) {
        case 1:
            selectedTopic = "All";
            break;
        case 2:
            selectedTopic = "Arithmetic";
            break;
        case 3:
            selectedTopic = "Algebra";
            break;
        case 4:
            selectedTopic = "Number Theory";
            break;
        default:
            printf("\nInvalid choice! Showing all topics.\n");
            selectedTopic = "All";
    }
    
    UserScore users[MAX_USERS];
    int userCount = calculateTotalScores(users, MAX_USERS, selectedTopic);
    
    printf("\n========================================\n");
    printf("   LEADERBOARD - %s\n", selectedTopic);
    printf("========================================\n\n");
    
    if (userCount == 0) {
        printf("No scores recorded yet for this topic.\n");
        printf("Complete some quizzes to appear here!\n");
        return;
    }
    
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




