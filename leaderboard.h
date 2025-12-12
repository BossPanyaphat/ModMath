#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#define MAX_USERS 100

/* Structure to hold user score data */
typedef struct {
    char username[50];
    int totalScore;
    int totalAttempts;
} UserScore;

/* Display the leaderboard */
void displayLeaderboard();

/* Calculate total scores for all users */
int calculateTotalScores(UserScore users[], int maxUsers);

/* Sort users by total score (descending) */
void sortUsersByScore(UserScore users[], int count);

#endif