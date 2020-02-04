#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "matrix.h"




int main(int argc, char** argv) {

    int num_rows;
    double vals[100];
    char line[256];
    int i = 0;



    FILE* f;

    f = fopen(argv[1], "r");

    fgets(line,sizeof(line),f);


    char* p = strtok(line," ");

    while(p!=NULL){

        vals[i++] = atoi(p);
        p = strtok(NULL, " ");
    }


    num_rows = (int) vals[0];




    Matrix matrix = makeMatrix(num_rows);


    readValues(f,num_rows,&matrix);



    double determinant = findDeterminant(&matrix,num_rows,0);



    printf("The determinant is %0.2lf.",determinant);

    freeMatrix(&matrix, num_rows);



    fclose(f);
    return 0;

}
