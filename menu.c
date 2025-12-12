#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "topics.h"
#include "leaderboard.h"

/* Clear screen function (cross-platform) */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Pause and wait for user input */
void pauseScreen() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

/* Display login/register menu */
int displayAuthMenu() {
    int choice;
    clearScreen();
    printf("========================================\n");
    printf("   AUTHENTICATION MENU\n");
    printf("========================================\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    return choice;
}

/* Display topic selection menu */
int displayTopicMenu() {
    int choice;
    clearScreen();
    printf("========================================\n");
    printf("   SELECT A MATH TOPIC\n");
    printf("========================================\n");
    printf("1. Arithmetic\n");
    printf("2. Algebra\n");
    printf("3. Number Theory\n");
    printf("4. Back to Main Menu\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    return choice;
}

/* Display exit confirmation */
int confirmExit() {
    char choice;
    printf("\nAre you sure you want to exit? (y/n): ");
    scanf(" %c", &choice);
    while (getchar() != '\n');
    return (choice == 'y' || choice == 'Y');
}

/* Display the main menu and handle user choices */
void displayMainMenu(const char *username) {
    int choice, topicChoice;
    int running = 1;
    
    while (running) {
        clearScreen();
        printf("========================================\n");
        printf("   MAIN MENU\n");
        printf("========================================\n");
        printf("Logged in as: %s\n", username);
        printf("========================================\n");
        printf("1. Start Learning (Choose Topic)\n");
        printf("2. View Leaderboard\n");
        printf("3. Logout\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                topicChoice = displayTopicMenu();
                if (topicChoice >= 1 && topicChoice <= 3) {
                    launchTopic(topicChoice, username);
                }
                break;
            case 2:
                clearScreen();
                displayLeaderboard();
                pauseScreen();
                break;
            case 3:
                if (confirmExit()) {
                    running = 0;
                }
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pauseScreen();
        }
    }
}