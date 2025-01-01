#include <stdlib.h>
#include <math.h>
#include "vectors.h"
#include "matrixOperations.h"
#include "list.h"
#include "inputValidator.h"
#include "menu.h"
#include "windows.h"

// Global Variables
Vector **vecArray = NULL;

// Public Functions
Vector *vectorAlloc(int dimension);
void vectorDealloc(Vector *vec);
Vector *vectorAddition(Vector *vecA, Vector *vecB);
Vector *vectorSubtraction(Vector *vecA, Vector *vecB);
double vectorDotProduct(Vector *vecA, Vector *vecB);
Vector *vectorCrossProduct(Vector *vecA, Vector *vecB);
double vectorModulus(Vector *vecA);

int vectorArithmetic();
int vectorOperation();

int vectorMenu();
int vectorExitMenu();
int vectorNotDefinedMenu();
int vectorDefine();
Vector *defineVector(int n);
// Private Functions
// None as of now!

Vector *vectorAlloc(int dimension)
{
    double *vec_arr = (double *)calloc(dimension, sizeof(double));
    Vector *vec = (Vector *)calloc(1, sizeof(Vector));
    vec->dimension = dimension;
    vec->vec = vec_arr;
    return vec;
}

void vectorDealloc(Vector *vec)
{
    free(vec->vec);
    free(vec);
}

void displayVector(Vector *vec)
{
    if (vec == NULL)
        return;
    for (int i = 0; i < vec->dimension; i++)
    {
        printf("[");
        printf(" %3.0f ", vec->vec[i]);
        printf("]\n");
    }
    printf("\n");
}

void displayVectorFloat(Vector *vec)
{
    if (vec == NULL)
        return;
    for (int i = 0; i < vec->dimension; i++)
    {
        printf("[");
        printf(" %3.2f ", vec->vec[i]);
        printf("]\n");
    }
    printf("\n");
}

Vector *vectorAddition(Vector *vecA, Vector *vecB)
{
    Vector *vecBackup;
    Vector *vec = vectorAlloc(3);
    if (vecA->dimension != vecB->dimension)
    {
        vecBackup = vectorAlloc(3);
        if (vecA->dimension < vecB->dimension)
        {
            vecBackup->vec[0] = vecA->vec[0];
            vecBackup->vec[1] = vecA->vec[1];
            for (int i = 0; i < 3; i++)
            {
                vec->vec[i] = vecBackup->vec[i] + vecB->vec[i];
            }
        }
        else
        {
            vecBackup->vec[0] = vecB->vec[0];
            vecBackup->vec[1] = vecB->vec[1];
            for (int i = 0; i < 3; i++)
            {
                vec->vec[i] = vecA->vec[i] + vecBackup->vec[i];
            }
        }
        vectorDealloc(vecBackup);
    }
    else
    {
        for (int i = 0; i < vecA->dimension; i++)
        {
            vec->vec[i] = vecA->vec[i] + vecB->vec[i];
        }
    }
    return vec;
}

Vector *vectorSubtraction(Vector *vecA, Vector *vecB)
{
    Vector *vecBackup;
    Vector *vec = vectorAlloc(3);
    if (vecA->dimension != vecB->dimension)
    {
        vecBackup = vectorAlloc(3);
        if (vecA->dimension < vecB->dimension)
        {
            vecBackup->vec[0] = vecA->vec[0];
            vecBackup->vec[1] = vecA->vec[1];
            for (int i = 0; i < 3; i++)
            {
                vec->vec[i] = vecBackup->vec[i] - vecB->vec[i];
            }
        }
        else
        {
            vecBackup->vec[0] = vecB->vec[0];
            vecBackup->vec[1] = vecB->vec[1];
            for (int i = 0; i < 3; i++)
            {
                vec->vec[i] = vecA->vec[i] - vecBackup->vec[i];
            }
        }
        vectorDealloc(vecBackup);
    }
    else
    {
        for (int i = 0; i < vecA->dimension; i++)
        {
            vec->vec[i] = vecA->vec[i] - vecB->vec[i];
        }
    }
    return vec;
}

double vectorModulus(Vector *vecA)
{
    double ans = 0;
    for (int i = 0; i < vecA->dimension; i++)
    {
        ans += pow(vecA->vec[i], (double)2);
    }
    ans = sqrt(ans);
    return ans;
}

