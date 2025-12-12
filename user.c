#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define USER_FILE "user.csv"

/* Check if username already exists */
int usernameExists(const char *username) {
    FILE *file = fopen(USER_FILE, "r");
    if (file == NULL) {
        return 0; /* File doesn't exist, so username doesn't exist */
    }
    
    char line[200];
    char storedUsername[MAX_USERNAME];
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,]", storedUsername);
        if (strcmp(storedUsername, username) == 0) {
            fclose(file);
            return 1; /* Username exists */
        }
    }
    
    fclose(file);
    return 0; /* Username doesn't exist */
}

/* Validate password for given username */
int validatePassword(const char *username, const char *password) {
    FILE *file = fopen(USER_FILE, "r");
    if (file == NULL) {
        return 0;
    }
    
    char line[200];
    char storedUsername[MAX_USERNAME];
    char storedPassword[MAX_PASSWORD];
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%s", storedUsername, storedPassword);
        if (strcmp(storedUsername, username) == 0) {
            fclose(file);
            return strcmp(storedPassword, password) == 0;
        }
    }
    
    fclose(file);
    return 0;
}

/* Register a new user */
int registerUser() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char confirmPassword[MAX_PASSWORD];
    
    printf("\n========================================\n");
    printf("   USER REGISTRATION\n");
    printf("========================================\n");
    
    printf("Enter username: ");
    scanf("%s", username);
    
    /* Check if username already exists */
    if (usernameExists(username)) {
        printf("\nError: Username already exists!\n");
        return 0;
    }
    
    printf("Enter password: ");
    scanf("%s", password);
    
    printf("Confirm password: ");
    scanf("%s", confirmPassword);
    
    /* Check if passwords match */
    if (strcmp(password, confirmPassword) != 0) {
        printf("\nError: Passwords do not match!\n");
        return 0;
    }
    
    /* Save user to file */
    FILE *file = fopen(USER_FILE, "a");
    if (file == NULL) {
        printf("\nError: Could not open user file!\n");
        return 0;
    }
    
    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
    
    return 1;
}

/* Login existing user */
int loginUser(char *username) {
    char password[MAX_PASSWORD];
    
    printf("\n========================================\n");
    printf("   USER LOGIN\n");
    printf("========================================\n");
    
    printf("Enter username: ");
    scanf("%s", username);
    
    /* Check if username exists */
    if (!usernameExists(username)) {
        printf("\nError: Username does not exist!\n");
        return 0;
    }
    
    printf("Enter password: ");
    scanf("%s", password);
    
    /* Validate password */
    if (!validatePassword(username, password)) {
        printf("\nError: Incorrect password!\n");
        return 0;
    }
    
    return 1;
}