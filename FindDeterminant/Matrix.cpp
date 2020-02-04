//
// Created by Suraj M on 2019-03-15.
//

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory>



Matrix makeMatrix(int numRows, int numCols) {
    Matrix matrix;
    matrix.numRows = numRows;
    matrix.numCols = numCols;
    matrix.values = (double**)malloc(numRows * sizeof(*matrix.values));
    for (int row = 0; row < numRows; ++row) {
        matrix.values[row] = (double*)malloc(numCols * sizeof(*matrix.values[row]));
    }
    return matrix;
}


Matrix readFile(const char *fileName) {
    FILE* file = fopen(fileName, "r");

    if (file) {
        int numRows, numCols;
        fscanf(file, "%d %d", &numRows, &numCols);
        Matrix matrix = makeMatrix(numRows, numCols);
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                fscanf(file, "%lf", &matrix.values[row][col]);
            }
        }
        fclose(file);
        return matrix;
    } else {
        printf("Failed to open %s\n", fileName);
        exit(0);
    }
}





double det(Matrix matrix) {
    Matrix trans = makeMatrix(matrix.numCols,matrix.numRows);

    for (int col = 0; col < matrix.numCols; ++col) {
        for (int row = 0; row < matrix.numRows; ++row) {
            trans.values[col][row] = matrix.values[row][col];
        }
    }

    double result = findDeterminant(trans);
    free(&trans);
    return result;

}


void free(Matrix *matrix) {
    for (int row = 0; row < matrix->numRows; ++row) {
        free(matrix->values[row]);
    }
    free(matrix->values);
    matrix->numRows = 0;
    matrix->numCols = 0;
    matrix->values = NULL;
}


double findDeterminant(Matrix matrix) {
    if (matrix.numRows == 2 && matrix.numCols == 2) {


        return (matrix.values[0][0] * matrix.values[1][1] -
                matrix.values[1][0] * matrix.values[0][1]);
    } else {
        int sign = 1;
        double det = 0;

        Matrix subMatrix = createSubMat(matrix.numRows - 1, matrix.numCols - 1);


        for (int row = 0; row < matrix.numRows; ++row) {
            fillSubMat(matrix, &subMatrix, row);
            det += sign * matrix.values[row][0] * findDeterminant(subMatrix);
            sign *= -1;
        }
        free(subMatrix.values);

        return det;
    }
}


Matrix createSubMat(int numRows, int numCols) {
    Matrix subMatrix;
    subMatrix.numCols = numRows;
    subMatrix.numRows = numCols;
    subMatrix.values = (double**)malloc(subMatrix.numRows * sizeof(*subMatrix.values));
    return subMatrix;
}


void fillSubMat(Matrix orig, Matrix *subMatrix, int offset) {
    for (int i = 0, j = 0; i < orig.numRows; ++i) {
        if (i != offset) {
            subMatrix->values[j] = orig.values[i] + 1;
            j++;
        }
    }
}



