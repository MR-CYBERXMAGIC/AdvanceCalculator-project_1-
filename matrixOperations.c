#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matrixOperations.h"
#include "list.h"
#include "inputValidator.h"
#include "menu.h"
#include "windows.h"

// Public Functions
void matrixDealloc(Matrix *mat);
void displayMatrix(Matrix *mat);
void displayMatrixFloat(Matrix *mat);
void matrixMinor(double **mat, double **minor, int row, int col, int m, int n);
double matrixDeterminant(Matrix *matrix);
int matrixMenu();
int matrixExitMenu();
int matrixOperation();
int matrixArithmetic();
Matrix *matrixAlloc(int rows, int cols);
Matrix *matrixTranspose(Matrix *mat);
Matrix *matrixAddition(Matrix *mat1, Matrix *mat2);
Matrix *matrixSubtraction(Matrix *mat1, Matrix *mat2);
Matrix *matrixMultiplication(Matrix *mat1, Matrix *mat2);
Matrix *matrixAdjoint(Matrix *mat);
Matrix *matrixInverse(Matrix *mat);

// Global Array Necessary For Persistant Storage Between Other Files
Matrix **matArray = NULL;

Matrix *matrixAlloc(int rows, int cols) {
    Matrix *matrix = (Matrix *)calloc(1, sizeof(Matrix)); 
    double **mat = (double **)calloc(rows, sizeof(double *));
    for (int i=0; i<rows; i++) {
        mat[i] = (double *)calloc(cols, sizeof(double));
    }
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->mat = mat;
    return matrix;
}

