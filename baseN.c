#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "menu.h"
#include "list.h"
#include "inputValidator.h"

char convertedToBinary[100];  // A large enough string to store binary
char initialValue[20];
char finalValue[100];

void fromBinary() {

    setPromptColor(BLUE);
    strcpy(convertedToBinary, inputValidator("Enter binary value: ", "B", 18));
    strcpy(initialValue,convertedToBinary);

}

void decimalToBinary() {
    
    setPromptColor(BLUE);
    strcpy(initialValue,inputValidator("Enter value :", "I", 15));
    long long int decimalValue = atoll(initialValue);

    int i = 0;
    if (decimalValue == 0) {
        // Handle edge case where decimalValue is zero
        convertedToBinary[i++] = '0';
    } else {

        while (decimalValue != 0) {
            convertedToBinary[i] = (decimalValue % 2) + '0'; // To convert number in their respected ascii code
            decimalValue /= 2;
            i++;
        }

    convertedToBinary[i] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct binary representation
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = convertedToBinary[start];
        convertedToBinary[start] = convertedToBinary[end];
        convertedToBinary[end] = temp;
        start++;
        end--;
        }
    }
}

void octalToBinary() {

    char octalValue[20];
    
    setPromptColor(BLUE);
    strcpy(octalValue,(inputValidator("Enter value :", "O", 15)));
    strcpy(initialValue,octalValue);

    // Clear the binary result array
    convertedToBinary[0] = '\0';

    for (int i = 0; octalValue[i] != '\0'; i++) {
        switch (octalValue[i]) {
            case '0': 
                strcat(convertedToBinary, "000"); 
                break;
            case '1': 
                strcat(convertedToBinary, "001"); 
                break;
            case '2': 
                strcat(convertedToBinary, "010"); 
                break;
            case '3': 
                strcat(convertedToBinary, "011"); 
                break;
            case '4': 
                strcat(convertedToBinary, "100"); 
                break;
            case '5': 
                strcat(convertedToBinary, "101"); 
                break;
            case '6': 
                strcat(convertedToBinary, "110"); 
                break;
            case '7': 
                strcat(convertedToBinary, "111"); 
                break;
        }
    } 
}

void hexToBinary() {

    char hexValue[100]; 

    setPromptColor(BLUE);
    strcpy(hexValue, inputValidator("Enter hexadecimal value:", "H", 15));
    strcpy(initialValue,hexValue);

    // Clear the binary result array
    convertedToBinary[0] = '\0';

    for (int i = 0; hexValue[i] != '\0'; i++) {
        switch (hexValue[i]) {
            case '0': 
                strcat(convertedToBinary, "0000"); 
                break;
            case '1': 
                strcat(convertedToBinary, "0001"); 
                break;
            case '2': 
                strcat(convertedToBinary, "0010"); 
                break;
            case '3': 
                strcat(convertedToBinary, "0011"); 
                break;
            case '4': 
                strcat(convertedToBinary, "0100"); 
                break;
            case '5': 
                strcat(convertedToBinary, "0101"); 
                break;
            case '6': 
                strcat(convertedToBinary, "0110"); 
                break;
            case '7': 
                strcat(convertedToBinary, "0111"); 
                break;
            case '8': 
                strcat(convertedToBinary, "1000"); 
                break;
            case '9': 
                strcat(convertedToBinary, "1001"); 
                break;
            case 'A': 
                strcat(convertedToBinary, "1010"); 
                break;
            case 'B': 
                strcat(convertedToBinary, "1011"); 
                break;
            case 'C': 
                strcat(convertedToBinary, "1100"); 
                break;
            case 'D': 
                strcat(convertedToBinary, "1101"); 
                break;
            case 'E': 
                strcat(convertedToBinary, "1110"); 
                break;
            case 'F': 
                strcat(convertedToBinary, "1111"); 
                break;
        }
    }
}

void toBinary() {
    
    strcpy(finalValue,convertedToBinary);

}

void binaryToDecimal() {

    long long int decimalValue = 0;
    int length = strlen(convertedToBinary);

    for (int i = 0; i < length; i++) {
        if(convertedToBinary[i] == '1') {
            decimalValue += pow(2,(length-i)-1);
        }
    }
    
    // Convert the decimal value to a string and store in finalValue
    sprintf(finalValue, "%lld", decimalValue);

}

void binaryToOctal() {
    char octalValue[20] = "";
    int length = strlen(convertedToBinary);

    if (length % 3 != 0) {
        char tempArray[100] = "";
        if (length % 3 == 1) {
            strcat(tempArray, "00");
        } else {
            strcat(tempArray, "0");
        }
        strcat(tempArray, convertedToBinary);
        strcpy(convertedToBinary, tempArray);
        length = strlen(convertedToBinary);
    }

    for (int i = 0; i < length; i += 3) {
        char chunk[4] = {convertedToBinary[i], convertedToBinary[i + 1], convertedToBinary[i + 2], '\0'};

        if (strcmp(chunk, "000") == 0)
            strcat(octalValue, "0");
        else if (strcmp(chunk, "001") == 0)
            strcat(octalValue, "1");
        else if (strcmp(chunk, "010") == 0)
            strcat(octalValue, "2");
        else if (strcmp(chunk, "011") == 0)
            strcat(octalValue, "3");
        else if (strcmp(chunk, "100") == 0)
            strcat(octalValue, "4");
        else if (strcmp(chunk, "101") == 0)
            strcat(octalValue, "5");
        else if (strcmp(chunk, "110") == 0)
            strcat(octalValue, "6");
        else if (strcmp(chunk, "111") == 0)
            strcat(octalValue, "7");
    }

    strcpy(finalValue, octalValue);
}

