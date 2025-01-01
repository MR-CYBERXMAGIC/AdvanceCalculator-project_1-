#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "menu.h"
#include "string.h"
#include "inputValidator.h"
#include "shapes.h"
#include "shapesIllustration.h"
#include "menu.h"

// Function to calculate the area of a circle
void circleArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>circle>Area\n\n%s",OLIVE,RESET);
    
    circleIllustration();

    // Prompt for radius input
    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter radius: ","PF",15));
    double areaOfCircle = pow(radius,2) * 3.14159 ;

    printf("%s\nArea of circle is:%s%lf\n\n", BROWN, RESET,areaOfCircle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            circleArea();
            break;
        case 1: case -1:
            circle();
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

// Function to calculate the circumference of a circle
void circleCircumference() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>circle>Circumference\n\n%s",OLIVE,RESET);
   
    circleIllustration();

    // Prompt for radius input
    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter radius: ","PF",15));
    double circumferenceOfCircle = 2 * 3.14159 * radius;

    printf("%s\nCircumference of circle is: %s%lf\n\n", BROWN, RESET,circumferenceOfCircle);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            circleCircumference();
            break;
        case 1: case -1:
            circle();
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

// display options for circle calculations
void circle() {

    const char *options[] = {"Area","Circumference"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>circle\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption)
    {
    case 0:
        circleArea();
        break;
    case 1:
        circleCircumference();
        break;
    case -1: 
        shapes2D();
        break;
    default:
        break;
    }
}

// Function to calculate the area of a square
void squareArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>square>Area\n\n%s",OLIVE,RESET);
    
    squareIllustration();
    
    setPromptColor(PINK);
    double side = stof(inputValidator("Enter side: ","PF",15));
    double areaOfSquare = pow(side,2);

    printf("%s\nArea of square is:%s%lf\n\n", BROWN, RESET,areaOfSquare);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            squareArea();
            break;
        case 1: case -1:
            square();
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

// Function to calculate the perimeter of a square
void squarePerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>square>Perimeter\n\n%s",OLIVE,RESET);
    
    squareIllustration();
    
    // Square illustration
    setPromptColor(PINK);
    double side = stof(inputValidator("Enter side: ","PF",15));
    double perimeterOfSquare = 4 * side;

    printf("%s\nPerimeter of square is:%s%lf\n\n", BROWN, RESET,perimeterOfSquare);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            squarePerimeter();
            break;
        case 1: case -1:
            square();
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

// Function to calculate the diagonal of a square
void squareDiagonal() {

    clearScreen(1);
    printf("%smainMenushapes>2d shapes>square>Diagonal\n\n%s",OLIVE,RESET);
    
    squareIllustration();

    setPromptColor(PINK);
    double side = stof(inputValidator("Enter side: ","PF",15));
    double diagonalOfSquare = side * sqrt(2);

    printf("%s\nPerimeter of square is:%s%lf\n\n", BROWN, RESET,diagonalOfSquare);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            squarePerimeter();
            break;
        case 1: case -1:
            square();
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

// display options for square calculations
void square() {

    const char *options[] = {"Area","Perimeter","Diagonal"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>square\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case 0:
        squareArea();
        break;
    case 1:
        squarePerimeter();
        break;
    case 2:
        squareDiagonal();
        break;    
    case -1: 
        shapes2D();
        break;
    default:
        break;
    }
}

// Function to calculate the area of a rectangle
void rectangleArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rectangle>Area\n\n%s",OLIVE,RESET);
    
    rectangleIllustration();
    
    setPromptColor(PINK);
    double length = stof(inputValidator("Enter length: ","PF",15));
    setPromptColor(PINK);
    double breadth = stof(inputValidator("Enter breadth: ","PF",15));
    double areaOfRectangle = length * breadth;

    printf("%s\nArea of Rectangle is:%s%lf\n\n", BROWN, RESET,areaOfRectangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            rectangleArea();
            break;
        case 1:
        case -1:
            rectangle();
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

// Function to calculate the perimeter of a rectangle
void rectanglePerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rectangle>Perimeter\n\n%s",OLIVE,RESET);
    
    rectangleIllustration();

    setPromptColor(PINK);
    double length = stof(inputValidator("Enter length: ","PF",15));
    setPromptColor(PINK);
    double breadth = stof(inputValidator("Enter breadth: ","PF",15));
    double perimeterOfRectangle = 2 * (length + breadth);

    printf("%s\nPerimeter of Rectangle is: %s%lf\n\n", BROWN, RESET,perimeterOfRectangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            rectanglePerimeter();
            break;
        case 1:
        case -1:
            rectangle();
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

// Function to calculate the diagonal of a rectangle
void rectangleDiagonal() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rectangle>Diagonal\n\n%s",OLIVE,RESET);
    
    rectangleIllustration();

    setPromptColor(PINK);
    double length = stof(inputValidator("Enter length: ","PF",15));
    setPromptColor(PINK);
    double breadth = stof(inputValidator("Enter breadth: ","PF",15));
    double diagonalOfRectangle = sqrt(pow(length,2)+pow(breadth,2));

    printf("%s\nDiagonal of Rectangle is: %s%lf\n\n", BROWN, RESET, diagonalOfRectangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            rectangleDiagonal();
            break;
        case 1:
        case -1:
            rectangle();
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

// display options for rectangle calculations
void rectangle() {
    
    const char *options[] = {"Area","Perimeter","Diagonal"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rectangle\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case 0:
        rectangleArea();
        break;
    case 1:
        rectanglePerimeter();
        break;
    case 2:
        rectangleDiagonal();
        break;    
    case -1: 
        shapes2D();
        break;
    default:
        break;
    }
}

// Function to calculate the area of a triangle
void triangleArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle>Area\n\n%s",OLIVE,RESET);
    
    triangleIllustration();
    
    setPromptColor(PINK);
    double length = stof(inputValidator("Enter length: ","PF",15));
    setPromptColor(PINK);
    double heigth = stof(inputValidator("Enter heigth: ","PF",15));
    double areaOfTriangle = 0.5 * (length * heigth);

    printf("%s\nArea of Triangle is:%s%lf\n\n", BROWN, RESET,areaOfTriangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            triangleArea();
            break;
        case 1:
        case -1:
            triangle();
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

// Function to calculate the perimeter of a triangle
void trianglePerimeter() {
    
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle>Perimeter\n\n%s",OLIVE,RESET);
    
    triangleIllustration();
    
    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side1: ","PF",15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side2: ","PF",15));
    setPromptColor(PINK);
    double side3 = stof(inputValidator("Enter Side3: ","PF",15));
    double perimeterOfTriangle = side1 + side2 + side3;

    printf("%s\nPerimeter of Triangle is:%s%lf\n\n", BROWN, RESET,perimeterOfTriangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            trianglePerimeter();
            break;
        case 1:
        case -1:
            triangle();
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

// Function to calculate the semi perimeter of a triangle
void triangleSemiPerimeter() {
    
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle>Semi Perimeter\n\n%s",OLIVE,RESET);
    
    triangleIllustration();

    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side1: ","PF",15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side2: ","PF",15));
    setPromptColor(PINK);
    double side3 = stof(inputValidator("Enter Side3: ","PF",15));
    double semiPerimeterOfTriangle = (side1 + side2 + side3)/2.0;

    printf("%s\nSemi Perimeter of Triangle is:%s%lf\n\n", BROWN, RESET,semiPerimeterOfTriangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            triangleSemiPerimeter();
            break;
        case 1:
        case -1:
            triangle();
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

// Function to calculate the inradius of a triangle
void triangleInRadius() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle>in radius\n\n%s",OLIVE,RESET);
    
    triangleIllustration();
    
    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side1: ","PF",15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side2: ","PF",15));
    setPromptColor(PINK);
    double side3 = stof(inputValidator("Enter Side3: ","PF",15));
    double semiPerimeterOfTriangle = (side1 + side2 + side3)/2.0;
    double areaOfTriangle = sqrt(semiPerimeterOfTriangle * (semiPerimeterOfTriangle - side1) * (semiPerimeterOfTriangle - side2) * (semiPerimeterOfTriangle - side3));
    double inRadiusOfTriangle = areaOfTriangle / semiPerimeterOfTriangle;

    printf("%s\nIn Radius of Triangle is: %s%lf\n\n", BROWN, RESET,inRadiusOfTriangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            triangleInRadius();
            break;
        case 1:
        case -1:
            triangle();
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

// Function to calculate the Circumradius of a triangle
void triangleCircumRadius() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle>Circumradius\n\n%s",OLIVE,RESET);
    
    triangleIllustration();

    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side1: ","PF",15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side2: ","PF",15));
    setPromptColor(PINK);
    double side3 = stof(inputValidator("Enter Side3: ","PF",15));
    double semiPerimeterOfTriangle = (side1 + side2 + side3)/2.0;
    double areaOfTriangle = sqrt(semiPerimeterOfTriangle * (semiPerimeterOfTriangle - side1) * (semiPerimeterOfTriangle - side2) * (semiPerimeterOfTriangle - side3));
    double circumradiusOfTriangle = (side1 * side2 * side3)/(4.0 * areaOfTriangle);

    printf("%s\nCircumradius of Triangle is:%s%lf\n\n", BROWN, RESET,areaOfTriangle);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            triangleCircumRadius();
            break;
        case 1:
        case -1:
            triangle();
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

// Display options for triangle calculations
void triangle() {

    const char *options[] = {"Area","Perimeter","Semi Perimeter","In Radius","Circum Radius"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>triangle\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 5);

    switch (selectedOption)
    {
    case 0:
        triangleArea();
        break;
    case 1:
        trianglePerimeter();
        break;
    case 2:
        triangleSemiPerimeter();
        break;
    case 3:
        triangleInRadius();
        break;
    case 4:
        triangleCircumRadius();
        break;    
    case -1: 
        shapes2D();
        break;
    default:
        break;
    }
}

// Function to calculate the area of a trapezoid
void trapezoidArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>trapezoid>Area\n\n%s",OLIVE,RESET);

    trapeziodIllustration();

    setPromptColor(PINK);
    double base1 = stof(inputValidator("Enter Base 1: ","PF",15));
    setPromptColor(PINK);
    double base2 = stof(inputValidator("Enter Base 2: ","PF",15));
    setPromptColor(PINK);
    double heigth = stof(inputValidator("Enter heigth: ","PF",15));
    double areaOfTrapezoid = 0.5 * (base1 + base2) * heigth;

    printf("%s\nArea of Trapezoid is:%s%lf\n\n", BROWN, RESET,areaOfTrapezoid);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            trapezoidArea();
            break;
        case 1:
        case -1:
            trapezoid();
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

// Function to calculate the perimeter of a trapezoid
void trapezoidPerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>trapezoid>perimeter\n\n%s",OLIVE,RESET);

    trapeziodIllustration();

    setPromptColor(PINK);
    double base1 = stof(inputValidator("Enter Base 1: ","PF",15));
    setPromptColor(PINK);
    double base2 = stof(inputValidator("Enter Base 2: ","PF",15));
    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side 1: ","PF",15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side 2: ","PF",15));
    double areaOfTrapezoid = base1 + base2 + side1 + side2;

    printf("%s\nPerimeter of Trapezoid is:%s%lf\n\n", BROWN, RESET,areaOfTrapezoid);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            trapezoidPerimeter();
            break;
        case 1:
        case -1:
            trapezoid();
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

// Display options for trapezoid calculations
void trapezoid() {

    const char *options[] = {"Area","Perimeter"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>trapezoid\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption)
    {
    case 0:
        trapezoidArea();
        break;
    case 1:
        trapezoidPerimeter();
        break;    
    case -1: 
        shapes2D();
        break;
    default:
        break;
    }
}

// Function to calculate the area of a parallelogram
void parallelogramArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>parallelogram>Area\n\n%s", OLIVE, RESET);

    parallelogramIllustration();

    setPromptColor(PINK);
    double base = stof(inputValidator("Enter Base: ", "PF", 15));
    setPromptColor(PINK);
    double height = stof(inputValidator("Enter Height: ", "PF", 15));
    double areaOfParallelogram = base * height;

    printf("%s\nArea of Parallelogram is: %s%lf\n\n", BROWN, RESET, areaOfParallelogram);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            parallelogramArea();
            break;
        case 1:
        case -1:
            parallelogram();
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

// Function to calculate the perimeter of a parallelogram
void parallelogramPerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>parallelogram>Perimeter\n\n%s", OLIVE, RESET);

    parallelogramIllustration();
    
    setPromptColor(PINK);
    double base = stof(inputValidator("Enter Base: ", "PF", 15));
    setPromptColor(PINK);
    double side = stof(inputValidator("Enter Side Length: ", "PF", 15));
    double perimeterOfParallelogram = 2 * (base + side);

    printf("%s\nPerimeter of Parallelogram is: %s%lf\n\n", BROWN, RESET, perimeterOfParallelogram);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            parallelogramPerimeter();
            break;
        case 1:
        case -1:
            parallelogram();
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

// Display options for parallelogram calculations
void parallelogram() {

    const char *options[] = {"Area", "Perimeter"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>parallelogram\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            parallelogramArea();
            break;
        case 1:
            parallelogramPerimeter();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a rhombus
void rhombusArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rhombus>Area\n\n%s", OLIVE, RESET);

    rhombusIllustration();

    setPromptColor(PINK);
    double d1 = stof(inputValidator("Enter Diagonal 1: ", "PF", 15));
    setPromptColor(PINK);
    double d2 = stof(inputValidator("Enter Diagonal 2: ", "PF", 15));
    double areaOfRhombus = 0.5 * d1 * d2;

    printf("%s\nArea of Rhombus is: %s%lf\n\n", BROWN, RESET, areaOfRhombus);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            rhombusArea();
            break;
        case 1:
        case -1:
            rhombus();
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

// Function to calculate the perimeter of a rhombus
void rhombusPerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rhombus>Perimeter\n\n%s", OLIVE, RESET);

    rhombusIllustration();

    setPromptColor(PINK);
    double side = stof(inputValidator("Enter Side Length: ", "PF", 15));
    double perimeterOfRhombus = 4 * side;

    printf("%s\nPerimeter of Rhombus is: %s%lf\n\n", BROWN, RESET, perimeterOfRhombus);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            rhombusPerimeter();
            break;
        case 1:
        case -1:
            rhombus();
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

// Display options for rhombus calculations
void rhombus() {

    const char *options[] = {"Area", "Perimeter"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>rhombus\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            rhombusArea();
            break;
        case 1:
            rhombusPerimeter();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a kite
void kiteArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>kite>Area\n\n%s", OLIVE, RESET);

    kiteIllustration();

    setPromptColor(PINK);
    double d1 = stof(inputValidator("Enter Diagonal 1: ", "PF", 15));
    setPromptColor(PINK);
    double d2 = stof(inputValidator("Enter Diagonal 2: ", "PF", 15));
    double areaOfKite = 0.5 * d1 * d2;

    printf("%s\nArea of Kite is: %s%lf\n\n", BROWN, RESET, areaOfKite);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            kiteArea();
            break;
        case 1:
        case -1:
            kite();
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

// Function to calculate the perimeter of a kite
void kitePerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>kite>Perimeter\n\n%s", OLIVE, RESET);

    kiteIllustration();

    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side 1: ", "PF", 15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side 2: ", "PF", 15));
    double perimeterOfKite = 2 * (side1 + side2);

    printf("%s\nPerimeter of Kite is: %s%lf\n\n", BROWN, RESET, perimeterOfKite);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            kitePerimeter();
            break;
        case 1:
        case -1:
            kite();
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

// Function to calculate the unknown diagonal of a kite
void kiteDiagonal() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>kite>Diagonal\n\n%s", OLIVE, RESET);

    kiteIllustration();

    setPromptColor(PINK);
    double knownDiagonal = stof(inputValidator("Enter Known Diagonal: ", "PF", 15));
    setPromptColor(PINK);
    double areaOfKite = stof(inputValidator("Enter Area of Kite: ", "PF", 15));
    double unknownDiagonal = (2 * areaOfKite) / knownDiagonal;

    printf("%s\nThe Unknown Diagonal of Kite is: %s%lf\n\n", BROWN, RESET, unknownDiagonal);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            kiteDiagonal();
            break;
        case 1:
        case -1:
            kite();
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

// Display options for kite calculations
void kite() {

    const char *options[] = {"Area", "Perimeter","Diagonal"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>kite\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            kiteArea();
            break;
        case 1:
            kitePerimeter();
            break;
        case 2:
            kiteDiagonal();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a dart (kite)
void dartArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>dart>Area\n\n%s", OLIVE, RESET);

    dartIllustration();

    setPromptColor(PINK);
    double d1 = stof(inputValidator("Enter Diagonal 1: ", "PF", 15));
    setPromptColor(PINK);
    double d2 = stof(inputValidator("Enter Diagonal 2: ", "PF", 15));
    double areaOfDart = 0.5 * d1 * d2;

    printf("%s\nArea of Dart is: %s%lf\n\n", BROWN, RESET, areaOfDart);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            dartArea();
            break;
        case 1:
        case -1:
            dart();
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

// Function to calculate the perimeter of a dart (kite)
void dartPerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>dart>Perimeter\n\n%s", OLIVE, RESET);

    dartIllustration();

    setPromptColor(PINK);
    double side1 = stof(inputValidator("Enter Side 1 Length: ", "PF", 15));
    setPromptColor(PINK);
    double side2 = stof(inputValidator("Enter Side 2 Length: ", "PF", 15));
    double perimeterOfDart = 2 * (side1 + side2);

    printf("%s\nPerimeter of Dart is: %s%lf\n\n", BROWN, RESET, perimeterOfDart);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            dartPerimeter();
            break;
        case 1:
        case -1:
            dart();
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

// Function to calculate the unknown diagonal of a dart
void dartDiagonal() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>dart>Diagonal\n\n%s", OLIVE, RESET);

    dartIllustration();

    setPromptColor(PINK);
    double knownDiagonal = stof(inputValidator("Enter Known Diagonal: ", "PF", 15));
    setPromptColor(PINK);
    double areaOfDart = stof(inputValidator("Enter Area of Dart: ", "PF", 15));
    double unknownDiagonal = (2 * areaOfDart) / knownDiagonal;

    printf("%s\nThe Unknown Diagonal of Dart is: %s%lf\n\n", BROWN, RESET, unknownDiagonal);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            dartDiagonal();
            break;
        case 1:
        case -1:
            dart();
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

// Display options for dart calculations
void dart() {

    const char *options[] = {"Area", "Perimeter","Diagonal"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>dart\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            dartArea();
            break;
        case 1:
            dartPerimeter();
            break;
        case 2:
            dartDiagonal();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of an ellipse
void ellipseArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>ellipse>Area\n\n%s", OLIVE, RESET);

    ellipseIllustration();

    setPromptColor(PINK);
    double a = stof(inputValidator("Enter Semi-Major Axis (a): ", "PF", 15));
    setPromptColor(PINK);
    double b = stof(inputValidator("Enter Semi-Minor Axis (b): ", "PF", 15));
    double areaOfEllipse = 3.0 * a * b;

    printf("%s\nArea of Ellipse is: %s%lf\n\n", BROWN, RESET, areaOfEllipse);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ellipseArea();
            break;
        case 1:
        case -1:
            ellipse();
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

// Function to calculate the perimeter (approximate circumference) of an ellipse
void ellipsePerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>ellipse>Perimeter\n\n%s", OLIVE, RESET);

    ellipseIllustration();

    setPromptColor(PINK);
    double a = stof(inputValidator("Enter Semi-Major Axis (a): ", "PF", 15));
    setPromptColor(PINK);
    double b = stof(inputValidator("Enter Semi-Minor Axis (b): ", "PF", 15));
    double perimeterOfEllipse = 3.14159  * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));

    printf("%s\nPerimeter of Ellipse (Approximate) is: %s%lf\n\n", BROWN, RESET, perimeterOfEllipse);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ellipsePerimeter();
            break;
        case 1:
        case -1:
            ellipse();
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

// Display options for ellipse calculations
void ellipse() {

    const char *options[] = {"Area", "Perimeter"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>ellipse\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            ellipseArea();
            break;
        case 1:
            ellipsePerimeter();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a sector of a circle
void sectorArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>sector of circle>Area\n\n%s", OLIVE, RESET);

    sectorOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angle = stof(inputValidator("Enter Central Angle (in degrees): ", "PF", 15));
    double areaOfSector = (angle / 360.0) * 3.14159 * radius * radius;

    printf("%s\nArea of Sector is: %s%lf\n\n", BROWN, RESET, areaOfSector);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sectorArea();
            break;
        case 1:
        case -1:
            sectorOfCircle();
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

// Function to calculate the arc length of a sector of a circle
void sectorArcLength() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>sector of circle>Arc Length\n\n%s", OLIVE, RESET);

    sectorOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angle = stof(inputValidator("Enter Central Angle (in degrees): ", "PF", 15));
    double arcLength = (angle / 360.0) * 2 * 3.14159 * radius;

    printf("%s\nArc Length of Sector is: %s%lf\n\n", BROWN, RESET, arcLength);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sectorArcLength();
            break;
        case 1:
        case -1:
            sectorOfCircle();
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

// Function to calculate the chord length of a sector of a circle
void sectorChordLength() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>sector of circle>Chord Length\n\n%s", OLIVE, RESET);

    sectorOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angleDegrees = stof(inputValidator("Enter Central Angle (in degrees): ", "PF", 15));
    double angleRadians = angleDegrees * 3.14159  / 180.0;  // Convert angle to radians

    double chordLength = 2 * radius * sin(angleRadians / 2);

    printf("%s\nChord Length of Sector is: %s%lf\n\n", BROWN, RESET, chordLength);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sectorChordLength();
            break;
        case 1:
        case -1:
            sectorOfCircle();
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

// Display options for sector of a circle calculations
void sectorOfCircle() {

    const char *options[] = {"Area", "Arc Length", "Chord Length"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>sector of circle\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            sectorArea();
            break;
        case 1:
            sectorArcLength();
            break;
        case 2:
            sectorChordLength();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a segment
void segmentArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Segment of circle>Area\n\n%s", OLIVE, RESET);

    segmentOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angle = stof(inputValidator("Enter Angle (in radians): ", "PF", 15));
    
    double areaOfSegment = 0.5 * radius * radius * (angle - sin(angle));
    
    printf("%s\nArea of Segment is: %s%lf\n\n", BROWN, RESET, areaOfSegment);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            segmentArea();
            break;
        case 1:
        case -1:
            segmentOfCircle();
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

// Function to calculate the chord length of a segment
void segmentChordLength() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Segment of circle>Chord Length\n\n%s", OLIVE, RESET);

    segmentOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angle = stof(inputValidator("Enter Angle (in radians): ", "PF", 15));
    
    double chordLength = 2 * radius * sin(angle / 2);
    
    printf("%s\nChord Length of Segment is: %s%lf\n\n", BROWN, RESET, chordLength);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            segmentChordLength();
            break;
        case 1:
        case -1:
            segmentOfCircle();
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

// Function to calculate the arc length of a segment
void segmentArcLength() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Segment of circle>Arc Length\n\n%s", OLIVE, RESET);

    segmentOfCircleIllustration();

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter Radius: ", "PF", 15));
    setPromptColor(PINK);
    double angle = stof(inputValidator("Enter Angle (in radians): ", "PF", 15));
    
    double arcLength = radius * angle;
    
    printf("%s\nArc Length of Segment is: %s%lf\n\n", BROWN, RESET, arcLength);
    
    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            segmentArcLength();
            break;
        case 1:
        case -1:
            segmentOfCircle();
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

// Display options for segment of a circle calculations
void segmentOfCircle() {

    const char *options[] = {"Area", "Chord Length", "Arc Length"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>circle>Segment\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            segmentArea();
            break;
        case 1:
            segmentChordLength();
            break;    
        case 2:
            segmentArcLength();
            break;
        case -1: 
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a ring
void ringArea() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Annulus (Ring)>Area\n\n%s", OLIVE, RESET);

    ringIllustration();

    setPromptColor(PINK);
    double outerRadius = stof(inputValidator("Enter Outer Radius (R): ", "PF", 15));
    double innerRadius = stof(inputValidator("Enter Inner Radius (r): ", "PF", 15));
    
    if (innerRadius >= outerRadius) {
        printf("%s\nError: Inner radius should be less than outer radius.%s\n\n", RED, RESET);
        ringArea();
        return;
    }
    
    double area = 3.14159 * (outerRadius * outerRadius - innerRadius * innerRadius);
    printf("%s\nArea of Ring is: %s%lf\n\n", BROWN, RESET, area);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ringArea();
            break;
        case 1:
        case -1:
            ring();
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

// Function to calculate the perimeter of a ring
void ringPerimeter() {

    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Annulus (Ring)>Perimeter\n\n%s", OLIVE, RESET);

    ringIllustration();

    setPromptColor(PINK);
    double outerRadius = stof(inputValidator("Enter Outer Radius (R): ", "PF", 15));
    double innerRadius = stof(inputValidator("Enter Inner Radius (r): ", "PF", 15));

    if (innerRadius >= outerRadius) {
        printf("%s\nError: Inner radius should be less than outer radius.%s\n\n", RED, RESET);
        ringPerimeter();
        return;
    }

    double perimeter = 2 * 3.14159 * (outerRadius + innerRadius);
    printf("%s\nPerimeter of Ring is: %s%lf\n\n", BROWN, RESET, perimeter);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            ringPerimeter();
            break;
        case 1:
        case -1:
            ring();
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

// Display options for ring calculations
void ring() {

    const char *options[] = {"Area", "Perimeter"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>Annulus (Ring)\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            ringArea();
            break;
        case 1:
            ringPerimeter();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the area of a regular polygon
void regularPolygonArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon>Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    int n = atoi(inputValidator("Enter the number of sides (n): ", "P", 15));
    double s = stof(inputValidator("Enter the side length (s): ", "PF", 15));

    double apothem = s / (2 * tan(3.14159 / n));
    double perimeter = n * s;
    double area = 0.5 * perimeter * apothem;

    printf("%s\nArea of Regular Polygon is: %s%lf\n\n", BROWN, RESET, area);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            regularPolygonArea();
            break;
        case 1:
        case -1:
            regularPolygon();
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

// Function to calculate the perimeter of a regular polygon
void regularPolygonPerimeter() {
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon>Perimeter\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    int n = atoi(inputValidator("Enter the number of sides (n): ", "P", 15));
    double s = stof(inputValidator("Enter the side length (s): ", "PF", 15));
    
    double perimeter = n * s;
    printf("%s\nPerimeter of Regular Polygon is: %s%lf\n\n", BROWN, RESET, perimeter);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            regularPolygonPerimeter();
            break;
        case 1:
        case -1:
            regularPolygon();
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

// Function to calculate the apothem of a regular polygon
void regularPolygonApothem() {
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon>Apothem\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    int n = stoi(inputValidator("Enter the number of sides (n): ", "P", 15));
    double s = stof(inputValidator("Enter the side length (s): ", "PF", 15));
    
    double apothem = s / (2 * tan(3.14159 / n));
    printf("%s\nApothem of Regular Polygon is: %s%lf\n\n", BROWN, RESET, apothem);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            regularPolygonApothem();
            break;
        case 1:
        case -1:
            regularPolygon();
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

// Function to calculate the interior angle of a regular polygon
void regularPolygonInteriorAngle() {
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon>Interior Angle\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    int n = stoi(inputValidator("Enter the number of sides (n): ", "P", 15));
    
    double interiorAngle = (double)(n - 2) * 180 / n;
    printf("%s\nInterior Angle of Regular Polygon is: %s%lf degrees\n\n", BROWN, RESET, interiorAngle);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            regularPolygonInteriorAngle();
            break;
        case 1:
        case -1:
            regularPolygon();
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

// Function to calculate the exterior angle of a regular polygon
void regularPolygonExteriorAngle() {
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon>Exterior Angle\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    int n = atoi(inputValidator("Enter the number of sides (n): ", "P", 15));

    double exteriorAngle = 360.0 / n;
    printf("%s\nExterior Angle of Regular Polygon is: %s%lf degrees\n\n", BROWN, RESET, exteriorAngle);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            regularPolygonExteriorAngle();
            break;
        case 1:
        case -1:
            regularPolygon();
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

// Display options for regular polygon calculations
void regularPolygon() {
    const char *options[] = {"Area", "Perimeter", "Apothem", "Interior Angle", "Exterior Angle"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes>regular polygon\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 5);

    switch (selectedOption) {
        case 0:
            regularPolygonArea();
            break;
        case 1:
            regularPolygonPerimeter();
            break;
        case 2:
            regularPolygonApothem();
            break;
        case 3:
            regularPolygonInteriorAngle();
            break;
        case 4:
            regularPolygonExteriorAngle();
            break;
        case -1:
            shapes2D();
            break;
        default:
            break;
    }
}

// Function to calculate the surface area of a cube
void cubeSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cube>Surface Area\n\n%s", OLIVE, RESET);

    cubeIllustration();

    setPromptColor(PINK);
    double side = stof(inputValidator("Enter the side length of the cube: ", "PF", 15));

    double surfaceArea = 6 * side * side;
    printf("%s\nSurface Area of Cube is: %s%lf\n\n", BROWN, RESET, surfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            cubeSurfaceArea();
            break;
        case 1:
        case -1:
            cube();
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

// Function to calculate the volume of a cube
void cubeVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cube>Volume\n\n%s", OLIVE, RESET);

    cubeIllustration();

    setPromptColor(PINK);
    double side = stof(inputValidator("Enter the side length of the cube: ", "PF", 15));

    double volume = side * side * side;
    printf("%s\nVolume of Cube is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            cubeVolume();
            break;
        case 1:
        case -1:
            cube();
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

// Display options for cube calculations
void cube() {
    const char *options[] = {"Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cube\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            cubeSurfaceArea();
            break;
        case 1:
            cubeVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}

// Function to calculate the surface area of a sphere
void sphereSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>sphere>Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the sphere: ", "PF", 15));

    double surfaceArea = 4 * 3.14159 * radius * radius;
    printf("%s\nSurface Area of Sphere is: %s%lf\n\n", BROWN, RESET, surfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sphereSurfaceArea();
            break;
        case 1:
        case -1:
            sphere();
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

// Function to calculate the volume of a sphere
void sphereVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>sphere>Volume\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the sphere: ", "PF", 15));

    double volume = (4.0 / 3.0) * 3.14159 * pow(radius, 3);
    printf("%s\nVolume of Sphere is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            sphereVolume();
            break;
        case 1:
        case -1:
            sphere();
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

// Display options for sphere calculations
void sphere() {
    const char *options[] = {"Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>sphere\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption) {
        case 0:
            sphereSurfaceArea();
            break;
        case 1:
            sphereVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}

// Function to calculate the lateral surface area of a cylinder
void cylinderLateralSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cylinder>Lateral Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cylinder: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cylinder: ", "PF", 15));

    double lateralSurfaceArea = 2 * 3.14159 * radius * height;
    printf("%s\nLateral Surface Area of Cylinder is: %s%lf\n\n", BROWN, RESET, lateralSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            cylinderLateralSurfaceArea();
            break;
        case 1:
        case -1:
            cylinder();
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

// Function to calculate the total surface area of a cylinder
void cylinderTotalSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cylinder>Total Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cylinder: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cylinder: ", "PF", 15));

    double totalSurfaceArea = 2 * 3.14159 * radius * (radius + height);
    printf("%s\nTotal Surface Area of Cylinder is: %s%lf\n\n", BROWN, RESET, totalSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            cylinderTotalSurfaceArea();
            break;
        case 1:
        case -1:
            cylinder();
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

// Function to calculate the volume of a cylinder
void cylinderVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cylinder>Volume\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cylinder: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cylinder: ", "PF", 15));

    double volume = 3.14159 * radius * radius * height;
    printf("%s\nVolume of Cylinder is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            cylinderVolume();
            break;
        case 1:
        case -1:
            cylinder();
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

// Display options for cylinder calculations
void cylinder() {
    const char *options[] = {"Lateral Surface Area", "Total Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cylinder\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            cylinderLateralSurfaceArea();
            break;
        case 1:
            cylinderTotalSurfaceArea();
            break;
        case 2:
            cylinderVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}

// Function to calculate the lateral surface area of a cone
void coneLateralSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cone>Lateral Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cone: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cone: ", "PF", 15));
    double slantHeight = sqrt(pow(radius, 2) + pow(height, 2));

    double lateralSurfaceArea = 3.14159 * radius * slantHeight;
    printf("%s\nLateral Surface Area of Cone is: %s%lf\n\n", BROWN, RESET, lateralSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            coneLateralSurfaceArea();
            break;
        case 1:
        case -1:
            cone();
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

// Function to calculate the total surface area of a cone
void coneTotalSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cone>Total Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cone: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cone: ", "PF", 15));
    double slantHeight = sqrt(pow(radius, 2) + pow(height, 2));

    double totalSurfaceArea = 3.14159 * radius * (radius + slantHeight);
    printf("%s\nTotal Surface Area of Cone is: %s%lf\n\n", BROWN, RESET, totalSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            coneTotalSurfaceArea();
            break;
        case 1:
        case -1:
            cone();
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

// Function to calculate the volume of a cone
void coneVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cone>Volume\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double radius = stof(inputValidator("Enter the radius of the cone: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the cone: ", "PF", 15));

    double volume = (1.0 / 3.0) * 3.14159 * pow(radius, 2) * height;
    printf("%s\nVolume of Cone is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            coneVolume();
            break;
        case 1:
        case -1:
            cone();
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

// Display options for cone calculations
void cone() {
    const char *options[] = {"Lateral Surface Area", "Total Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>cone\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            coneLateralSurfaceArea();
            break;
        case 1:
            coneTotalSurfaceArea();
            break;
        case 2:
            coneVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}

// Function to calculate the lateral surface area of a square pyramid
void pyramidLateralSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>pyramid>Lateral Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double baseSide = stof(inputValidator("Enter the side length of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the pyramid: ", "PF", 15));
    double slantHeight = sqrt(pow(baseSide / 2, 2) + pow(height, 2));

    double lateralSurfaceArea = 4 * (0.5 * baseSide * slantHeight);
    printf("%s\nLateral Surface Area of Pyramid is: %s%lf\n\n", BROWN, RESET, lateralSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            pyramidLateralSurfaceArea();
            break;
        case 1:
        case -1:
            pyramid();
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

// Function to calculate the total surface area of a square pyramid
void pyramidTotalSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>pyramid>Total Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double baseSide = stof(inputValidator("Enter the side length of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the pyramid: ", "PF", 15));
    double slantHeight = sqrt(pow(baseSide / 2, 2) + pow(height, 2));

    double lateralSurfaceArea = 4 * (0.5 * baseSide * slantHeight);
    double baseArea = pow(baseSide, 2);
    double totalSurfaceArea = lateralSurfaceArea + baseArea;

    printf("%s\nTotal Surface Area of Pyramid is: %s%lf\n\n", BROWN, RESET, totalSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            pyramidTotalSurfaceArea();
            break;
        case 1:
        case -1:
            pyramid();
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

// Function to calculate the volume of a square pyramid
void pyramidVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>pyramid>Volume\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double baseSide = stof(inputValidator("Enter the side length of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the pyramid: ", "PF", 15));

    double baseArea = pow(baseSide, 2);
    double volume = (1.0 / 3.0) * baseArea * height;
    printf("%s\nVolume of Pyramid is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            pyramidVolume();
            break;
        case 1:
        case -1:
            pyramid();
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

// Display options for pyramid calculations
void pyramid() {
    const char *options[] = {"Lateral Surface Area", "Total Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>pyramid\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            pyramidLateralSurfaceArea();
            break;
        case 1:
            pyramidTotalSurfaceArea();
            break;
        case 2:
            pyramidVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}

// Function to calculate the lateral surface area of a prism
void prismLateralSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>prism>Lateral Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double basePerimeter = stof(inputValidator("Enter the perimeter of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the prism: ", "PF", 15));

    double lateralSurfaceArea = basePerimeter * height;
    printf("%s\nLateral Surface Area of Prism is: %s%lf\n\n", BROWN, RESET, lateralSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            prismLateralSurfaceArea();
            break;
        case 1:
        case -1:
            prism();
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

// Function to calculate the total surface area of a prism
void prismTotalSurfaceArea() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>prism>Total Surface Area\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double baseArea = stof(inputValidator("Enter the area of the base: ", "PF", 15));
    double basePerimeter = stof(inputValidator("Enter the perimeter of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the prism: ", "PF", 15));

    double lateralSurfaceArea = basePerimeter * height;
    double totalSurfaceArea = (2 * baseArea) + lateralSurfaceArea;

    printf("%s\nTotal Surface Area of Prism is: %s%lf\n\n", BROWN, RESET, totalSurfaceArea);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            prismTotalSurfaceArea();
            break;
        case 1:
        case -1:
            prism();
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

// Function to calculate the volume of a prism
void prismVolume() {
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>prism>Volume\n\n%s", OLIVE, RESET);

    setPromptColor(PINK);
    double baseArea = stof(inputValidator("Enter the area of the base: ", "PF", 15));
    double height = stof(inputValidator("Enter the height of the prism: ", "PF", 15));

    double volume = baseArea * height;
    printf("%s\nVolume of Prism is: %s%lf\n\n", BROWN, RESET, volume);

    // Handle the exit menu options
    switch (exitMenu()) {
        case 0:
            prismVolume();
            break;
        case 1:
        case -1:
            prism();
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

// Display options for prism calculations
void prism() {
    const char *options[] = {"Lateral Surface Area", "Total Surface Area", "Volume"};

    setHeadingColor(GRAY);
    setSelectionColor(BLUE);
    setNotSelectedColor(CYAN);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes>prism\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) {
        case 0:
            prismLateralSurfaceArea();
            break;
        case 1:
            prismTotalSurfaceArea();
            break;
        case 2:
            prismVolume();
            break;
        case -1:
            shapes3D();
            break;
        default:
            break;
    }
}