double vectorDotProduct(Vector *vecA, Vector *vecB)
{
    Vector *vecBackup;
    double ans = 0;
    if (vecA->dimension != vecB->dimension)
    {
        vecBackup = vectorAlloc(3);
        if (vecA->dimension < vecB->dimension)
        {
            vecBackup->vec[0] = vecA->vec[0];
            vecBackup->vec[1] = vecA->vec[1];
            for (int i = 0; i < 3; i++)
            {
                ans += vecBackup->vec[i] * vecB->vec[i];
            }
        }
        else
        {
            vecBackup->vec[0] = vecB->vec[0];
            vecBackup->vec[1] = vecB->vec[1];
            for (int i = 0; i < 3; i++)
            {
                ans += vecA->vec[i] * vecBackup->vec[i];
            }
        }
        vectorDealloc(vecBackup);
    }
    else
    {
        for (int i = 0; i < vecA->dimension; i++)
        {
            ans += vecA->vec[i] * vecB->vec[i];
        }
    }
    return ans;
}

Vector *vectorCrossProduct(Vector *vecA, Vector *vecB)
{
    Vector *vec = vectorAlloc(3);
    Matrix *mi = matrixAlloc(2, 2);
    Matrix *mj = matrixAlloc(2, 2);
    Matrix *mk = matrixAlloc(2, 2);
    double ai, bi;
    double aj, bj;
    double ak, bk;

    if (vecA->dimension == 2 && vecB->dimension == 2)
    {
        ai = vecA->vec[0], bi = vecB->vec[0];
        aj = vecA->vec[1], bj = vecB->vec[1];
        ak = 0, bk = 0;
    }
    else if (vecA->dimension == 2)
    {
        ai = vecA->vec[0], bi = vecB->vec[0];
        aj = vecA->vec[1], bj = vecB->vec[1];
        ak = 0, bk = vecB->vec[2];
    }
    else if (vecB->dimension == 2)
    {
        ai = vecA->vec[0], bi = vecB->vec[0];
        aj = vecA->vec[1], bj = vecB->vec[1];
        ak = vecA->vec[2], bk = 0;
    }
    else
    {
        ai = vecA->vec[0], bi = vecB->vec[0];
        aj = vecA->vec[1], bj = vecB->vec[1];
        ak = vecA->vec[2], bk = vecB->vec[2];
    }

    mi->mat[0][0] = aj;
    mi->mat[0][1] = ak;
    mi->mat[1][0] = bj;
    mi->mat[1][1] = bk;

    mj->mat[0][0] = ai;
    mj->mat[0][1] = ak;
    mj->mat[1][0] = bi;
    mj->mat[1][1] = bk;

    mk->mat[0][0] = ai;
    mk->mat[0][1] = aj;
    mk->mat[1][0] = bi;
    mk->mat[1][1] = bj;

    double i = matrixDeterminant(mi);
    double j = matrixDeterminant(mj);
    double k = matrixDeterminant(mk);

    vec->vec[0] = i;
    vec->vec[1] = (-1) * j;
    vec->vec[2] = k;

    matrixDealloc(mi);
    matrixDealloc(mj);
    matrixDealloc(mk);

    return vec;
}

Vector *vectorScalarMultiplication(Vector *vecA, int n)
{
    Vector *vec = vectorAlloc(vecA->dimension);
    for (int i = 0; i < vecA->dimension; i++)
    {
        vec->vec[i] = vecA->vec[i] * n;
    }
    return vec;
}

Vector *vectorUnitVector(Vector *vecA)
{
    double mod = vectorModulus(vecA);
    return vectorScalarMultiplication(vecA, 1 / mod);
}

