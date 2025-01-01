#ifndef VECTOR_OP
#define VECTOR_OP

// Structures
typedef struct Vector {
    int dimension;
    double *vec;
} Vector;

extern Vector **vecArray;

// Public Functions
struct Vector *vectorAlloc(int dimension);
void vectorDealloc(struct Vector *vec);
struct Vector *vectorAddition(struct Vector *vecA, struct Vector *vecB);
struct Vector *vectorSubtraction(struct Vector *vecA, struct Vector *vecB);
double vectorDotProduct(struct Vector *vecA, struct Vector *vecB);
struct Vector *vectorCrossProduct(struct Vector *vecA, struct Vector *vecB);
double vectorModulus(struct Vector *vecA);
int vectorArithmetic();
int vectorOperation();
int vectorMenu();
int vectorExitMenu();
int vectorNotDefinedMenu();
int vectorDefine();

#endif