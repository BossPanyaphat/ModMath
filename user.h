// Name : Panyaphat Pipatsaraphan
// ID : 68070503438

#ifndef USER_H
#define USER_H

#define MAX_USERNAME 50
#define MAX_PASSWORD 50

int registerUser();

int loginUser(char *username);

int usernameExists(const char *username);

int validatePassword(const char *username, const char *password);


#endif