void matrixDealloc(Matrix *mat) {
    for (int i=0; i<mat->rows; i++) {
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}

void displayMatrix(Matrix *mat)
{
    if (mat == NULL) return;
    for (int i = 0; i < mat->rows; i++)
    {
        printf("[");
        for (int j = 0; j < mat->cols; j++)
        {
            printf("%3.0f ", mat->mat[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

void displayMatrixFloat(Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        printf("[");
        for (int j = 0; j < mat->cols; j++)
        {
            printf(" %-3.2f ", mat->mat[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

Matrix *matrixTranspose(Matrix *mat)
{
    // Reallocate memory for result array as a row x col matrix
    Matrix *result = matrixAlloc(mat->cols, mat->rows);

    // Transpose the matrix
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            result->mat[j][i] = mat->mat[i][j];
        }
    }

    // Update result dimensions
    return result;
}

Matrix *matrixAddition(Matrix *mat1, Matrix *mat2)
{
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols)
        return NULL;

    int rows = mat1->rows;
    int cols = mat1->cols;
    Matrix *result = matrixAlloc(mat1->rows, mat1->cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result->mat[i][j] = mat1->mat[i][j] + mat2->mat[i][j];
        }
    }

    return result;
}

Matrix *matrixSubtraction(Matrix *mat1, Matrix *mat2)
{
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols)
        return NULL;

    int rows = mat1->rows;
    int cols = mat1->cols;
    Matrix *result = matrixAlloc(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result->mat[i][j] = mat1->mat[i][j] - mat2->mat[i][j];
        }
    }

    return result;
}

Matrix *matrixMultiplication(Matrix *mat1, Matrix *mat2)
{
    if (mat1->cols != mat2->rows)
        return NULL;

    int rows = mat1->rows;
    int cols = mat2->cols;
    Matrix *result = matrixAlloc(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double sum = 0;
            for (int k = 0; k < mat1->cols; k++)
            {
                sum += mat1->mat[i][k] * mat2->mat[k][j];
            }
            result->mat[i][j] = sum;
        }
    }

    return result;
}

void matrixMinor(double **mat, double **minor, int row, int col, int m, int n)
{
    int rowm = 0, colm = 0;

    for (int i = 0; i < row; i++)
    {
        if (i != m)
        {
            colm = 0; // Reset column index for each new row
            for (int j = 0; j < col; j++)
            {
                if (j != n)
                {
                    minor[rowm][colm] = mat[i][j];
                    colm++;
                }
            }
            rowm++;
        }
    }
}

double matrixDeterminant(Matrix *matrix)
{
    if (matrix->rows != matrix->cols) // Not a square matrix
        return 0;

    int n = matrix->rows;
    double det = 0;

    // Base case for 1x1 matrix
    if (n == 1)
        return matrix->mat[0][0];

    // Allocate memory for the minor matrix
    Matrix *minor = matrixAlloc(n-1, n-1);
    minor->rows = n-1;
    minor->cols = n-1;

    for (int i = 0; i < n; i++)
    {
        matrixMinor(matrix->mat, minor->mat, n, n, 0, i);
        double sign = (i % 2 == 0) ? 1 : -1;
        det += sign * matrix->mat[0][i] * matrixDeterminant(minor);
    }

    // Free the memory allocated for the minor matrix
    matrixDealloc(minor);
    return det;
}

Matrix *matrixAdjoint(Matrix *mat)
{
    if (mat->rows != mat->cols) // If not a square matrix
        return NULL;

    int n = mat->rows;
    Matrix *result;

    // Allocate memory for adjoint resultay as a 3x3 matrix
    Matrix *adjoint = matrixAlloc(mat->cols, mat->rows);

    // Allocate memory for the minor matrix
    Matrix *minor = matrixAlloc(n-1, n-1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrixMinor(mat->mat, minor->mat, mat->rows, mat->cols, i, j);
            adjoint->mat[i][j] = pow((-1), i + j) * matrixDeterminant(minor);
        }
    }
    result = matrixTranspose(adjoint);
    matrixDealloc(minor);
    matrixDealloc(adjoint);
    return result;
}

Matrix *matrixInverse(Matrix *mat)
{

    if (mat->rows != mat->cols) // If not a square matrix
        return NULL;

    int n = mat->rows;

    Matrix *result = matrixAdjoint(mat);
    double det = matrixDeterminant(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result->mat[i][j] *= (1.0 / det);
        }
    }

    return result;
}

int matrixOp1input(int n) {
    char *temp;
    const char *options[] = {"Matrix Transpose","Matrix Inverse","Matrix Determinant"};
    const char *matrices[] = {"Matrix A", "Matrix B", "Matrix C", "Matrix D", "Matrix Answer"};
    int avail[5] = {-1, -1, -1, -1, -1};
    int count = 0;
    Matrix *result = NULL;

    for (int i=0; i<5; i++) {
        if (matArray[i] != NULL) {
            // displayMatrix(matArray[i]);
            avail[count] = i;
            count++;
        }
    }
    
    count = 1;
    clearScreen(1);

    char menuLine[64] = "mainMenu>Matrix>";
    strcat(menuLine, options[n]);
    printf("%s%s\n%s",OLIVE, menuLine, RESET);
    printf("\n%sChoose Corresponsing Matrix Number\n%s",OLIVE,RESET);
    count = 1;
    for (int i=0; i<5; i++) {
        if (avail[i] != -1) {
            printf("%s%d. %s\n%s",OLIVE, count, matrices[avail[i]], RESET);
            count++;
        }
    }

    int ok=1,mat1 = 6; // To make sure a valid matrix is chosen
    while (mat1 >= count || mat1 < 1) {
        
        (ok)?setPromptColor(YELLOW):setPromptColor(RED);
        mat1 = stoi(inputValidator("Choose Matrix 1: ", "I", 1));
        ok=0;
        clearPreviousLine();

    }
    clearPreviousLine();
    printf("%sMatrix 1: %s\n%s", GREEN, matrices[avail[mat1-1]], RESET);

    double determinant = -1.0;
    switch (n) {
        case 0:
            result = matrixTranspose(matArray[avail[mat1-1]]);
            break;
        case 1:
            result = matrixInverse(matArray[avail[mat1-1]]);
            break;
        case 2:
            determinant = matrixDeterminant(matArray[avail[mat1-1]]);
            break;
    }

    if (result != NULL) {
        if (matArray[4] != NULL) {
            matrixDealloc(matArray[4]);
        }
        matArray[4] = result;
        displayMatrixFloat(result);
    } else if (determinant != -1.0) {
        printf("\n%sDeterminant of %s = %lf\n%s",OLIVE, matrices[avail[mat1-1]], determinant, RESET);
    } else {
        // In case of invalid matrix operations
        printf("\n%sAn error occured!\nDid you choose matrix with correct dimensions?\n%s",OLIVE,RESET);
    }

    // Handle the exit menu options
    switch (matrixExitMenu()) {
        case 0: case -1:
            matrixOperation();
            break;
        case 1:
            matrixMenu();
            break;
        case 2:
            exit(1);
            break;
    }
}

int matrixOp2input(int n) {
    char *temp;
    const char *options[] = {"Matrix Addition","Matrix Subtraction","Matrix Multiplication"};
    const char *matrices[] = {"Matrix A", "Matrix B", "Matrix C", "Matrix D", "Matrix Answer"};
    int avail[5] = {-1, -1, -1, -1, -1};
    int count = 0;
    Matrix *result = NULL;

    for (int i=0; i<5; i++) {
        if (matArray[i] != NULL) {
            // displayMatrix(matArray[i]);
            avail[count] = i;
            count++;
        }
    }
    
    count = 1;
    clearScreen(1);

    char menuLine[64] = "mainMenu>Matrix>";
    strcat(menuLine, options[n]);
    printf("%s%s\n%s",OLIVE, menuLine, RESET);
    printf("\n%sChoose Corresponsing Matrix Number\n%s",OLIVE,RESET);
    count = 1;
    for (int i=0; i<5; i++) {
        if (avail[i] != -1) {
            printf("%s%d. %s\n%s",OLIVE, count, matrices[avail[i]], RESET);
            count++;
        }
    }

    int mat1 = 6;
    int mat2 = 6;
    
    int ok=1;
    while (mat1 >= count || mat1 < 1) {
        
        (ok)?setPromptColor(YELLOW):setPromptColor(RED);
        mat1 = stoi(inputValidator("Choose Matrix 1: ", "I", 1));
        ok=0;
        clearPreviousLine();
    }
    clearPreviousLine();
    printf("%sMatrix 1: %s%s\n", GREEN, matrices[avail[mat1-1]], RESET);
    
    ok=1;
    while (mat2 >= count || mat2 < 1) {
        
        (ok)?setPromptColor(YELLOW):setPromptColor(RED);
        mat2 = stoi(inputValidator("Choose Matrix 2: ", "I", 1));
        ok=0;
        clearPreviousLine();

    }
    clearPreviousLine();
    printf("%sMatrix 2: %s\n%s", GREEN, matrices[avail[mat2-1]], RESET);

    switch (n) {
        case 0:
            result = matrixAddition(matArray[avail[mat1-1]], matArray[avail[mat2-1]]);
            break;
        case 1:
            result = matrixSubtraction(matArray[avail[mat1-1]], matArray[avail[mat2-1]]);
            break;
        case 2:
            result = matrixMultiplication(matArray[avail[mat1-1]], matArray[avail[mat2-1]]);
            break;
    }

    if (result != NULL && result != 0) {
        if (matArray[4] != NULL) {
            matrixDealloc(matArray[4]);
        }
        matArray[4] = result;
        displayMatrixFloat(result);
    } else {
        // In case of invalid matrix operations
        printf("\n%sAn error occured!\nDid you choose matrices with correct dimensions?\n%s",OLIVE,RESET);
    }

    // Handle the exit menu options
    switch (matrixExitMenu()) {
        case 0: case -1:
            matrixArithmetic();
            break;
        case 1:
            matrixMenu();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            exit(1);
            break;
    }
}

int matrixArithmetic() {

    const char *options[] = {"Matrix Addition","Matrix Subtraction","Matrix Multiplication"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Matrix>Matrix Arithmetic\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case -1:
        matrixMenu();
        break;
    default:
        matrixOp2input(selectedOption);
        break;
    }
}

int matrixOperation() {
    const char *options[] = {"Matrix Transpose","Matrix Inverse","Matrix Determinant"};

    setHeadingColor(GRAY);
    setSelectionColor(TURQUOISE);
    setNotSelectedColor(LIME);
    clearScreen(1);
    printf("%smainMenu>Matrix>Matrix Operation\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case -1:
        matrixMenu();
        break;
    default:
        matrixOp1input(selectedOption);
        break;
    }
}

int matrixNotDefined() {
    // int defined = 0;
    if (matArray == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Matrix *defineMatrix(int n) {
    const char *options[] = {"Matrix A", "Matrix B", "Matrix C", "Matrix D"};

    char prompt[64] = "mainMenu>Matrix>Matrix Define";
    strcat(prompt, options[n]);
    clearScreen(1);
    printf("%s%s\n%s",OLIVE,prompt,RESET);
    
    setPromptColor(YELLOW);
    int rows = -1;
    while (rows < 1 || rows > 9) {
        rows = stoi(inputValidator("Enter rows: ", "I", 1));
    }
    setPromptColor(YELLOW);
    int cols = -1;
    while (cols < 1 || cols > 9) {
        cols = stoi(inputValidator("Enter cols: ", "I", 1));
    }
    Matrix *mat = matrixAlloc(rows, cols);
    double value = 0;
    clearScreen(1);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            clearScreen(1);
            printf("%smainMenu>Matrix>Matrix Define\n%s",OLIVE,RESET);
            displayMatrixFloat(mat);
            setPromptColor(YELLOW);
            value = stof(inputValidator("Enter Value: ", "F", 32));
            mat->mat[i][j] = value;
        }
    }

    // Display The Updated Matrix
    clearScreen(1);
    printf("%s%s\n%s",OLIVE,prompt,RESET);
    displayMatrixFloat(mat);
    setPromptColor(YELLOW);
    // printf("%sPress enter to continue\n%s",OLIVE,RESET);

    int i = stoi(inputValidator("Press enter key to continue", "I", 0));
    return mat;
}

int matrixDefine() {
    const char *options[] = {"Matrix A", "Matrix B", "Matrix C", "Matrix D"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Matrix>Matrix Define\n%s",OLIVE,RESET);
    printf("%sChoose a Matrix\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 4);

    switch (selectedOption)
    {
    case -1:
        matrixMenu();
        break;
    default:
        // Allocate memory for Matrices Array
        if (matArray == NULL) {
            matArray = (Matrix **)calloc(5, sizeof(Matrix *));
        }
        // Free Pre-Allocated memory of previous definition of Matrix
        if (matArray[selectedOption] != NULL) {
            free(matArray[selectedOption]);
            matArray[selectedOption] = NULL;
        }
        matArray[selectedOption] = defineMatrix(selectedOption);
        break;
    }

    matrixMenu();
}

int matrixExitMenu() {
    const char *options[] = {"Matrix Previous Menu", "Matrix Main Menu", "Main Menu", "Exit"};
    
    int selectedOption = displayList(options, 4);
    return selectedOption;
}

int matrixNotDefinedMenu() {
    const char *options[] = {"Define Matrix", "Matrix Main Menu", "Main Menu", "Exit"};
    
    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Matrix\n%s",OLIVE,RESET);
    printf("%sNo Matrix is Defined. Please Define a Matrix First!\n%s",OLIVE,RESET);

    int selectedOption = displayList(options, 4);
    switch (selectedOption)
    {
    case 0:
        matrixDefine();
        break;
    case 1: case -1:
        matrixMenu();
        break;
    case 2:
        mainMenu();
        break;
    case 3:
        exit(1);
        break;
    }
}

int matrixMenu() {
    const char *options[] = {"Define Matrix","Matrix Arithmetic","Matrix Operation"};

    setHeadingColor(GRAY);
    setSelectionColor(GOLD);
    setNotSelectedColor(TANGERINE);
    clearScreen(1);
    printf("%smainMenu>Matrix\n%s",OLIVE,RESET);
    int selectedOption = displayList(options, 3);

    switch (selectedOption)
    {
    case 0:
        matrixDefine();
        break;
    case 1:
        if (matrixNotDefined()) {
            matrixNotDefinedMenu();
        } else {
            matrixArithmetic();
        }
        break;
    case 2:
        if (matrixNotDefined()) {
            matrixNotDefinedMenu();
        } else {
            matrixOperation();
        }
        break;
    case -1:
        mainMenu();
        break;
    } 
}
