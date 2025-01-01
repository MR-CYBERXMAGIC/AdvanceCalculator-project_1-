#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "list.h"
#include "ageManipulation.h"

const char *promptColor = WHITE;

// Function to convert a dynamically allocated string to a doubleand then free the string itself
double stof(char *s) {
    double f = atof(s); // Convert the string to a double using atof 
    free(s); // Free the dynamically allocated memory for the input string
    return f; // Return the converted double value
}

// Function to convert a dynamically allocated string to an integer and then free the string itself
int stoi(char *s) {
    int i = atoi(s); // Convert the string to an integer using atoi
    free(s); // Free the dynamically allocated memory for the input string
    return i; // Return the converted integer value
}

// Function to convert a dynamically allocated string to an long long integer and then free the string itself
long long int stoll(char *s) {
    long long int i = atoll(s); // Convert the string to an long long integer using atoll
    free(s); // Free the dynamically allocated memory for the input string
    return i; // Return the converted long long integer value
}

// Function to set prompt color
void setPromptColor(const char *color) {
    promptColor = color;
}

// Function to clear the current line and reset cursor position
void clearLine() {
    printf("\r");     // Move cursor to the beginning of the line
    printf("\033[K"); // Clear the entire line from cursor position
}

// Function to check integers
int isInteger(const char *input) {
    int i = 0;
    if (input[0] == '-') { // Negative number checker
        i++;
    }
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check postive integers
int isPositiveInteger(const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check floats
int isFloat(const char *input) {
    int i = 0;
    int dot = 0;
    if (input[0] == '-') { // Negative number checker
        i++;
    }
    while (input[i] != '\0') {
        if (input[i] == '.') { // Decimal point checker
            dot++;
            if (dot > 1) {
                return 0; // Allows only one decimal point
            }
        } else if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check positive floats
int isPositiveFloat(const char *input) {
    int i = 0;
    int dot = 0;
    while (input[i] != '\0') {
        if (input[i] == '.') { // Decimal point checker
            dot++;
            if (dot > 1) {
                return 0; // Allows only one decimal point
            }
        } else if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check Binary digits
int isBinary(const char *input) {
    int i = 0;
    if (input[0] == '-') { // Negative number checker
        i++;
    }
    while (input[i] != '\0') {
        if (input[i] != '1' && input[i] != '0') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check Octal digits
int isOctal(const char *input) {
    int i = 0;
    if (input[0] == '-') { // Negative number checker
        i++;
    }
    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '7') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check Hexadecimal digits
int isHexadecimal(const char *input) {
    int i = 0;
    if (input[0] == '-') { // Negative number checker
        i++;
    }
    while (input[i] != '\0') {
        if (!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F'))) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check number entered is in the range of month
int isMonth(const char *input) {

    if (isPositiveInteger(input)) {
        int month = atoi(input);

        if ((currentYear == year) && (month >= 1 && month <= currentMonth)) {
            return 1;
        } else if ((currentYear != year) && (month >= 1 && month <= 12)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Function to check number entered is in the range of day
int isDay(const char *input) {

    if (isPositiveInteger(input)) {
        int day = atoi(input);

        if ((year == currentYear) && (month == currentMonth) && 
            (day >= 1 && day <= currentDay)) {
            return 1;
        } else if  ((year != currentYear) ||
                    (year == currentYear && month != currentMonth) &&
                    (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
                    (day >= 1 && day <= 31)) {
            return 1;
        } else if  ((year != currentYear) ||
                    (year == currentYear && month != currentMonth) &&
                    (month == 4 || month == 6 || month == 9 || month == 11 ) &&
                    (day >= 1 && day <= 30)) {
            return 1;
        } else if  ((year != currentYear) || 
                    (year == currentYear && month != currentMonth) &&
                    (month == 2) ) {
                        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) &&
                        (day >= 1 && day <= 29)) {
                            return 1;    
                        } else if (day >= 1 && day <= 28) {
                            return 1;
                        } else {
                            return 0;
                        }                
        } else {
            return 0;
        }
    } else  {
        return 0;
    }
    
}

// Function to check number entered is in the range of day
int isYear(const char *input) {
    
    if (isPositiveInteger(input)) {
        int year = atoi(input);
        if (year >= 0 && year <= currentYear) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }    
    
}

// Function only allow to enter limited number of input
char *limitedInput(char *input, int size) {
    int i = 0;
    while (1) {
        char ch = getch();

        if (ch == 13) {  // Enter key
            input[i] = '\0'; // Null-terminate the string
            return input;
        } else if (ch == 8 && i > 0) { // Backspace
            i--;
            printf("\b \b"); // Erase the last character on screen
        } else if(ch == 'H' || ch == 'P' || ch == 'K' || ch == 'M'){

        } else if (i >= 0 && i < size && ch >= 32 && ch <= 126) { // Check for printable characters
            input[i++] = ch;
            putchar(ch); // Display character on screen
        }
    }
}

// Function to only allow valid input
char *inputValidator(const char *prompt, char *allowedType, int size) {
    char *input = (char *)malloc((size + 1) * sizeof(char));
    int valid = 0;

    while (!valid) {

        clearLine();
        printf("%s%s%s", promptColor, prompt, RESET); // Print prompt on the same line
        limitedInput(input, size);

        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';

        // Validate input based on allowed types and range
        if ((strcmp(allowedType, "I") == 0 && isInteger(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if ((strcmp(allowedType, "P") == 0 && isPositiveInteger(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "F") == 0 && (isFloat(input) || isInteger(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "PF") == 0 && (isPositiveFloat(input) || isPositiveInteger(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        }else if (strcmp(allowedType, "B") == 0 && (isBinary(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "O") == 0 && (isOctal(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "H") == 0 && (isHexadecimal(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "D") == 0 && (isDay(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "M") == 0 && (isMonth(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else if (strcmp(allowedType, "Y") == 0 && (isYear(input))) {

            clearLine();
            setPromptColor(GREEN);
            printf("%s%s%s", promptColor, prompt, RESET);
            puts(input);
            valid = 1;
        } else {

            clearLine(); // Clear invalid input
            setPromptColor(RED);
        }
    }
    return input;
}

void clearPreviousLine() {
    printf("\x1b[1F"); // Move to beginning of previous line
    printf("\x1b[2K"); // Clear entire line
}