int vectorOp1input(int n)
{
    char *temp;
    const char *options[] = {"Unit Vector", "Scalar Multiplication", "Vector Modulus"};
    const char *vectors[] = {"Vector A", "Vector B", "Vector C", "Vector D", "Vector Answer"};
    int avail[5] = {-1, -1, -1, -1, -1};
    int count = 0;
    Vector *result = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (vecArray[i] != NULL)
        {
            avail[count] = i;
            count++;
        }
    }

    count = 1;
    clearScreen(1);

    char menuLine[64] = "mainMenu>Vector>";
    strcat(menuLine, options[n]);
    printf("%s%s\n%s", OLIVE, menuLine, RESET);
    printf("\n%sChoose Corresponsing Vector Number\n%s", OLIVE, RESET);
    count = 1;
    for (int i = 0; i < 5; i++)
    {
        if (avail[i] != -1)
        {
            printf("%s%d. %s\n%s", OLIVE, count, vectors[avail[i]], RESET);
            count++;
        }
    }

    int vec1 = 6; // To make sure a valid matrix is chosen
    double scalar;

    int ok = 1;
    while (vec1 >= count || vec1 < 1)
    {
        (ok) ? setPromptColor(YELLOW) : setPromptColor(RED);
        vec1 = stoi(inputValidator("Choose Vector 1: ", "I", 1));
        ok = 0;
        clearPreviousLine();
    }
    clearPreviousLine();
    printf("%sVector 1: %s\n%s", GREEN, vectors[avail[vec1 - 1]], RESET);
    if (n == 1)
    {
        setPromptColor(YELLOW);
        scalar = stof(inputValidator("Enter Scalar: ", "F", 16));
        clearPreviousLine();
        printf("%sScalar: %lf\n%s", GREEN, scalar, RESET);
    }

    double mod;
    int is_mod = 0;
    switch (n)
    {
    case 0:
        result = vectorUnitVector(vecArray[avail[vec1 - 1]]);
        break;
    case 1:
        result = vectorScalarMultiplication(vecArray[avail[vec1 - 1]], scalar);
        break;
    case 2:
        mod = vectorModulus(vecArray[avail[vec1 - 1]]);
        is_mod = 1;
        break;
    }

    if (result != NULL)
    {
        if (vecArray[4] != NULL)
        {
            vectorDealloc(vecArray[4]);
        }
        vecArray[4] = result;
        displayVectorFloat(result);
    }
    else if (is_mod)
    {
        printf("\n%sModulus of %s = %lf\n%s", OLIVE, vectors[avail[vec1 - 1]], mod, RESET);
    }
    else
    {
        // In case of invalid vector operations
        printf("\n%sAn error occured!\nDid you choose vector with correct dimensions?\n%s", OLIVE, RESET);
    }

    // Handle the exit menu options
    switch (vectorExitMenu())
    {
    case 0:
    case -1:
        vectorOperation();
        break;
    case 1:
        vectorMenu();
        break;
    case 2:
        mainMenu();
        break;
    case 3:
        exit(1);
        break;
    }
}

int vectorOp2input(int n)
{

    const char *options[] = {"Vector Addition", "Vector Subtraction", "Vector Cross Product", "Vector Dot Product"};
    const char *vectors[] = {"Vector A", "Vector B", "Vector C", "Vector D", "Vector Answer"};
    int avail[5] = {-1, -1, -1, -1, -1};
    int count = 0;
    Vector *result = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (vecArray[i] != NULL)
        {
            // displayMatrix(matArray[i]);
            avail[count] = i;
            count++;
        }
    }

    count = 1;
    clearScreen(1);

    char menuLine[64] = "mainMenu>Vector>";
    strcat(menuLine, options[n]);
    printf("%s%s\n%s", OLIVE, menuLine, RESET);
    printf("\n%sChoose Corresponsing Vector Number\n%s", OLIVE, RESET);
    count = 1;
    for (int i = 0; i < 5; i++)
    {
        if (avail[i] != -1)
        {
            printf("%s%d. %s\n%s", OLIVE, count, vectors[avail[i]], RESET);
            count++;
        }
    }

    int vec1 = 6;
    int vec2 = 6;
    int ok = 1;
    while (vec1 >= count || vec1 < 1)
    {
        (ok) ? setPromptColor(YELLOW) : setPromptColor(RED);
        vec1 = stoi(inputValidator("Choose Vector 1: ", "I", 1));
        ok = 0;
        clearPreviousLine();
    }
    clearLine();
    printf("%sVector 1: %s\n%s", GREEN, vectors[avail[vec1 - 1]], RESET);
    ok = 1;
    while (vec2 >= count || vec2 < 1)
    {
        (ok) ? setPromptColor(YELLOW) : setPromptColor(RED);
        vec2 = stoi(inputValidator("Choose Vector 2: ", "I", 1));
        ok = 0;
        clearPreviousLine();
    }
    clearLine();
    printf("%sVector 2: %s\n%s", GREEN, vectors[avail[vec2 - 1]], RESET);

    double dp;
    int is_dp = 0;

    switch (n)
    {
    case 0:
        result = vectorAddition(vecArray[avail[vec1 - 1]], vecArray[avail[vec2 - 1]]);
        break;
    case 1:
        result = vectorSubtraction(vecArray[avail[vec1 - 1]], vecArray[avail[vec2 - 1]]);
        break;
    case 2:
        result = vectorCrossProduct(vecArray[avail[vec1 - 1]], vecArray[avail[vec2 - 1]]);
        break;
    case 3:
        dp = vectorDotProduct(vecArray[avail[vec1 - 1]], vecArray[avail[vec2 - 1]]);
        is_dp = 1;
        break;
    }

    if (result != NULL)
    {
        if (vecArray[4] != NULL)
        {
            vectorDealloc(vecArray[4]);
        }
        vecArray[4] = result;
        displayVectorFloat(result);
    }
    else if (is_dp)
    {
        printf("\n%sDot Product of %s and %s = %lf\n%s", OLIVE, vectors[avail[vec1 - 1]], vectors[avail[vec2 - 1]], dp, RESET);
    }
    else
    {
        // In case of invalid matrix operations
        printf("\n%sAn error occured!\nDid you choose matrices with correct dimensions?\n%s", OLIVE, RESET);
    }

    // Handle the exit menu options
    switch (vectorExitMenu())
    {
    case 0:
    case -1:
        vectorArithmetic();
        break;
    case 1:
        vectorMenu();
        break;
    case 2:
        mainMenu();
        break;
    case 3:
        exit(1);
        break;
    }
}

