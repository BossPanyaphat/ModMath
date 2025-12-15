// Name : Nattaya Seangon
// ID : 68070503420

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#define MAX_USERS 100

/* Structure to hold user score data */
typedef struct {
    char username[50];
    int totalScore;
    int totalAttempts;
} UserScore;

/* Display the leaderboard with topic selection */
void displayLeaderboard();

/* Calculate total scores for all users for a specific topic */
int calculateTotalScores(UserScore users[], int maxUsers, const char *topic);

/* Sort users by total score (descending) */
void sortUsersByScore(UserScore users[], int count);

#endif


