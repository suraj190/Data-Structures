//
// Created by Suraj M on 1/27/19.
//

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <math.h>



int sign(int num){

    if((num % 2 ) == 0){
        return 1;
    }

    else{
        return -1;
    }
}

Matrix makeMatrix(int num_rows) {


    Matrix matrix;



    matrix.vals =  malloc(num_rows * sizeof(double *));

    for (int i = 0; i < num_rows; i++) {

        matrix.vals[i] =  malloc(num_rows * sizeof(double));
    }




    return matrix;
}


void readValues(FILE* f,int num_rows,Matrix* matrix){

    //char buffer[256];
    int i = 0, j = 0;

    double val;

    for (i = 0; i < num_rows; i++) {

        for (j = 0; j < num_rows; j++) {

            fscanf(f, "%lf", &val);

            matrix -> vals[i][j] = val;
        }
    }

}




void createSubMatrix(Matrix* m, Matrix* orig_matrix,int num_rows,int col_offset){

    int i, j = 0;
    int offset = 0;

    for ( j = 0; j < num_rows; j++){

        if(j == col_offset){

            j++;
            offset=1;
        }

        for(i = 1; i < num_rows; i++){

            if(j == col_offset){

                j++;
                offset=1;
            }

            if(offset==1){

                m->vals[i-1][j-1] = orig_matrix->vals[i][j];

            }

            else{

                m->vals[i-1][j] = orig_matrix->vals[i][j];
            }
        }

    }

}





void freeMatrix(Matrix* matrix, int num_rows){


    for(int i = 0 ; i < num_rows ; i++) {

        free(matrix->vals[i]);

    }

    free(matrix->vals);



}



Matrix createMat(int num_rows){


    int j = 0;
    Matrix mat;
    mat.vals = malloc(num_rows * sizeof( double *));
    for (j = 0; j < num_rows; j++) {
        mat.vals[j] = malloc(num_rows * sizeof( double));
    }

    return(mat);

}



double findDeterminant(Matrix* matrix, int num_rows, int offset) {

    double determinant=0;

    Matrix subMat;


    if(num_rows==2){

        determinant = ((matrix->vals[0][0] * matrix->vals[1][1]) -(matrix->vals[0][1] * matrix->vals[1][0]));

        return determinant;


    }

    else if(num_rows==1){

        determinant = matrix->vals[0][0];

        return determinant;
    }

    else{

        for(int i = 0; i<num_rows; i++){

            subMat = createMat(num_rows-1);

            createSubMatrix(&subMat,matrix, num_rows, i);

            determinant = determinant+ (double) matrix->vals[0][i] * sign(i+0) * findDeterminant(&subMat,(num_rows-1),i);

            freeMatrix(&subMat, num_rows-1);

        }

        return determinant;
    }



}






