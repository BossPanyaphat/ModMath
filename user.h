#ifndef USER_H
#define USER_H

#define MAX_USERNAME 50
#define MAX_PASSWORD 50

/* Register a new user */
int registerUser();

/* Login existing user */
int loginUser(char *username);

/* Check if username already exists */
int usernameExists(const char *username);

/* Validate password for given username */
int validatePassword(const char *username, const char *password);

#endif