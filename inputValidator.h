#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

// Function to set prompt color
void setPromptColor(const char* color);

// Function to clear the current line and reset cursor position
void clearLine();

// Function to convert a dynamically allocated string to a doubleand then free the string itself
double stof(char *s);

// Function to convert a dynamically allocated string to an integer and then free the string itself
int stoi(char *s);
 
// Function to check integers
int isInteger(const char *input);

// Function to check postive integers
int isPositiveInteger(const char *input);

// Function to check positive floats
int isPositiveFloat(const char *input);

// Function to check floats
int isFloat(const char *input);

// Function to check Binary digits
int isBinary(const char *input);

// Function to check Octal digits
int isOctal(const char *input);

// Function to check Hexadecimal digits
int isHexadecimal(const char *input);

// Function to check number entered is in the range of month
int isMonth(const char *input);

// Function to check number entered is in the range of day
int isDay(const char *input);

// Function to only allow valid input
char* inputValidator(const char *prompt, char *allowedType, int size);

void clearPreviousLine();

#endif