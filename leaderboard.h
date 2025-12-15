// Name : Nattaya Seangon
// ID : 68070503420

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#define MAX_USERS 100

//User score data structure 
typedef struct {
    char username[50];
    int totalScore;
    int totalAttempts;
} UserScore;

void displayLeaderboard();

int calculateTotalScores(UserScore users[], int maxUsers, const char *topic);

void sortUsersByScore(UserScore users[], int count);

#endif



