#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "topics.h"
#include "leaderboard.h"

int main() {
    char username[MAX_USERNAME];
    int authChoice, loggedIn = 0;
    
    printf("========================================\n");
    printf("   BASIC MATH LEARNING PROGRAM\n");
    printf("========================================\n\n");
    
    /* Authentication loop */
    while (!loggedIn) {
        authChoice = displayAuthMenu();
        
        switch (authChoice) {
            case 1:
                if (loginUser(username)) {
                    loggedIn = 1;
                    printf("\nLogin successful! Welcome, %s!\n", username);
                    pauseScreen();
                } else {
                    printf("\nLogin failed. Please try again.\n");
                    pauseScreen();
                }
                break;
            case 2:
                if (registerUser()) {
                    printf("\nRegistration successful! Please login.\n");
                    pauseScreen();
                } else {
                    printf("\nRegistration failed. Please try again.\n");
                    pauseScreen();
                }
                break;
            case 3:
                printf("\nThank you for using the Math Learning Program!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pauseScreen();
        }
    }
    
    /* Main program loop after login */
    displayMainMenu(username);
    
    printf("\nThank you for using the Math Learning Program, %s!\n", username);
    return 0;
}