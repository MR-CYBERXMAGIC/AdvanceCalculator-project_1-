#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"
#include "inputValidator.h"
#include "simpleCalculator.h"
#include "menu.h"

// Function to perform addition
void sum() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>addition\n\n%s", OLIVE, RESET);
    
    // Get two input numbers for addition
    setPromptColor(YELLOW);
    double num1 = stof(inputValidator("Enter number1:", "F", 15));
    setPromptColor(YELLOW);
    double num2 = stof(inputValidator("Enter number2:", "F", 15));
    
    // Calculate and display the sum
    double sumVar = num1 + num2;
    printf("\n%sthe Sum is : %lf\n%s", CYAN, sumVar, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sum();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to perform subtraction
void subtract() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>subtraction\n\n%s", OLIVE, RESET);
    
    // Get two input numbers for subtraction
    setPromptColor(YELLOW);
    double num1 = stof(inputValidator("Enter number1:", "F", 15));
    setPromptColor(YELLOW);
    double num2 = stof(inputValidator("Enter number2:", "F", 15));

    // Calculate and display the difference
    double sub = num1 - num2;
    printf("\n%sthe difference is : %f\n%s", CYAN, sub, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            subtract();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to find and remove the decimal point from a number string
int findDecimalPosition(char *numStr) {
    int len = strlen(numStr);
    int pointPos = 0;

    for (int i = 0; i < len; i++) {
        if (numStr[i] == '.') {
            pointPos = len - i - 1; // Count digits after the decimal point
            // Shift digits to the left to remove the decimal point
            for (int j = i; j < len; j++) {
                numStr[j] = numStr[j + 1];
            }
            break;
        }
    }

    return pointPos; // Return the number of digits after the decimal
}

// Function to perform multiplication
void multiply() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>multiplication\n\n%s", OLIVE, RESET);
    
    // Get two input numbers for multiplication
    setPromptColor(YELLOW);
    char *num1 = inputValidator("Enter any number1:", "F", 20);
    setPromptColor(YELLOW);
    char *num2 = inputValidator("Enter any number2:", "F", 20);

    // Find and remove decimal points, and calculate total decimal positions
    int decimalPos1 = findDecimalPosition(num1);
    int decimalPos2 = findDecimalPosition(num2);
    int totalDecimalPos = decimalPos1 + decimalPos2;
    
    // Get the lengths of the modified strings
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result[100] = {0};     // Array to store the result of multiplication

    // Perform multiplication digit by digit
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int prod = (num1[i] - '0') * (num2[j] - '0');
            int pos = (len1 - 1 - i) + (len2 - 1 - j);

            result[pos] += prod;

            // Handle carry
            result[pos + 1] += result[pos] / 10;
            result[pos] %= 10;
        }
    }
    // Find the size of the result array
    int resultSize = len1 + len2;
    while (resultSize > 0 && result[resultSize - 1] == 0) {
        resultSize--; // Remove leading zeros
    }


    // Print the result in reverse order, inserting the decimal point if needed
    printf("%s\nThe product is: ",CYAN);
    int decimalInserted = 0;

     // Handle the case where the result is smaller than 1 (e.g., 0.000123)
    if (totalDecimalPos > resultSize) {
        printf("0.");
        for (int i = 0; i < totalDecimalPos - resultSize; i++) {
            printf("0");
        }
    }

    for (int i = resultSize - 1; i >= 0; i--) {
        if (i == totalDecimalPos - 1 ) {
            printf(".");
            decimalInserted = 1;
        }
        printf("%d", result[i]);
    }
    printf("\n%s",RESET);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            multiply();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to perform division
void divide() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>division\n\n%s", OLIVE, RESET);
    
    // Get two input numbers for division
    setPromptColor(YELLOW);
    double num1 = stof(inputValidator("Enter number1:", "F", 15));
    setPromptColor(YELLOW);
    double num2 = stof(inputValidator("Enter number2:", "F", 15));
    
    // Calculate and display the quotient
    double div = num1 / num2;
    printf("\n%sthe quotient is : %lf\n%s", CYAN, div, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            divide();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to calculate remainder (modulus)
void reminder() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>division\n\n%s", OLIVE, RESET);
    
    // Get two integer input numbers for modulus operation
    setPromptColor(YELLOW);
    long long int num1 = atoll(inputValidator("Enter number1:", "I", 15));
    setPromptColor(YELLOW);
    long long int num2 = atoll(inputValidator("Enter number2:", "I", 15));

    // Calculate and display the remainder
    long long int rem = num1 % num2;
    printf("\n%sthe remainder is : %lld\n%s", CYAN, rem, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            reminder();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to calculate the N-th root of a number
void nthRoot() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>N-th Root\n\n%s", OLIVE, RESET);
    
    // Get input number and power for N-th root calculation
    setPromptColor(YELLOW);
    double num = stof(inputValidator("Enter any number:", "F", 10));
    setPromptColor(YELLOW);
    float power = stof(inputValidator("Enter power of root:", "I", 2));     

    // Calculate and display the N-th root
    double root = pow(num, 1.0 / power);
    printf("%s\nthe Nth-root is %lf%s", CYAN, root, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            nthRoot();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}

// Function to calculate power of a number
void power() {
    clearScreen(1);
    printf("%smainMenu>simpleCalculator>Power\n\n%s", OLIVE, RESET);
    
    // Get input number and exponent
    setPromptColor(YELLOW);
    double num = stof(inputValidator("Enter any number:", "F", 10));
    setPromptColor(YELLOW);
    int powerVar = stoi(inputValidator("Enter power:", "I", 2));     

    // Calculate and display the result of the power operation
    double ans = pow(num, powerVar);
    printf("%s\nthe result is %lf%s", CYAN, ans, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            power();
            break;
        case 1: case -1:
            simpleCalculator();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
    }
}