int vectorArithmetic()
{

    const char *options[] = {"Vector Addition", "Vector Subtraction", "Vector Cross Product", "Vector Dot Product"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Vector>Vector Arithmetic\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 4);

    switch (selectedOption)
    {
    case -1:
        vectorMenu();
        break;
    default:
        vectorOp2input(selectedOption);
        break;
    }
}

int vectorOperation()
{
    const char *options[] = {"Unit Vector", "Scalar Multiplication", "Vector Modulus"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Vector>Vector Operation\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case -1:
        vectorMenu();
        break;
    default:
        vectorOp1input(selectedOption);
        break;
    }
}

int vectorNotDefined()
{
    if (vecArray == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Vector *defineVector(int n)
{
    const char *options[] = {"Vector A", "Vector B", "Vector C", "Vector D"};
    char prompt[64] = "mainMenu>Vector>Vector Define";
    strcat(prompt, options[n]);
    clearScreen(1);
    printf("%s%s\n%s", OLIVE, prompt, RESET);

    setPromptColor(YELLOW);
    int dim = -1;
    while (dim < 2 || dim > 3)
    {
        dim = stoi(inputValidator("Enter dimension: ", "I", 1));
    }
    Vector *vec = vectorAlloc(dim);
    double value = 0;
    clearScreen(1);
    for (int i = 0; i < dim; i++)
    {
        clearScreen(1);
        printf("%s%s\n%s", OLIVE, prompt, RESET);
        displayVectorFloat(vec);
        setPromptColor(YELLOW);
        value = stof(inputValidator("Enter Value: ", "F", 32));
        vec->vec[i] = value;
    }

    // Display The Updated Vector
    clearScreen(1);
    printf("%smainMenu>Vector>Vector Define\n%s", OLIVE, RESET);
    displayVectorFloat(vec);
    setPromptColor(YELLOW);

    int i = stoi(inputValidator("Press enter key to continue", "I", 0));
    return vec;
}

int vectorDefine()
{
    const char *options[] = {"Vector A", "Vector B", "Vector C", "Vector D"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Vector>Vector Define\n%s", OLIVE, RESET);
    printf("%sChoose a Vector\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 4);

    switch (selectedOption)
    {
    case -1:
        vectorMenu();
        break;
    default:
        // Allocate memory for Vectors Array
        if (vecArray == NULL)
        {
            vecArray = (Vector **)calloc(5, sizeof(Vector *));
        }
        // Free Pre-Allocated memory of previous definition of Vector
        if (vecArray[selectedOption] != NULL)
        {
            free(vecArray[selectedOption]);
            vecArray[selectedOption] = NULL;
        }
        vecArray[selectedOption] = defineVector(selectedOption);
        break;
    }

    vectorMenu();
}

int vectorExitMenu()
{
    const char *options[] = {"Vector Previous Menu", "Vector Main Menu", "Main Menu", "Exit"};

    int selectedOption = displayList(options, 4);
    return selectedOption;
}

int vectorNotDefinedMenu()
{
    const char *options[] = {"Define Vector", "Vector Main Menu", "Main Menu", "Exit"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Vector\n%s", OLIVE, RESET);
    printf("%sNo Vector is Defined. Please Define a Vector First!\n%s", OLIVE, RESET);

    int selectedOption = displayList(options, 4);
    switch (selectedOption)
    {
    case 0:
        vectorDefine();
        break;
    case 1:
    case -1:
        vectorMenu();
        break;
    case 2:
        mainMenu();
        break;
    case 3:
        exit(1);
        break;
    }
}

int vectorMenu()
{
    const char *options[] = {"Define Vector", "Vector Arithmetic", "Vector Operation"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Vector\n%s", OLIVE, RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case 0:
        vectorDefine();
        break;
    case 1:
        if (vectorNotDefined())
        {
            vectorNotDefinedMenu();
        }
        else
        {
            vectorArithmetic();
        }
        break;
    case 2:
        if (vectorNotDefined())
        {
            vectorNotDefinedMenu();
        }
        else
        {
            vectorOperation();
        }
        break;
    case -1:
        mainMenu();
        break;
    }
}
