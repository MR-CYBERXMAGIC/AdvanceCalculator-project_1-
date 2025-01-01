#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "menu.h"
#include "string.h"
#include "inputValidator.h"
#include "converters.h"

char initialUnit[50];
char convertionUnit[50];

// Converts a given value to meters based on the selected unit
double convertToMeter(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Meter to Meter
            convertedValue = value;
            strcpy(initialUnit, "Meter");
            break;
        case 1: // Kilometer to Meter
            convertedValue = value * 1000.0;
            strcpy(initialUnit, "Kilometer");
            break;
        case 2: // Foot to Meter
            convertedValue = value * 0.3048;
            strcpy(initialUnit, "Foot");
            break;
        case 3: // Yard to Meter
            convertedValue = value * 0.9144;
            strcpy(initialUnit, "Yard");
            break;
        case 4: // Mile to Meter
            convertedValue = value * 1609.34;
            strcpy(initialUnit, "Mile");
            break;
        case 5: // Nautical Mile to Meter
            convertedValue = value * 1852;
            strcpy(initialUnit, "Nautical Mile");
            break;
        default:
            break;   
    }

    return convertedValue;
}

// Converts from meters to the selected unit
double convertFromMeter(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Meter to Meter
            convertedValue = value;
            strcpy(convertionUnit, "Meter");
            break;
        case 1: // Meter to Kilometer
            convertedValue = value / 1000.0;
            strcpy(convertionUnit, "Kilometer");
            break;
        case 2: // Meter to Foot
            convertedValue = value / 0.3048;
            strcpy(convertionUnit, "Foot");
            break;
        case 3: // Meter to Yard
            convertedValue = value / 0.9144;
            strcpy(convertionUnit, "Yard");
            break;
        case 4: // Meter to Mile
            convertedValue = value / 1609.34;
            strcpy(convertionUnit, "Mile");
            break;
        case 5: // Meter to Nautical Mile
            convertedValue = value / 1852;
            strcpy(convertionUnit, "Nautical Mile");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main length conversion function
int length() {
    clearScreen(1);
    printf("%smainMenu>Converters>Length\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);
    
    double initialValue = atof(inputValidator("Enter value to convert: ", "F", 15));

    const char *units[] = {"Meter (m)", "Kilometer (km)", "Foot (ft)", "Yard (yd)", "Mile (mi)", "Nautical Mile"};
    
    printf("\n%sInitial unit:\n%s", CYAN, RESET);
    int initialSelection = displayList(units, 6);

    double meters = convertToMeter(initialValue, initialSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Length\n\n%s", OLIVE, RESET);
    printf("%sEnter value to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    int targetSelection = displayList(units, 6);

    double convertedValue = convertFromMeter(meters, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Length\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Value to Convert : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit           : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit          : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Value        : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            length();
            break;
        case 1: case -1:
            converters();
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

// Converts the given value to kilograms based on the selected unit
double convertToKilogram(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Kilogram to Kilogram
            convertedValue = value;
            strcpy(initialUnit, "Kilogram");
            break;
        case 1: // Gram to Kilogram
            convertedValue = value / 1000.0;
            strcpy(initialUnit, "Gram");
            break;
        case 2: // Pound to Kilogram
            convertedValue = value * 0.453592;
            strcpy(initialUnit, "Pound");
            break;
        case 3: // Ounce to Kilogram
            convertedValue = value * 0.0283495;
            strcpy(initialUnit, "Ounce");
            break;
        case 4: // Ton to Kilogram
            convertedValue = value * 1000.0;
            strcpy(initialUnit, "Ton");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from kilograms to the selected unit
double convertFromKilogram(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Kilogram to Kilogram
            convertedValue = value;
            strcpy(convertionUnit, "Kilogram");
            break;
        case 1: // Kilogram to Gram
            convertedValue = value * 1000.0;
            strcpy(convertionUnit, "Gram");
            break;
        case 2: // Kilogram to Pound
            convertedValue = value / 0.453592;
            strcpy(convertionUnit, "Pound");
            break;
        case 3: // Kilogram to Ounce
            convertedValue = value / 0.0283495;
            strcpy(convertionUnit, "Ounce");
            break;
        case 4: // Kilogram to Ton
            convertedValue = value / 1000.0;
            strcpy(convertionUnit, "Ton");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main weight/mass conversion function
int weight() {
    clearScreen(1);
    printf("%smainMenu>Converters>Weight/Mass\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);

    double initialValue = atof(inputValidator("Enter weight/mass to convert: ", "F", 15));

    const char *units[] = {"Kilogram (kg)", "Gram (g)", "Pound (lb)", "Ounce (oz)", "Ton (t)"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 5);
    double kilograms = convertToKilogram(initialValue,selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Weight/Mass\n\n%s", OLIVE, RESET);
    printf("%sEnter weight/mass to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 5);

    double convertedValue = convertFromKilogram(kilograms,targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Weight/Mass\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Weight/Mass        : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit             : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit            : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Weight/Mass    : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            weight();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given temperature to Celsius
double convertToCelsius(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Celsius to Celsius
            convertedValue = value;
            strcpy(initialUnit, "Celsius");
            break;
        case 1: // Fahrenheit to Celsius
            convertedValue = (value - 32) * 5.0 / 9.0;
            strcpy(initialUnit, "Fahrenheit");
            break;
        case 2: // Kelvin to Celsius
            convertedValue = value - 273.15;
            strcpy(initialUnit, "Kelvin");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts Celsius to the selected temperature unit
double convertFromCelsius(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Celsius to Celsius
            convertedValue = value;
            strcpy(convertionUnit, "Celsius");
            break;
        case 1: // Celsius to Fahrenheit
            convertedValue = (value * 9.0 / 5.0) + 32;
            strcpy(convertionUnit, "Fahrenheit");
            break;
        case 2: // Celsius to Kelvin
            convertedValue = value + 273.15;
            strcpy(convertionUnit, "Kelvin");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main temperature conversion function
int temperature() {
    clearScreen(1);
    printf("%smainMenu>Converters>Temperature\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);

    double initialValue = atof(inputValidator("Enter temperature to convert: ", "F", 15));

    const char *units[] = {"Celsius (C)", "Fahrenheit (F)", "Kelvin (K)"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 3);

    if (selection == 2 && initialValue < 0) {
        initialValue *= -1;
    }
    
    double celsiusValue = convertToCelsius(initialValue, selection);

    if(celsiusValue < -273.15) {
        temperature();
    }

    clearScreen(1);
    printf("%smainMenu>Converters>Temperature\n\n%s", OLIVE, RESET);
    printf("%sEnter temperature to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 3);

    double convertedValue = convertFromCelsius(celsiusValue, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Temperature\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Temperature to Convert: %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit               : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit              : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Temperature       : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            temperature();
            break;
        case 1:
        case -1:
            converters();
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

// Converts a given time value to seconds based on the selected unit
double convertToSeconds(double value, int selection) {
    double convertedValue = 0;
    const char *units[] = {"Second (s)", "Minute (min)", "Hour (hr)", "Day (d)", "Week (wk)", "Month (mo)", "Year (yr)"};

    switch (selection) {
        case 0: // Seconds to Seconds
            convertedValue = value;
            strcpy(initialUnit, "Second");
            break;
        case 1: // Minutes to Seconds
            convertedValue = value * 60.0;
            strcpy(initialUnit, "Minute");
            break;
        case 2: // Hours to Seconds
            convertedValue = value * 3600.0;
            strcpy(initialUnit, "Hour");
            break;
        case 3: // Days to Seconds
            convertedValue = value * 86400.0;
            strcpy(initialUnit, "Day");
            break;
        case 4: // Weeks to Seconds
            convertedValue = value * 604800.0;
            strcpy(initialUnit, "Week");
            break;
        case 5: // Months to Seconds (30.4375 days)
            convertedValue = value * 30.4375 * 86400.0;
            strcpy(initialUnit, "Month");
            break;
        case 6: // Years to Seconds (365.25 days)
            convertedValue = value * 365.25 * 86400.0;
            strcpy(initialUnit, "Year");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from seconds to the selected time unit
double convertFromSeconds(double value, int selection) {
    double convertedValue = 0;
    const char *units[] = {"Second (s)", "Minute (min)", "Hour (hr)", "Day (d)", "Week (wk)", "Month (mo)", "Year (yr)"};

    switch (selection) {
        case 0: // Seconds to Seconds
            convertedValue = value;
            strcpy(convertionUnit, "Second");
            break;
        case 1: // Seconds to Minutes
            convertedValue = value / 60.0;
            strcpy(convertionUnit, "Minute");
            break;
        case 2: // Seconds to Hours
            convertedValue = value / 3600.0;
            strcpy(convertionUnit, "Hour");
            break;
        case 3: // Seconds to Days
            convertedValue = value / 86400.0;
            strcpy(convertionUnit, "Day");
            break;
        case 4: // Seconds to Weeks
            convertedValue = value / 604800.0;
            strcpy(convertionUnit, "Week");
            break;
        case 5: // Seconds to Months (30.4375 days)
            convertedValue = value / (30.4375 * 86400.0);
            strcpy(convertionUnit, "Month");
            break;
        case 6: // Seconds to Years (365.25 days)
            convertedValue = value / (365.25 * 86400.0);
            strcpy(convertionUnit, "Year");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main time conversion function
int time() {
    clearScreen(1);
    printf("%smainMenu>Converters>Time\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);
    
    double initialValue = atof(inputValidator("Enter time to convert: ", "F", 15));

    const char *units[] = {"Second (s)", "Minute (min)", "Hour (hr)", "Day (d)", "Week (wk)", "Month (mo)", "Year (yr)"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 7);
    double secondsValue = convertToSeconds(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Time\n\n%s", OLIVE, RESET);
    printf("%sEnter time to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 7);

    double convertedValue = convertFromSeconds(secondsValue, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Time\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Time to Convert     : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit              : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit             : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Time            : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            time();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given angle to radians based on the selected unit
double convertToRadians(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Degrees to Radians
            convertedValue = value * (3.14159265358979 / 180.0);
            strcpy(initialUnit, "Degrees");
            break;
        case 1: // Radians to Radians
            convertedValue = value;
            strcpy(initialUnit, "Radians");
            break;
        case 2: // Gradians to Radians
            convertedValue = value * (3.14159265358979 / 200.0);
            strcpy(initialUnit, "Gradians");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from radians to the selected angle unit
double convertFromRadians(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Radians to Degrees
            convertedValue = value * (180.0 / 3.14159265358979);
            strcpy(convertionUnit, "Degrees");
            break;
        case 1: // Radians to Radians
            convertedValue = value;
            strcpy(convertionUnit, "Radians");
            break;
        case 2: // Radians to Gradians
            convertedValue = value * (200.0 / 3.14159265358979);
            strcpy(convertionUnit, "Gradians");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main angle conversion function
int angle() {
    clearScreen(1);
    printf("%smainMenu>Converters>Angle\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);
    double initialValue = atof(inputValidator("Enter angle to convert: ", "F", 15));

    const char *units[] = {"Degrees", "Radians", "Gradians"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 3);
    double radiansValue = convertToRadians(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Angle\n\n%s", OLIVE, RESET);
    printf("%sEnter angle to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 3);

    double convertedValue = convertFromRadians(radiansValue, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Angle\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Angle to Convert  : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit           : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit          : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Angle         : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            angle();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given area to square meters
double convertToSquareMeters(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Square meter to Square meter
            convertedValue = value;
            strcpy(initialUnit, "Square meter");
            break;
        case 1: // Square kilometer to Square meter
            convertedValue = value * 1000000;
            strcpy(initialUnit, "Square kilometer");
            break;
        case 2: // Square foot to Square meter
            convertedValue = value * 0.092903;
            strcpy(initialUnit, "Square foot");
            break;
        case 3: // Acre to Square meter
            convertedValue = value * 4046.86;
            strcpy(initialUnit, "Acre");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from square meters to the selected area unit
double convertFromSquareMeters(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Square meter to Square meter
            convertedValue = value;
            strcpy(convertionUnit, "Square meter");
            break;
        case 1: // Square meter to Square kilometer
            convertedValue = value / 1000000;
            strcpy(convertionUnit, "Square kilometer");
            break;
        case 2: // Square meter to Square foot
            convertedValue = value / 0.092903;
            strcpy(convertionUnit, "Square foot");
            break;
        case 3: // Square meter to Acre
            convertedValue = value / 4046.86;
            strcpy(convertionUnit, "Acre");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main area conversion function
int area() {
    clearScreen(1);
    printf("%smainMenu>Converters>Area\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);

    double initialValue = atof(inputValidator("Enter area to convert: ", "F", 15));

    const char *units[] = {"Square meter", "Square kilometer", "Square foot", "Acre"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 4);
    double squareMetersValue = convertToSquareMeters(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Area\n\n%s", OLIVE, RESET);
    printf("%sEnter area to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 4);

    double convertedValue = convertFromSquareMeters(squareMetersValue, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Area\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Area to Convert   : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit           : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit          : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Area          : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            area();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given volume to liters
double convertToLiters(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Liters to Liters
            convertedValue = value;
            strcpy(initialUnit, "Liter");
            break;
        case 1: // Milliliters to Liters
            convertedValue = value / 1000.0;
            strcpy(initialUnit, "Milliliter");
            break;
        case 2: // Gallons to Liters
            convertedValue = value * 3.78541;
            strcpy(initialUnit, "Gallon");
            break;
        case 3: // Cubic Meters to Liters
            convertedValue = value * 1000.0;
            strcpy(initialUnit, "Cubic Meter");
            break;
        case 4: // Cubic Inches to Liters
            convertedValue = value * 0.0163871;
            strcpy(initialUnit, "Cubic Inch");
            break;
        case 5: // Quarts to Liters
            convertedValue = value * 0.946353;
            strcpy(initialUnit, "Quart");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from liters to the selected volume unit
double convertFromLiters(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Liters to Liters
            convertedValue = value;
            strcpy(convertionUnit, "Liter");
            break;
        case 1: // Liters to Milliliters
            convertedValue = value * 1000.0;
            strcpy(convertionUnit, "Milliliter");
            break;
        case 2: // Liters to Gallons
            convertedValue = value / 3.78541;
            strcpy(convertionUnit, "Gallon");
            break;
        case 3: // Liters to Cubic Meters
            convertedValue = value / 1000.0;
            strcpy(convertionUnit, "Cubic Meter");
            break;
        case 4: // Liters to Cubic Inches
            convertedValue = value / 0.0163871;
            strcpy(convertionUnit, "Cubic Inch");
            break;
        case 5: // Liters to Quarts
            convertedValue = value / 0.946353;
            strcpy(convertionUnit, "Quart");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main volume conversion function
int volume() {
    clearScreen(1);
    printf("%smainMenu>Converters>Volume\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);
    
    double initialValue = atof(inputValidator("Enter volume to convert: ", "F", 15));

    const char *units[] = {"Liter (L)", "Milliliter (mL)", "Gallon (gal)", "Cubic Meter (m³)", "Cubic Inch (in³)", "Quart (qt)"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 6);
    double litersValue = convertToLiters(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Volume\n\n%s", OLIVE, RESET);
    printf("%sEnter volume to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 6);

    double convertedValue = convertFromLiters(litersValue, targetSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Volume\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Volume to Convert    : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit               : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit              : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Volume           : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            volume();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given value to bytes using powers of 2 (i.e., 2^10 for kilobytes, etc.)
double convertToBytes(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Bit to Byte (1 Byte = 8 bits)
            convertedValue = value / 8;
            strcpy(initialUnit, "Bit");
            break;
        case 1: // Nibble to Byte (1 Byte = 2 Nibbles)
            convertedValue = value / 2;
            strcpy(initialUnit, "Nibble");
            break;
        case 2: // Byte to Byte
            convertedValue = value;
            strcpy(initialUnit, "Byte");
            break;
        case 3: // Kilobyte to Byte
            convertedValue = value * pow(2, 10);  // 1 KB = 2^10 bytes
            strcpy(initialUnit, "Kilobyte");
            break;
        case 4: // Megabyte to Byte
            convertedValue = value * pow(2, 20);  // 1 MB = 2^20 bytes
            strcpy(initialUnit, "Megabyte");
            break;
        case 5: // Gigabyte to Byte
            convertedValue = value * pow(2, 30);  // 1 GB = 2^30 bytes
            strcpy(initialUnit, "Gigabyte");
            break;
        case 6: // Terabyte to Byte
            convertedValue = value * pow(2, 40);  // 1 TB = 2^40 bytes
            strcpy(initialUnit, "Terabyte");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from bytes to the selected unit using powers of 2
double convertFromBytes(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Byte to Bit
            convertedValue = value * 8;
            strcpy(convertionUnit, "Bit");
            break;
        case 1: // Byte to Nibble
            convertedValue = value * 4;
            strcpy(convertionUnit, "Nibble");
            break;
        case 2: // Byte to Byte
            convertedValue = value;
            strcpy(convertionUnit, "Byte");
            break;
        case 3: // Byte to Kilobyte
            convertedValue = value / pow(2, 10);  // 1 KB = 2^10 bytes
            strcpy(convertionUnit, "Kilobyte");
            break;
        case 4: // Byte to Megabyte
            convertedValue = value / pow(2, 20);  // 1 MB = 2^20 bytes
            strcpy(convertionUnit, "Megabyte");
            break;
        case 5: // Byte to Gigabyte
            convertedValue = value / pow(2, 30);  // 1 GB = 2^30 bytes
            strcpy(convertionUnit, "Gigabyte");
            break;
        case 6: // Byte to Terabyte
            convertedValue = value / pow(2, 40);  // 1 TB = 2^40 bytes
            strcpy(convertionUnit, "Terabyte");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main digital storage conversion function
int digitalStorage() {
    clearScreen(1);
    printf("%smainMenu>Converters>Digital Storage\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);

    double initialValue = atof(inputValidator("Enter value to convert: ", "F", 15));

    const char *units[] = {"Bit", "Nibble", "Byte", "Kilobyte", "Megabyte", "Gigabyte", "Terabyte"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 7);
    double byteValue = convertToBytes(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Digital Storage\n\n%s", OLIVE, RESET);
    printf("%sEnter value to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 7);

    double convertedValue = convertFromBytes(byteValue, targetSelection);

    clearScreen(1);
    // Display the conversion details with enhanced formatting and clear separation
    printf("%smainMenu>Converters>Digital Storage\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Value to Convert   : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit           : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit          : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Value         : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            digitalStorage();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given speed to meters per second
double convertToMPS(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Meters per second to Meters per second
            convertedValue = value;
            strcpy(initialUnit, "Meters per second");
            break;
        case 1: // Kilometers per hour to Meters per second
            convertedValue = value / 3.6;
            strcpy(initialUnit, "Kilometers per hour");
            break;
        case 2: // Miles per hour to Meters per second
            convertedValue = value * 0.44704;
            strcpy(initialUnit, "Miles per hour");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from meters per second to the selected speed unit
double convertFromMPS(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // Meters per second to Meters per second
            convertedValue = value;
            strcpy(convertionUnit, "Meters per second");
            break;
        case 1: // Meters per second to Kilometers per hour
            convertedValue = value * 3.6;
            strcpy(convertionUnit, "Kilometers per hour");
            break;
        case 2: // Meters per second to Miles per hour
            convertedValue = value / 0.44704;
            strcpy(convertionUnit, "Miles per hour");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main speed conversion function
int speed() {
    clearScreen(1);
    printf("%smainMenu>Converters>Speed\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);
    double initialValue = atof(inputValidator("Enter speed to convert: ", "F", 15));

    const char *units[] = {"Meters per second (m/s)", "Kilometers per hour (km/h)", "Miles per hour (mph)"};
    int selection;
    printf("\n%sInitial unit:\n%s", CYAN, RESET);

    selection = displayList(units, 3);
    double mpsValue = convertToMPS(initialValue, selection);

    clearScreen(1);
    printf("%smainMenu>Converters>Speed\n\n%s", OLIVE, RESET);
    printf("%sEnter speed to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial unit: %s\n%s", CYAN, initialUnit, RESET);

    int targetSelection;
    printf("\n%stargeted unit:\n%s", CYAN, RESET);
    targetSelection = displayList(units, 3);

    double convertedValue = convertFromMPS(mpsValue, targetSelection);

    clearScreen(1);
    // Display the conversion details with enhanced formatting and clear separation
    printf("%smainMenu>Converters>Speed\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Speed to Convert  : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit           : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit          : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Speed         : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            speed();
            break;
        case 1:
        case -1:
            converters();
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

// Converts the given currency to USD
double convertToUSD(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // USD to USD
            convertedValue = value;
            strcpy(initialUnit, "US Dollar (USD)");
            break;
        case 1: // PKR to USD
            convertedValue = value * 0.0035;
            strcpy(initialUnit, "Pakistani Rupee (PKR)");
            break;
        case 2: // INR to USD
            convertedValue = value * 0.012;
            strcpy(initialUnit, "Indian Rupee (INR)");
            break;
        case 3: // SAR to USD
            convertedValue = value * 0.27;
            strcpy(initialUnit, "Saudi Riyal (SAR)");
            break;
        case 4: // AED to USD
            convertedValue = value * 0.27;
            strcpy(initialUnit, "Dirham (AED)");
            break;
        case 5: // GBP to USD
            convertedValue = value * 1.21;
            strcpy(initialUnit, "British Pound (GBP)");
            break;
        case 6: // EUR to USD
            convertedValue = value * 1.08;
            strcpy(initialUnit, "Euro (EUR)");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Converts from USD to the selected currency
double convertFromUSD(double value, int selection) {
    double convertedValue = 0;

    switch (selection) {
        case 0: // USD to USD
            convertedValue = value;
            strcpy(convertionUnit, "US Dollar (USD)");
            break;
        case 1: // USD to PKR
            convertedValue = value * 286.45;
            strcpy(convertionUnit, "Pakistani Rupee (PKR)");
            break;
        case 2: // USD to INR
            convertedValue = value * 82.53;
            strcpy(convertionUnit, "Indian Rupee (INR)");
            break;
        case 3: // USD to SAR
            convertedValue = value * 3.75;
            strcpy(convertionUnit, "Saudi Riyal (SAR)");
            break;
        case 4: // USD to AED
            convertedValue = value * 3.67;
            strcpy(convertionUnit, "Dirham (AED)");
            break;
        case 5: // USD to GBP
            convertedValue = value * 0.83;
            strcpy(convertionUnit, "British Pound (GBP)");
            break;
        case 6: // USD to EUR
            convertedValue = value * 0.93;
            strcpy(convertionUnit, "Euro (EUR)");
            break;
        default:
            break;
    }

    return convertedValue;
}

// Main currency conversion function
int currencyConverter() {
    clearScreen(1);
    printf("%smainMenu>Converters>Currency Converter\n\n%s", OLIVE, RESET);

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    setPromptColor(BROWN);

    double initialValue = atof(inputValidator("Enter amount to convert: ", "F", 15));

    const char *currencies[] = {"US Dollar (USD)", "Pakistani Rupee (PKR)", "Indian Rupee (INR)", 
                                "Saudi Riyal (SAR)", "Dirham (AED)", "British Pound (GBP)", "Euro (EUR)"};
    int fromSelection, toSelection;

    // Ask the user for the currency they want to convert from
    printf("\n%sInitial currency:\n%s", CYAN, RESET);
    fromSelection = displayList(currencies, 7);
    double usdValue = convertToUSD(initialValue, fromSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Currency Converter\n\n%s", OLIVE, RESET);
    printf("%sEnter amount to convert: %lf\n%s", GREEN, initialValue, RESET);
    printf("\n%sInitial currency: %s\n%s", CYAN, initialUnit, RESET);

    // Ask the user for the target currency
    printf("\n%sTarget currency:\n%s", CYAN, RESET);
    toSelection = displayList(currencies, 7);

    double convertedValue = convertFromUSD(usdValue, toSelection);

    clearScreen(1);
    printf("%smainMenu>Converters>Currency Converter\n\n%s", OLIVE, RESET);

    printf("%s---------------------------------------%s\n", CYAN, RESET);
    printf("%s Enter Amount to Convert  : %s%lf\n", GREEN, RESET, initialValue);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Initial Unit            : %s%s\n", YELLOW, RESET, initialUnit);
    printf("%s Targeted Unit           : %s%s\n", YELLOW, RESET, convertionUnit);
    printf("%s---------------------------------------%s\n", PURPLE, RESET);
    printf("%s Converted Amount        : %s%lf\n%s", GREEN, RESET, convertedValue, RESET);
    printf("%s---------------------------------------%s\n\n", CYAN, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            currencyConverter();
            break;
        case 1:
        case -1:
            converters();
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
