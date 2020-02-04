//
// Created by Suraj M on 2019-03-15.
//

#ifndef FINDDETERMINANT_MATRIX_H
#define FINDDETERMINANT_MATRIX_H
#include <stdio.h>

typedef struct MatrixStruct{
    double** values;
    int numRows;
    int numCols;
} Matrix;


Matrix makeMatrix(int numRows, int numCols);
Matrix readFile(const char *fileName);
Matrix transpose(Matrix matrix);
double det(Matrix matrix);
void free(Matrix *matrix);


double findDeterminant(Matrix matrix);
Matrix createSubMat(int numRows, int numCols);
void fillSubMat(Matrix orig, Matrix *subMatrix, int offset);
#endif //FINDDETERMINANT_MATRIX_H
