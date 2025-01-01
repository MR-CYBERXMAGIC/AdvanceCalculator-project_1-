#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "inputValidator.h"
#include "menu.h"
#include "numberManipulation.h"

//Number classification

//Function to check if the input is an even number or odd
void evenOdd(){

    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Even/Odd\n%s", OLIVE, RESET);

    // Definition of even and odd
    printf("%s\nEven numbers:%s\n Even numbers are integers that can be divided by 2 without a remainder.%s", BROWN, GRAY, RESET);
    printf("%s\nOdd numbers:%s\n Odd numbers are integers that cannot be divided by 2 without a remainder.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "I", 18));

    if ( num % 2 == 0) {
         printf("%s\n%lld is a even number%s\n", YELLOW, num, RESET); 
    } else {
         printf("%s\n%lld is a odd number%s\n", YELLOW, num, RESET); 
    }
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            evenOdd();
            break;
        case 1:
        case -1:
            numberClassification();
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

//Function to check if the input is a prime number or composite
void primeComposite() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Prime/Composite\n%s", OLIVE, RESET);

    // Definition of prime and composite
    printf("%s\n\nPrime Number:%s\n A natural number greater than 1 that has exactly two distinct positive divisors: 1 and itself%s", BROWN, GRAY, RESET);
    printf("%s\nComposite Number:%s\n A natural number greater than 1 that has more than two divisors%s\n\n", BROWN, GRAY, RESET);

    int isPrime = 1;
    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 

    if (num == 1 || num == 0) {
        printf("%s\n\n%lld is neither prime nor composite number%s\n", RED, num, RESET);
        isPrime = -1;
    } else if (num <= 3) {
        isPrime = 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        isPrime = 0; // Eliminate multiples of 2 and 3
    } else {
        for (long long int i = 5; i * i <= num; i += 6) { 
            if (num % i == 0 || num % (i + 2) == 0) {
                isPrime = 0; // Check divisors in the form 6k ± 1
                break;
            }
        }
    }

    if (isPrime == 1) {
        printf("%s\n%lld is a prime number%s\n", YELLOW, num, RESET); 
    } else if (isPrime == 0) {
        printf("%s\n%lld is a composite number%s\n", YELLOW, num, RESET); 
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            primeComposite();
            break;
        case 1:
        case -1:
            numberClassification();
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

//Function to check if the input is perfect number
void perfect() {

    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Perfect\n%s", OLIVE, RESET);
    // Definition of a Perfect Number
    printf("%s\nPerfect Number:%s\n A positive integer equal to the sum of its proper divisors (excluding itself).%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 15)); 

    if (num <= 1) {
        printf("%s\n%lld is NOT a Perfect Number.%s\n", YELLOW, num, RESET);
    } else {
        // Calculate sum of divisors using optimized approach
        long long int sum = 1; // Start with 1 as it is a divisor for all numbers
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i; // Add the divisor
                if (i != num / i) {
                    sum += num / i; // Add the paired divisor, avoiding duplication
                }
            }
        }

        if (sum == num) {
            printf("%s\n%lld is a Perfect Number!%s\n", YELLOW, num, RESET);
        } else {
            printf("%s\n%lld is NOT a Perfect Number.%s\n", YELLOW, num, RESET);
        }
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            perfect();
            break;
        case 1: 
        case -1:
            numberClassification();
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

//Function to check if the input is Armstrong/narcissistic number
void Armstrong() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Armstrong/narcissistic\n%s", OLIVE, RESET);

    // Explanation of Armstrong Numbers
    printf("%s\nArmstrong/narcissistic Number:%s\n A number equal to the sum of its digits each raised to the power of the number of digits.%s\n\n", BROWN, GRAY, RESET);

    // Input validation and initialization
    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 15)); 
    long long int digitCount = 0, sum = 0, temp = num;

    // Calculate digit count
    while (temp != 0) {
        digitCount++;
        temp /= 10;
    }

    //calculate sum of digit powers
    temp = num;
    while (temp != 0) {
        long long int digit = temp % 10;
        temp /= 10;

        // Compute power manually to make solution more optimized
        int power = 1;
        for (long long int i = 0; i < digitCount; i++) {
            power *= digit;
        }
        sum += power;
    }

    if (sum == num) {
        printf("%s\n%d is an Armstrong number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%d is NOT an Armstrong number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            Armstrong();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if the input is a Kaprekar number
void kaprekar() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Kaprekar\n%s", OLIVE, RESET);

    // Explanation of Kaprekar Number
    printf("%s\nKaprekar Number:%s\n A number whose square, when split into two parts, gives the original number as the sum.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ","P",9));
    long long int square = num * num;

    int numDigits = 0;
    long long int originalNumber = num;
    while (originalNumber != 0) {
        originalNumber /= 10;
        numDigits++;
    }

    long long int divisor = (long long int)pow(10, numDigits); 

    // Split the square into two parts
    long long int rightPart = square % divisor;
    long long int leftPart = square / divisor;

    // Check if the sum of both parts equals the original number
    if (rightPart + leftPart == num) {
        printf("%s\n%lld is a Kaprekar Number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%lld is NOT a Kaprekar Number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            kaprekar();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if the input is a Palindrome number
void palindrome() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Palindrome\n%s", OLIVE, RESET);

    // Explanation of Palindrome Numbers
    printf("%s\nPalindrome Number:%s\n A number that remains the same when its digits are reversed.%s\n\n", BROWN, GRAY, RESET);

    // Input validation and initialization
    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 
    long long int reversedNumber = 0, remainder, originalNumber = num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;                  // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder;  // Add to the reversed number
        num /= 10;                              // Remove the last digit
    }

    // Check if the original number is equal to the reversed number
    if (originalNumber == reversedNumber) {
        printf("%s\n%d is a Palindrome number!%s\n", YELLOW, originalNumber, RESET);
    } else {
        printf("%s\n%d is NOT a Palindrome number.%s\n", YELLOW, originalNumber, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            palindrome();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if two numbers are coprime
void coprime() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Coprime\n%s", OLIVE, RESET);

    // Explanation of Coprime Numbers
    printf("%s\nCoprime Numbers:%s\n Two numbers that have no common divisors other than 1.%s\n\n", BROWN, GRAY, RESET);

    // Input validation and initialization
    setPromptColor(BLUE);
    long long int originalNum1 = atoll(inputValidator("Enter the first number: ", "I", 17));
    long long int num1 = llabs(originalNum1);
    setPromptColor(BLUE);
    long long int originalNum2 = atoll(inputValidator("Enter the second number: ", "I", 17)); 
    long long int num2 = llabs(originalNum2);
    int areCoprime = 0;
   
    if(gcd(num1,num2)==1) {
        areCoprime = 1;
    }

    if (areCoprime) {
        printf("%s\n%lld and %lld are coprime numbers.%s\n", YELLOW, originalNum1, originalNum2, RESET);
    } else {
        printf("%s\n%lld and %lld are not coprime numbers.%s\n", YELLOW, originalNum1, originalNum2, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            coprime();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if the input is a Niven (Harshad) number
void niven() {

    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Niven\n%s", OLIVE, RESET);

    // Explanation of Niven/Harshad Number
    printf("%s\nNiven/Harshad Number:%s\n A number that is divisible by the sum of its digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 
    long long int originalNumber = num;
    long long int digitSum = 0;

    // Calculate the sum of digits
    while (originalNumber != 0) {
        digitSum += originalNumber % 10;
        originalNumber /= 10;
    }

    // Check if the number is divisible by the sum of its digits
    if (num % digitSum == 0) {
        printf("%s\n%lld is a Niven/Harshad number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%lld is NOT a Niven/Harshad number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            niven();
            break;
        case 1: 
        case -1:
            numberClassification();
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
// Function to check if the input is a Deficient number
void deficient() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Deficient\n%s", OLIVE, RESET);

    // Explanation of Deficient Number
    printf("%s\nDeficient Number:%s\n A positive integer that is lesser than the sum of its proper divisors (excluding the number itself).%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 
    long long int sum = 0;

    // Calculate the sum of proper divisors
    for (long long int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of proper divisors is less than the number
    if (sum < num) {
        printf("%s\n%lld is a Deficient number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%lld is NOT a Deficient number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            deficient();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if the input is an Abundant number
void abundant() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Abundant\n%s", OLIVE, RESET);

    // Explanation of Abundant Number
    printf("%s\nAbundant Number:%s\n A positive integer that is less than the sum of its proper divisors (excluding the number itself).%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 

    long long int sum = 0;

    // Calculate the sum of proper divisors
    for (long long int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of proper divisors is greater than the number
    if (sum > num) {
        printf("%s\n%lld is an Abundant number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%lld is NOT an Abundant number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            abundant();
            break;
        case 1: 
        case -1:
            numberClassification();
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

// Function to check if the input is a Spy number
void spy() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification>Spy\n%s", OLIVE, RESET);

    // Explanation of Spy Number
    printf("%s\nSpy Number:%s\n A number whose sum of digits equals the product of its digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int num = atoll(inputValidator("Enter any positive number ", "P", 18)); 

    long long int digitSum = 0, digitProduct = 1;
    long long int originalNumber = num;

    // Calculate the sum and product of digits
    while (originalNumber != 0) {
        long long int digit = originalNumber % 10;
        digitSum += digit;
        digitProduct *= digit;
        originalNumber /= 10;
    }

    // Check if the sum of digits equals the product of digits
    if (digitSum == digitProduct) {
        printf("%s\n%lld is a Spy number!%s\n", YELLOW, num, RESET);
    } else {
        printf("%s\n%lld is NOT a Spy number.%s\n", YELLOW, num, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            spy();
            break;
        case 1: 
        case -1:
            numberClassification();
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

//numeric operations

// Function to calculate the sum of n numbers
void SumOfNumbers() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Numeric Operations>Sum of n Numbers\n%s", OLIVE, RESET);

    // Explanation of Sum
    printf("%s\nSum:%s\n The total obtained by adding all the numbers in a dataset.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the count of numbers
    setPromptColor(BLUE);
    int n = atoi(inputValidator("Enter the total numbers to input: ", "P", 2)); // Max 99 for now, can increase

    if (n <= 0) {
        SumOfNumbers();
        return;
    }

    // Array to store the numbers
    long double numbers[n];
    long double sum = 0; // To hold the sum of the numbers

    printf("%sEnter numbers (one per line):%s\n", GRAY, RESET);
    for (int i = 0; i < n; i++) {
        setPromptColor(VIOLET);
        numbers[i] = atof(inputValidator(">: ", "F", 10)); // Accepting only integers
        sum += numbers[i];
    }

    // Display the result
    printf("%s\nThe sum of numbers %s", YELLOW, RESET);
    for (int i = 0; i < n; i++) {
        printf("%s%.3Lf, ", PURPLE, numbers[i]);
    }
    printf("%sis %s%Lf\n%s", YELLOW, CYAN, sum, RESET);

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            SumOfNumbers();
            break;
        case 1:
        case -1:
            numericOperations();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to multiply number digit by digit 
int multiplicationDigitsByDigits(long long int num,int result[],int size) {
    //loop multiplies the number digit by digit and stores the result in the array
    long long int carry = 0;
    for (int i = 0; i < size; i++) {
        long long int product = result[i]* num + carry;
        result[i]=product % 10; //stores last digit in carry
        carry = product / 10;   //update carry with remaining digits
    }

    //loop to handle remaining digits of carry
    while (carry) {
        result[size]=carry%10; // stores last digit of carry in result array if remaining
        carry /=10; //update carry with remaining digits
        size++; // increment size of result array to store remaining digits of carry if any
    }
    
    return size;
    
}

// Function to calculate the factorial of a number upto 999
void Factorial() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Numeric Operations>Factorial\n%s", OLIVE, RESET);

    printf("%s\nFactorial:%s\n The factorial of a number is the product of all positive integers less than or equal to that number.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    int num = stoi(inputValidator("Enter a positive integer: ","P",3)); 
    int result[2570];
    result[0] = 1; // Initialize the first element of the array to 1 to handle the case when the input is 0 or 1
    int size=1;

    for (int i = 2; i <= num; i++) {
        size = multiplicationDigitsByDigits(i,result,size);
    }

    printf("%s\nThe Factorial of %d is%s: ",GOLD,num,RESET);
    for (int i = size - 1; i >= 0; i--) { // Print result in reverse
        printf("%s%d%s",CYAN,result[i],RESET);
    }
    printf("\n");

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            Factorial();
            break;
        case 1: 
        case -1:
            numericOperations();
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

//Function to calculate GCD of two numbers
long long int gcd(long long int num1,long long int num2) {

    // Handle edge cases for zero inputs
    if (num1 == 0 && num2 == 0) {
        return -1;
    } else if (num1 == 0) {
        return num2;
    } else if (num2 == 0) {
        return num1;
    } else {
 
        // Compute GCD using the Euclidean Algorithm
        while (num2 != 0) {
            long long int remainder = num1 % num2;
            num1 = num2;
            num2 = remainder;
        }
        return num1;
    }
}

// Function to take input for GCD 
void gcdDataEntry() {

    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Numeric Operations>GCD\n%s", OLIVE, RESET);

    // Explanation of GCD
    printf("%s\nGCD (Greatest Common Divisor):%s\n The largest positive integer that divides two numbers without leaving a remainder.%s\n", BROWN, GRAY, RESET);
    printf("%sNote: \n%s GCD is always positive. \n If one number is 0 GCD is the other number.\n If both number are 0 GCD is undefined.%s\n\n", BROWN, GRAY, RESET);
    
    setPromptColor(BLUE);
    long long int originalNum1 = atoll(inputValidator("Enter the first number: ", "I", 17));
    long long int num1 = llabs(originalNum1);
    setPromptColor(BLUE);
    long long int originalNum2 = atoll(inputValidator("Enter the second number: ", "I", 17));
    long long int num2 = llabs(originalNum2);

    // Handle edge cases for zero inputs
    long long int result = gcd(num1, num2);
    switch (result) {
    case -1:
        printf("%s\nGCD is undefined for two zeroes.%s\n", YELLOW, RESET);
        break;
    default:
        printf("%s\nThe GCD of %lld and %lld is: %lld%s\n", YELLOW, originalNum1, originalNum2, result, RESET);
        break;
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0: 
            gcdDataEntry();
            break;
        case 1: 
        case -1:
            numericOperations();
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

//Function to calculate LCM of two numbers
void lcm() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Numeric Operations>LCM\n%s", OLIVE, RESET);

    // Explanation of LCM
    printf("%s\nLCM (Least Common Multiple):%s\n The smallest positive integer that is divisible by both numbers.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    long long int originalNum1 = atoll(inputValidator("Enter the first number: ", "I", 15));
    long long int num1 = llabs(originalNum1);
    setPromptColor(BLUE);
    long long int originalNum2 = atoll(inputValidator("Enter the second number: ", "I", 15));
    long long int num2 = llabs(originalNum2);

    long long int result = gcd(num1,num2);
    // Handle zero input
    if (num1 == 0 || num2 == 0) {
        printf("%s\nThe LCM of %lld and %lld is 0.%s\n", YELLOW, originalNum1, originalNum2, RESET);
    } else {
        
        long long int result = gcd(num1,num2);
        // Calculate LCM using a safe formula to avoid overflow
        result = (num1 / result) * num2;

        printf("%s\nThe LCM of %lld and %lld is: %lld%s\n", YELLOW, originalNum1, originalNum2, result, RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            lcm();
            break;
        case 1:
        case -1:
            numericOperations();
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

// Digits operations
 
// Function to calculate the sum of digits upto 115 digits number(we can increase the limit if needed but for it program inputvaldator needed to be optimized)
void digitSum() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Sum\n%s", OLIVE, RESET);

    // Explanation of Digit Sum
    printf("%s\nDigit Sum:%s\n The sum of all digits in a given number, capable of handling numbers up to 115 digits(we can increase the limit if needed but for it program inputvaldator needed to be optimized).%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers
    int sum = 0;

    // Compute the sum of digits
    for (int i = 0; num[i] != '\0'; i++) {
        if (isdigit(num[i])) {
            sum += num[i] - '0'; // Convert char digit to integer and add to sum //we can also use atio function here
        }
    }

    printf("%s\nThe sum of the digits is: %d%s\n", YELLOW, sum, RESET);
    free(num);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            digitSum();
            break;
        case 1:
        case -1:
            digitOperations();
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

// Function to calculate the product of digits upto 115 digits number(we can increase the limit if needed but for it program inputvaldator needed to be optimized)
void digitProduct() {
    
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Product\n%s", OLIVE, RESET);

    // Explanation of Digit Product
    printf("%s\nDigit Product:%s\n The product of all digits in a given number, capable of handling numbers up to 115 digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers

    int result[500] = {1}; // Array to store the product digits with great precision, initialized with 1
    int size = 1; // Current size of the result array (starts with 1 digit: 1)

    // Multiply each digit
    for (int i = 0; num[i] != '\0'; i++) {
        if (isdigit(num[i])) {
            int digit = num[i] - '0'; //we can also use atio function here
            if (digit == 0) { // Early exit for 0
                size = 1;
                result[0] = 0;
                break;
            } else {
                size = multiplicationDigitsByDigits(digit, result, size); // Multiply digit by digit
            }
        }
    }

    printf("%s\nThe product of the digits is: ", YELLOW);
    for (int i = size - 1; i >= 0; i--) { // Print the result in reverse (highest digit first)
        printf("%s%d%s", CYAN, result[i], RESET);
    }
    printf("%s\n", RESET);
    free(num);

    switch (exitMenu()) {
        case 0:
            digitProduct();
            break;
        case 1:
        case -1:
            digitOperations();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to calculate the frequency of digits
void digitFrequency() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Frequency\n%s", OLIVE, RESET);

    // Explanation of Digit Frequency
    printf("%s\nDigit Frequency:%s\n The frequency of each digit in the given number, capable of handling numbers up to 115 digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers

    int freq[10] = {0}; // Frequency array to count digits

    // Count the frequency of each digit
    for (int i = 0; num[i] != '\0'; i++) {
        if (isdigit(num[i])) {
            freq[num[i] - '0']++; // Increment the count for the respective digit
        }
    }

    // Display the digit frequencies
    printf("%s\nDigit Frequency:%s\n", YELLOW, RESET);
    for (int i = 0; i < 10; i++) {
        if (freq[i] != 0) {
            printf("%s%d%s = %d times\n", CYAN, i, RESET, freq[i]);
        }
    }

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            digitFrequency();
            break;
        case 1:
        case -1:
            digitOperations();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to calculate the average of digits
void digitAverage() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Average\n%s", OLIVE, RESET);

    // Explanation of Digit Average
    printf("%s\nDigit Average:%s\n The average of the digits in the given number, capable of handling numbers up to 115 digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers

    float sum = 0;
    float count = 0;

    //I know i can use digitsum () function here but i am doing it manually because it is more convinient for me 
    // Calculate the sum of digits and the total number of digits
    for (int i = 0; num[i] != '\0'; i++) {
        if (isdigit(num[i])) {
            sum += num[i] - '0'; // Convert char digit to integer and add to sum//we can also use atio function here
            count++; // Increment the digit count
        }
    }

    // Calculate the average if there are digits
    float average = 0;
    if (count > 0) {
        average = sum / count; 
    }

    printf("%s\nThe average of the digits is: %s%.2f%s\n", YELLOW,CYAN ,average, RESET);

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            digitAverage();
            break;
        case 1:
        case -1:
            digitOperations();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break; 
    }
}

// Function to reverse a number
void digitReverse() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Average\n%s", OLIVE, RESET);

    // Explanation of Digit Average
    printf("%s\nDigit Reverse:%s\n To print the mirror image or the digits.%s\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers

    // Using the strrev function to reverse the string
    strrev(num);

    printf("%s\n\nReversed string:%s%s\n%s", YELLOW, CYAN, num, RESET);

}

// Function to sort the digits of a large number
void digitSort() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digit Operations>Digit Sort\n%s", OLIVE, RESET);

    // Explanation of Digit Sort
    printf("%s\nDigit Sort:%s\n Sort the digits of the given number in ascending order, capable of handling numbers up to 115 digits.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    char *num = inputValidator("Enter a number: ", "P", 115); // Input as a string to handle large numbers

    //Extract digits and store them in an int array
    int digits[115] = {0}; 
    int digitCount = 0;

    for (int i = 0; num[i] != '\0'; i++) {
        if (isdigit(num[i])) {
            digits[digitCount++] = num[i] - '0'; // Convert char digit to integer and store it // we can also use atoi function for it
        }
    }

    //Sort the digits array in ascending order
    for (int i = 0; i < digitCount - 1; i++) {
        for (int j = i + 1; j < digitCount; j++) {
            if (digits[i] > digits[j]) {
                // Swap the digits
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    printf("%s\nThe sorted digits are: ", YELLOW);
    for (int i = 0; i < digitCount; i++) {
        printf("%s%d", CYAN,digits[i]); // Print each digit in the sorted order
    }
    printf("%s\n", RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            digitSort();
            break;
        case 1:
        case -1:
            digitOperations();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

//Statistics

// Function to calculate the mean of numbers
void Mean() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Statistics>Mean\n%s", OLIVE, RESET);

    // Explanation of Mean
    printf("%s\nMean:%s\n The average of a set of numbers calculated as the sum of the numbers divided by the count of numbers.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the count of numbers
    setPromptColor(BLUE);
    // For now 99 number are enough if we want to input more than 99 we can increase the limit
    int n = atoi(inputValidator("Enter the total numbers to input: ", "P", 2)); 

    if (n == 0) {
        Mean();
    }

    // Array to store the numbers
    long long int numbers[n]; 
    long long int sum = 0.0; // Using long double for precision with large numbers

    printf("%sEnter numbers (one per line):%s\n", GRAY, RESET);

    for (int i = 0; i < n; i++) {
        setPromptColor(VIOLET);
        numbers[i] =atoll(inputValidator(">: ","I",10));//We are also excepting integers only if you want to input decimal number you can change I to F
        sum += numbers[i];
    }

    // Calculate mean
    long double mean = sum / n;

    // Display the result
    printf("%s\nThe mean of numbers %s", YELLOW, RESET);

    for (int i = 0; i < n; i++) {
        printf("%s%lld, ", PURPLE,numbers[i]);
    }
    printf("%sis %s%Lf\n%s", YELLOW, CYAN, mean, RESET);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            Mean();
            break;
        case 1:
        case -1:
            statistics();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to calculate the median of numbers
void Median() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Statistics>Median\n%s", OLIVE, RESET);

    // Explanation of Median
    printf("%s\nMedian:%s\n The middle value in a sorted list of numbers. If the list has an even number of elements, the median is the average of the two middle values.%s\n\n", BROWN, GRAY, RESET);

    setPromptColor(BLUE);
    // For now 99 numbers are enough; if we want to input more, we can increase the limit
    int n = atoi(inputValidator("Enter the number of elements: ", "P", 2)); 

    if (n == 0) {
        Median();
        return;
    }

    // Array to store the numbers
    long long int numbers[n];
    long long int sortedNumbers[n];

    printf("%sEnter numbers (one per line):%s\n", GRAY, RESET);
    for (int i = 0; i < n; i++) {
        setPromptColor(VIOLET);
        numbers[i] = atoll(inputValidator(">: ", "I", 10)); // Only integer inputs are accepted
    }

    // Sorting the array using Bubble Sort (can be replaced with optimized sorting)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedNumbers[j] > sortedNumbers[j + 1]) {
                long long int temp = sortedNumbers[j];
                sortedNumbers[j] = sortedNumbers[j + 1];
                sortedNumbers[j + 1] = temp;
            }
        }
    }

    // Calculate and display the median
    printf("%s\nThe median of the numbers : ", YELLOW);
    for (int i = 0; i < n; i++) {
        printf("%s%lld, ", PURPLE, numbers[i]);
    }
    if (n % 2 == 0) {
        // Even case: average of two middle elements
        long double medianValue1 = numbers[n / 2 - 1];
        long double medianValue2 = numbers[n / 2];
        printf(" %sare %s%Lf %sand%s %Lf\n%s", YELLOW, CYAN, medianValue1, YELLOW,CYAN,medianValue2, RESET);
    } else {
        // Odd case: middle element
        printf(" %sis %s%lld\n%s",YELLOW, CYAN, numbers[n / 2], RESET);
    }

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            Median();
            break;
        case 1:
        case -1:
            statistics();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to calculate the mode of numbers
void Mode() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Statistics>Mode\n%s", OLIVE, RESET);

    // Explanation of Mode
    printf("%s\nMode:%s\n The number(s) that appear most frequently in a set of data. If all numbers occur only once, there is no mode.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the count of numbers
    setPromptColor(BLUE);
    int n = atoi(inputValidator("Enter the number of elements: ", "P", 2)); // Max 99 for now, can increase

    if (n == 0) {
        Mode();
        return;
    }

    // Array to store the numbers
    long long int numbers[n];
    printf("%sEnter numbers (one per line):%s\n", GRAY, RESET);
    for (int i = 0; i < n; i++) {
        setPromptColor(VIOLET);
        numbers[i] = atoll(inputValidator(">: ", "I", 10));
    }

    // Sort the array (to handle large numbers without excessive memory use)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] > numbers[j]) {
                long long int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Count frequencies
    long long int currentNum = numbers[0], maxFreq = 1, currentFreq = 1;
    long long int modes[n];
    int modeCount = 0;

    for (int i = 1; i < n; i++) {
        if (numbers[i] == currentNum) {
            currentFreq++;
        } else {
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                modeCount = 0;
                modes[modeCount++] = currentNum;
            } else if (currentFreq == maxFreq) {
                modes[modeCount++] = currentNum;
            }
            currentNum = numbers[i];
            currentFreq = 1;
        }
    }

    // Check the last group of numbers
    if (currentFreq > maxFreq) {
        maxFreq = currentFreq;
        modeCount = 0;
        modes[modeCount++] = currentNum;
    } else if (currentFreq == maxFreq) {
        modes[modeCount++] = currentNum;
    }

    // Display the result
    printf("%s\nMode(s) of numbers: %s", YELLOW, RESET);
    for (int i = 0; i < n; i++) {
        printf("%s%lld, ", PURPLE, numbers[i]);
    }

    if (maxFreq > 1) {
        printf("%s are:%s ", YELLOW, RESET);
        for (int i = 0; i < modeCount; i++) {
            printf("%s%lld%s ", CYAN, modes[i], RESET);
        }
    } else {
        printf("%sNo mode (all numbers appear only once).%s", CYAN, RESET);
    }
    printf("\n");

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            Mode();
            break;
        case 1:
        case -1:
            statistics();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

//Sequences

// Helper function to print a large number stored in an array
void printLargeNumber(int num[]) {
    int leadingZero = 1;
    for (int i = 999; i >= 0; i--) {
        if (num[i] != 0 || !leadingZero) {
            printf("%d", num[i]);
            leadingZero = 0;
        }
    }
    if (leadingZero) { // If all digits are zero
        printf("0");
    }
}

// Function to add two large numbers digit by digit
void additionByDigits(int a[], int b[], int result[]) {
    int carry = 0;
    for (int i = 0; i < 1000; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

// Function to generate the Fibonacci Sequence
void FibonacciSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Fibonacci\n%s", OLIVE, RESET);

    // Explanation of Fibonacci Sequence
    printf("%s\nFibonacci Sequence:%s\n A sequence where each number is the sum of the two preceding ones, starting with 0 and 1.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the number of terms
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    if (n == 0) {
        FibonacciSequence();
        return;
    }

    // Arrays to store digits of Fibonacci numbers
    int first[1000] = {0}, second[1000] = {0}, next[1000] = {0};
    first[0] = 0;  // First Fibonacci number
    second[0] = 1; // Second Fibonacci number

    // Display the result
    printf("%s\nFibonacci Sequence:%s\n", YELLOW, RESET);

    setPromptColor(PURPLE);
    for (int i = 0; i < n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        if (i == 0) {
            printLargeNumber(first); // Print the first number
        } else if (i == 1) {
            printLargeNumber(second); // Print the second number
        } else {
            additionByDigits(first, second, next); // Calculate next Fibonacci number

            // Shift numbers for the next iteration
            for (int j = 0; j < 1000; j++) {
                first[j] = second[j];
                second[j] = next[j];
            }

            printLargeNumber(next); // Print the next number
        }

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("%s\nCalculation completed successfully!%s\n", GREEN, RESET);

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            FibonacciSequence();
            break;
        case 1:
        case -1:
            Sequences(); 
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to generate the Triangular Sequence
void TriangularSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Triangular Sequence\n%s", OLIVE, RESET);

    printf("%s\nTriangular Sequence:%s\n A sequence where each term is the sum of the first n natural numbers.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the number of terms
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    // Display the sequence
    printf("%s\nTriangular Sequence:%s\n", YELLOW, RESET);
    setPromptColor(PURPLE);

    for (int i = 1; i <= n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        long long triangularNumber = (long long)i * (i + 1) / 2; // Calculate triangular number
        printf("%lld", triangularNumber);

        if (i < n) {
            printf(", ");
        }
    }

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            TriangularSequence();
            break;
        case 1:
        case -1:
            Sequences();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to generate the Squares Sequence
void SquaresSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Squares Sequence\n%s", OLIVE, RESET);

    printf("%s\nSquares Sequence:%s\n A sequence where each term is the square of a natural number.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the number of terms
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    // Display the sequence
    printf("%s\nSquares Sequence:%s\n", YELLOW, RESET);
    setPromptColor(PURPLE);

    for (int i = 1; i <= n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        printf("%d", i * i); // Calculate and print the square of the number

        if (i < n) {
            printf(", ");
        }
    }
    printf("\n");

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            SquaresSequence();
            break;
        case 1:
        case -1:
            Sequences();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to generate the Cubes Sequence
void CubesSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Cubes Sequence\n%s", OLIVE, RESET);

    printf("%s\nCubes Sequence:%s\n A sequence where each term is the cube of a natural number.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for the number of terms
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    // Display the sequence
    printf("%s\nCubes Sequence:%s\n", YELLOW, RESET);
    setPromptColor(PURPLE);

    for (long int i = 1; i <= n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        printf("%ld", i * i * i); // Calculate and print the cube of the number

        if (i < n) {
            printf(", ");
        }
    }
    printf("\n");

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            CubesSequence();
            break;
        case 1:
        case -1:
            Sequences();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to generate the Arithemetic Sequence
void ArithmeticSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Arithmetic Sequence\n%s", OLIVE, RESET);

    printf("%s\nArithmetic Sequence:%s\n A sequence of numbers where each term is obtained by adding a constant to the previous term.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for first term and common difference
    setPromptColor(BLUE);
    int firstTerm = stoi(inputValidator("Enter the first term: ", "I", 10));
    setPromptColor(BLUE);
    int commonDifference = stoi(inputValidator("Enter the common difference: ", "I", 10));
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    // Display the sequence
    printf("%s\nArithmetic Sequence:%s\n", YELLOW, RESET);
    setPromptColor(PURPLE);

    for (int i = 0; i < n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        printf("%lld", firstTerm + i * commonDifference);

        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            ArithmeticSequence();
            break;
        case 1:
        case -1:
            Sequences();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

// Function to generate the Geometric Sequence
void GeometricSequence() {
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Sequences>Geometric Sequence\n%s", OLIVE, RESET);

    printf("%s\nGeometric Sequence:%s\n A sequence of numbers where each term is obtained by multiplying the previous term by a constant.%s\n\n", BROWN, GRAY, RESET);

    // Input validation for first term and common ratio
    setPromptColor(BLUE);
    int firstTerm = stoi(inputValidator("Enter the first term (a): ", "I", 10));
    setPromptColor(BLUE);
    int commonRatio = stoi(inputValidator("Enter the common ratio (r): ", "I", 3));
    setPromptColor(BLUE);
    int n = stoi(inputValidator("Enter the number of terms: ", "P", 3));

    // Display the sequence
    printf("%s\nGeometric Sequence:%s\n", YELLOW, RESET);
    setPromptColor(PURPLE);

    for (int i = 0; i < n; i++) {
        printf("%s", (i % 2 == 0) ? CYAN : PURPLE);
        printf("%lld", (long long)firstTerm * pow(commonRatio, i));

        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Handle the exit menu options
    int choice = exitMenu();
    switch (choice) {
        case 0:
            GeometricSequence();
            break;
        case 1:
        case -1:
            Sequences();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}
