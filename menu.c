#include "list.h"
#include "simpleCalculator.h"
#include "converters.h"
#include "shapes.h"
#include "menu.h"
#include "baseN.h"
#include "ageManipulation.h"
#include "numberManipulation.h"
#include "matrixOperations.h"
#include "vectors.h"

void mainMenu(){
    
    const char *options[] = { "Simple Calculations", "Number Manipulation","Shapes", "Age Manipulation", "Converters","Base-N","Matrix","Vectors"};

    setHeadingColor(GRAY);
    setSelectionColor(PINK);
    setNotSelectedColor(PURPLE);
    clearScreen(1);

    printf("%smainMenu\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 8);  

    switch (selectedOption)
    {
    case 0:
        simpleCalculator();
        break;
    case 1:
        numberManipulation();
        break;
    case 2:
        shapes();
        break;
    case 3:
        ageManipulation();
        break;
    case 4:
        converters();
        break;
    case 5:
        baseN();
        break;
    case 6:
        matrixMenu();
        break;
    case 7:
        vectorMenu();
        break;
    default:
        break;
    }
}

int simpleCalculator() {
    const char *options[] ={"Additon","Subtraction","Multiplication","Division","Reminder","N-th Root","Power"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>simpleCalculator\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 7);

    switch (selectedOption)
    {
    case 0:
        sum();
        break;
    case 1:
        subtract();
        break;
    case 2:
        multiply();
        break;
    case 3:
        divide();
        break;
    case 4:
        reminder();
        break;
    case 5:
        nthRoot();
        break;
    case 6:
        power();
        break;
    case -1:
        mainMenu();
        break;

    default:
        break;
    }
    

    return 0;
}

int numberManipulation() {
    
    const char *options[] ={"Number Classification","Numeric Operations","Digits Operations","Statistics","Sequences"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 5);

    switch (selectedOption)
    {
    case 0:
        numberClassification();
        break;
    case 1:
        numericOperations();
        break;
    case 2:
        digitOperations();
        break;
    case 3:
        statistics();
        break;
    case 4:
        Sequences();
        break;
    case -1:
        mainMenu();
        break;

    default:
        break;
    }
}

int numberClassification() {
    
    const char *options[] = {"Even/odd","Prime/Composite","Perfect","Armstrong/narcissistic","Kaprekar","Palindrome","Coprime","Niven/Harshad","deficient","abundant","spy"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Number Classification\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 11);

    switch (selectedOption)
    {
    case 0:
        evenOdd();
        break;
    case 1:
        primeComposite();
        break;
    case 2:
        perfect();
        break;
    case 3:
        Armstrong();
        break;
    case 4:
        kaprekar();
        break;
    case 5:
        palindrome();
        break;
    case 6:
        coprime();
        break;
    case 7:
        niven();
        break;
    case 8:
        deficient();
        break;
    case 9:
        abundant();
        break;
    case 10:
        spy();
        break;
    case -1:
        numberManipulation();
        break;
    }
}

int numericOperations() {
    
    const char *options[] = {"SUM of n numbers","Factorial","GCD","LCM"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Numeric Operations\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 4);

    switch (selectedOption) 
    {
    case 0:
        SumOfNumbers();
        break;
    case 1:
        Factorial();
        break;
    case 2:
        gcdDataEntry();
        break;
    case 3:
        lcm();
        break;
    case -1:
        numberManipulation();
        break;
    }
}

int digitOperations() {
    const char *options[] = {"Digits Sum","Digits Product","Digits Frequency","Digits Average","Digits Reverse","Digits Sort"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>Digits Operations\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 6);

    switch (selectedOption) 
    {
    case 0:
        digitSum();
        break;
    case 1:
        digitProduct(); 
        break;
    case 2:
        digitFrequency();   
        break;
    case 3:
        digitAverage();
        break;
    case 4:
        digitReverse();
        break;
    case 5:
        digitSort();
        break;
    case -1:
        numberManipulation();
        break;
    }
}

int statistics() {
    const char *options[] = {"Mean","Median","Mode"};
    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>statistics\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption) 
    {
    case 0:
        Mean();
        break;
    case 1:
        Median();
        break;
    case 2:
        Mode();
        break;
    case -1:
        numberManipulation();
        break;
    }
}

