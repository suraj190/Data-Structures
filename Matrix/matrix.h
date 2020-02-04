//
// Created by Suraj M on 1/27/19.
//

#ifndef HW1_2_MATRIX_H
#define HW1_2_MATRIX_H
#include <stdio.h>

struct Matrix {


    double** vals;

};
typedef struct Matrix Matrix;



Matrix makeMatrix(int num_rows);

void readValues(FILE* f,int num_rows,Matrix* given_mat);

double findDeterminant(Matrix* matrix, int num_rows, int offset);

void freeMatrix(Matrix* matrix, int num_rows);

#endif //HW1_2_MATRIX_H
