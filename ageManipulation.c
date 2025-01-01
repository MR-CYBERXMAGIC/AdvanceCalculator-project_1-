#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inputValidator.h"
#include "ageManipulation.h"
#include "list.h"

//external variables
int year,month,day,curr,currentDay,currentMonth,currentYear;

//global varibales
int totalYear,totalMonth,totalDay;

// Calculates exact age (years, months, days) based on the date of birth.
void exactAge() {

    // Get the current time
    time_t now = time(NULL);
    // Convert to local time structure
    struct tm *local = localtime(&now);

    // Extract the day, month, and year
    currentDay = local->tm_mday;         // Day of the month
    currentMonth = local->tm_mon + 1;    // Month of the year (0-11, add 1)
    currentYear = local->tm_year + 1900; // Year since 1900 (add 1900)

    setPromptColor(PURPLE);
    int birthYear = stoi(inputValidator("Enter Year of birth (YYYY): ","Y",4));
    year = birthYear;
    int birthMonth = stoi(inputValidator("Enter Month of birth (MM): ","M",2));
    month = birthMonth;
    int birthDay = stoi(inputValidator("Enter date of birth (DD): ","D",2));
    day = birthDay;


    totalYear = currentYear - birthYear;
    totalMonth = currentMonth - birthMonth;
    if (totalMonth <= 0) {
        totalMonth += 12;
        totalYear--;
    }
        
    totalDay = currentDay - birthDay;
    if (totalDay < 0) {
        totalDay += 31; // Assuming a 31-day month for simplicity
        totalMonth--;
    }

    if (totalMonth % 12 == 0) {
        totalYear += totalMonth / 12;
        totalMonth = 0;
    }
}

// Displays the exact age in years, months, and days.
void displayExactAge() {

    clearScreen(1);
    printf("%smainMenu>Age Manipulation>Exact age\n\n%s",OLIVE,RESET);

    exactAge();

    printf("%s\n----------------------------------------\n%s", VIOLET, RESET);
    printf("%sExact Age Calculator\n%s", YELLOW, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);
    printf("%sYour exact age is:\n%s", GRAY, RESET);
    printf("%s%d years, %d months, and %d days\n%s", GRAY, totalYear, totalMonth, totalDay, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            displayExactAge();
            break;
        case 1:
        case -1:
            ageManipulation();
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

// Displays the age in years.
void ageInYears() {

    clearScreen(1);
    printf("%smainMenu>Age Manipulation>Age in years\n\n%s",OLIVE,RESET);

    exactAge();

    float ageYears = (float)totalYear + (float)totalMonth / 12 + (float)totalDay / 365.25;
    printf("%s\n----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in years calculator:\n%s", YELLOW, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in years calculator:\n%s", GRAY, RESET);
    printf("%s%.3f years\n%s", GRAY, ageYears, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);

    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ageInYears();  
            break;
        case 1:
        case -1:
            ageManipulation();  
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

// Displays the age in month.
void ageInMonths() {

    clearScreen(1);
    printf("%smainMenu>Age Manipulation>Age in months\n\n%s",OLIVE,RESET);

    exactAge();

    float ageMonths = (float)totalYear * 12 + (float)totalMonth + (float)totalDay / 30.4375;
    printf("%s\n----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in months calculator:\n%s", YELLOW, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in months:\n%s", GRAY, RESET);
    printf("%s%.3f months\n%s", GRAY, ageMonths, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ageInMonths();  
            break;
        case 1:
        case -1:
            ageManipulation();  
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

// Displays the age in month.
void ageInWeeks() {

    clearScreen(1);
    printf("%smainMenu>Age Manipulation>Age in Weeks\n\n%s",OLIVE,RESET);

    exactAge();

    float ageWeeks = (float)totalYear * 52 + (float)totalMonth * 4 + (float)totalDay / 7;
    printf("%s\n----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in Weeks calculator:\n%s", YELLOW, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in Weeks:\n%s", GRAY, RESET);
    printf("%s%.3f Weeks\n%s", GRAY, ageWeeks, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ageInWeeks();  
            break;
        case 1:
        case -1:
            ageManipulation();  
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

// Displays the age in Days.
void ageInDays() {

    clearScreen(1);
    printf("%smainMenu>Age Manipulation>Age in Days\n\n%s",OLIVE,RESET);

    exactAge();

    float ageDays = (float)totalYear * 365 + (float)totalMonth * 30.4375 + (float)totalDay;
    printf("%s\n----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in Days calculator:\n%s", YELLOW, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);
    printf("%sAge in months:\n%s", GRAY, RESET);
    printf("%s%.3f Days\n%s", GRAY, ageDays, RESET);
    printf("%s----------------------------------------\n%s", VIOLET, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ageInDays();  
            break;
        case 1:
        case -1:
            ageManipulation();  
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
