#ifndef NUMBERMANIPULATION_H
#define NUMBERMANIPULATION_H

//Number Classification

//Function to check if the input is a even and odd
void evenOdd();

//function to check if the input is a prime number or composite
void primeComposite();

//Function to check if the input is perfect number
void perfect();

//Function to check if the input is Armstrong/narcissistic number
void Armstrong();

// Function to check if the input is a Kaprekar number
void kaprekar();

// Function to check if the input is a Palindrome number
void palindrome();

// Function to check if two numbers are coprime
void coprime();

// Function to check if the input is a Niven/Harshad number
void niven();

// Function to check if the input is a Deficient number
void deficient();

// Function to check if the input is an Abundant number
void abundant();

// Function to check if the input is a Spy number
void spy();

//Numeric Operations

// Function to calculate the sum of n numbers
void SumOfNumbers();

// Function to multiply number digit by digit 
int multiplicationDigitsByDigits(long long int num,int result[],int size);

// Function to calculate the factorial of a number
void Factorial();

//Function to calculate GCD of two numbers
long long int gcd(long long int num1,long long int num2);

// Function to calculate the GCD of two numbers
void gcdDataEntry();

//Function to calculate LCM of two numbers
void lcm();

// Function to calculate the sum of digits for large numbers (up to 115 digits)
void digitSum();

// Function to calculate the product of digits for large numbers (up to 115 digits)
void digitProduct();

// Function to calculate the frequency of digits
void digitFrequency();

// Function to calculate the average of digits
void digitAverage();

// Function to reverse a number
void digitReverse();

// Function to sort the digits of a large number
void digitSort();

// Function to calculate the mean of numbers
void Mean();

// Function to calculate the median of numbers
void Median();

// Function to calculate the mode of numbers
void Mode();

// Function to generate the Fibonacci Sequence
void FibonacciSequence();

// Function to generate the Triangular Sequence
void TriangularSequence();

// Function to generate the Squares Sequence
void SquaresSequence();

// Function to generate the Cubes Sequence
void CubesSequence();

// Function to generate the Arithemetic Sequence
void ArithmeticSequence();

// Function to generate the Geometric Sequence
void GeometricSequence();
#endif