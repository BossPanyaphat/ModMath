// Name : Nicharee Surakavanichakorn
// ID : 68070503423

#ifndef MENU_H
#define MENU_H

// Display the main menu and handle user choices
void displayMainMenu(const char *username);

// Display login/register menu
int displayAuthMenu();

// Display topic selection menu 
int displayTopicMenu();

// Display exit confirmation 
int confirmExit();

// Clear screen function (cross-platform) 
void clearScreen();

// Pause and wait for user input 
void pauseScreen();


#endif