void binaryToHexadecimal() {
    char hexValue[20] = "";
    int length = strlen(convertedToBinary);

    if (length % 4 != 0) {
        char tempArray[100] = "";
        int padding = 4 - (length % 4);
        for (int i = 0; i < padding; i++) {
            strcat(tempArray, "0");
        }
        strcat(tempArray, convertedToBinary);
        strcpy(convertedToBinary, tempArray);
        length = strlen(convertedToBinary);
    }

    for (int i = 0; i < length; i += 4) {
        char chunk[5] = {convertedToBinary[i], convertedToBinary[i + 1], convertedToBinary[i + 2], convertedToBinary[i + 3], '\0'};

        if (strcmp(chunk, "0000") == 0)
            strcat(hexValue, "0");
        else if (strcmp(chunk, "0001") == 0)
            strcat(hexValue, "1");
        else if (strcmp(chunk, "0010") == 0)
            strcat(hexValue, "2");
        else if (strcmp(chunk, "0011") == 0)
            strcat(hexValue, "3");
        else if (strcmp(chunk, "0100") == 0)
            strcat(hexValue, "4");
        else if (strcmp(chunk, "0101") == 0)
            strcat(hexValue, "5");
        else if (strcmp(chunk, "0110") == 0)
            strcat(hexValue, "6");
        else if (strcmp(chunk, "0111") == 0)
            strcat(hexValue, "7");
        else if (strcmp(chunk, "1000") == 0)
            strcat(hexValue, "8");
        else if (strcmp(chunk, "1001") == 0)
            strcat(hexValue, "9");
        else if (strcmp(chunk, "1010") == 0)
            strcat(hexValue, "A");
        else if (strcmp(chunk, "1011") == 0)
            strcat(hexValue, "B");
        else if (strcmp(chunk, "1100") == 0)
            strcat(hexValue, "C");
        else if (strcmp(chunk, "1101") == 0)
            strcat(hexValue, "D");
        else if (strcmp(chunk, "1110") == 0)
            strcat(hexValue, "E");
        else if (strcmp(chunk, "1111") == 0)
            strcat(hexValue, "F");
    }

    strcpy(finalValue, hexValue);
}

int baseN() {

    const char *options[] ={"Binary(2)","Decimal(10)","Octal(8)","Hexa-Decimal(16)"};

    char initialBase[20];
    char finalBase[20];

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Base-N\n%s",OLIVE,RESET);

    printf("\n%sSelect Intial base %s\n",CYAN,RESET);
    
    int selectedOption = displayList(options, 4);
    switch (selectedOption)
    {
    case 0:
        strcpy(initialBase,"Binary(2)");
        break;
    case 1:
        strcpy(initialBase,"Decimal(10)");
        break;
    case 2:
        strcpy(initialBase,"Octal(8)");
        break;
    case 3:
        strcpy(initialBase,"Hexa-Decimal(16)");
        break;
    case -1:
        mainMenu();
    default:
        break;
    }

    clearScreen(1);
    printf("%smainMenu>Base-N>\n%s",OLIVE,RESET);
    printf("\n%sInitail base : %s%s\n\n%s",CYAN,PURPLE,initialBase,RESET);

    switch (selectedOption)
    {
    case 0:
        fromBinary();
        break;
    case 1:
        decimalToBinary();
        break;
    case 2:
        octalToBinary();
        break;
    case 3:
        hexToBinary();
        break;
    case -1:
        mainMenu();
    default:
        break;
    }
    
    printf("\n%sSelect final base %s\n",CYAN,RESET);
    
    selectedOption = displayList(options, 4);
    switch (selectedOption)
    {
    case 0:
        strcpy(finalBase,"Binary(2)");
        toBinary();
        break;
    case 1:
        strcpy(finalBase,"Decimal(10)");
        binaryToDecimal();
        break;
    case 2:
        strcpy(finalBase,"Octal(8)");
        binaryToOctal();
        break;
    case 3:
        strcpy(finalBase,"Hexa-Decimal(16)");
        binaryToHexadecimal();
        break;
    case -1:
        baseN();
    default:
        break;
    }

    clearScreen(1);

    printf("%smainMenu>Base-N>\n\n%s",OLIVE,RESET);
    printf("%sInitail base : %s%s\n\n%s",CYAN,PURPLE,initialBase,RESET);
    printf("%sEntered value : %s%s\n\n%s",GREEN,WHITE,initialValue,RESET);
    printf("%sFinal base : %s%s\n\n%s",CYAN,PURPLE,finalBase,RESET);
    printf("%sConverted value : %s%s\n\n%s",GREEN,WHITE,finalValue,RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            baseN();
            break;
        case 1:
        case -1:
            mainMenu();
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

