#ifndef LIST_H        
#define LIST_H

#include <stdio.h>
#include <conio.h>

//font styles MACROS
#define BOLD        "\x1b[1m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\x1b[4m"
#define RESET       "\x1b[0m"

//font COLOR MACROS
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define CYAN        "\033[0;36m"
#define WHITE       "\x1b[37m"
#define ORANGE      "\x1b[38;5;202m"
#define MAGENTA     "\033[0;35m"
#define GRAY        "\x1b[38;5;243m"
#define GOLD        "\033[38;2;255;215;0m"
#define INDIGO      "\033[38;2;75;0;130m"
#define VIOLET      "\033[38;2;238;130;238m"
#define BROWN       "\033[38;2;132;60;19m"
#define PINK        "\033[38;2;255;100;180m"
#define OLIVE       "\033[38;2;128;128;0m"
#define TANGERINE   "\033[38;2;255;69;0m"
#define LIME        "\033[38;2;154;205;50m"
#define TURQUOISE   "\033[38;2;72;209;204m"
#define PURPLE      "\033[38;2;130;105;219m"

// ANSI escape code to move the cursor up
#define MOVE_CURSOR_UP(n) printf("\x1b[%dA", (n))

// Function to clear the screen
void clearScreen(int clearAll);

// Function to set heading color
void setHeadingColor(const char* color);

// Function to set selection highlight color
void setSelectionColor(const char* color);

// Function to set not selected color
void setNotSelectedColor(const char* color);

// Function to display the list with highlighting
void displayMenu(const char *options[], int numOptions, int highlight);

// Function to return the selected index
int displayList(const char *options[], int totalOption);

// A function with predefined list to suggest user what to do next
int exitMenu();

#endif 
