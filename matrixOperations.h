#ifndef MATRIX_OP
#define MATRIX_OP

// Struct

typedef struct Matrix {
    int rows;
    int cols;
    double **mat;
} Matrix;

// Public Functions
void matrixDealloc(Matrix *mat);
void displayMatrix(Matrix *mat);
void displayMatrixFloat(Matrix *mat);
void matrixMinor(double **mat, double **minor, int row, int col, int m, int n);
int matrixMenu();
int matrixDefine();
int matrixArithmetic();
double matrixDeterminant(Matrix *matrix);
Matrix *matrixAlloc(int rows, int cols);
Matrix *matrixTranspose(Matrix *mat);
Matrix *matrixAddition(Matrix *mat1, Matrix *mat2);
Matrix *matrixSubtraction(Matrix *mat1, Matrix *mat2);
Matrix *matrixMultiplication(Matrix *mat1, Matrix *mat2);
Matrix *matrixAdjoint(Matrix *mat);
Matrix *matrixInverse(Matrix *mat);

#endif