int Sequences() {
    const char *options[] = {"Fibonacci","Triangular","Squares","Cubes","Arithemetic","Geometric","Prism"};
    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Number Manipulation>sequences\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 6);

    switch (selectedOption) 
    {
    case 0:
        FibonacciSequence();
        break;
    case 1:
        TriangularSequence();
        break;
    case 2:
        SquaresSequence();
        break;
    case 3:
        CubesSequence();
        break;
    case 4:
        ArithmeticSequence();
        break;
    case 5:
        GeometricSequence();
        break;
    case -1:
        numberManipulation();
        break;
    }
}

int converters() {
    const char *options[] = {"Length","Weight/Mass","Temperature","Time","Angle","Area","Volume","Digital Storage","Speed","Currency"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Converters\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 10);

    switch (selectedOption)
    {
    case 0:
        length();
        break;
    case 1:
        weight();
        break;
    case 2:
        temperature();
        break;
    case 3:
        time();
        break;
    case 4:
        angle();
        break;
    case 5:
        area();
        break;
    case 6:
        volume();
        break;
    case 7:
        digitalStorage();
        break;
    case 8:
        speed();
        break;
    case 9:
        currencyConverter();
    case -1:
        mainMenu();
        break;    
    default:
        break;    
    }
}

int shapes2D() {
     
    const char *options[] = {"Circle","Square","Rectangle","Triangle","Trapezoid","Parallelogram","Rhombus","Kite","Dart","Ellipse","Sector of a Circle","Segment of a Circle","Annulus (Ring)","Regular Polygon"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>shapes>2d shapes\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 14);

    switch (selectedOption)
    {
    case 0:
        circle();
        break;
    case 1:
        square();
        break;
    case 2:
        rectangle();
        break;
    case 3:
        triangle();
        break;
    case 4:
        trapezoid();
        break;
    case 5:
        parallelogram();
        break;
    case 6:
        rhombus();
        break;
    case 7:
        kite();
        break;
    case 8:
        dart();
    case 9:
        ellipse();
        break;
    case 10:
        sectorOfCircle();
        break;
    case 11:
        segmentOfCircle();
        break;
    case 12:
        ring();
    case 13:
        regularPolygon();
        break;
    case -1:
        shapes();
        break;
    }
}

int shapes3D() {

    const char *options[] = {"Cube","Sphere","Cylinder","Cone","Pyramid","Prism"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>shapes>3d shapes\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 6);

    switch (selectedOption)
    {
    case 0:
        cube();
        break;
    case 1:
        sphere();
        break;
    case 2:
        cylinder();
        break;
    case 3:
        cone();
        break;
    case 4:
        pyramid();
        break;
    case 5:
        prism();
        break;
    case -1:
        shapes();
        break;
    }
}

int shapes() {
    
    const char *options[] = {"2d shapes","3d shapes"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>shapes\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 2);

    switch (selectedOption)
    {
    case 0:
        shapes2D();
        break;
    case 1:
        shapes3D();
        break;
    case -1:
        mainMenu();
        break;
    }
}

int ageManipulation() {
    const char *options[] ={"Exact age","Age in years","Age in months","Age in week" ,"Age in days"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Age Manipulation\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 5);

    switch (selectedOption)
    {
    case 0:
        displayExactAge();
        break;
    case 1:
        ageInYears();
        break;
    case 2:
        ageInMonths();
        break;
    case 3:
        ageInWeeks();
        break;
    case 4:
        ageInDays();
        break;
    case -1:
        mainMenu();
        break;
    }
}
