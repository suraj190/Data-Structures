
#include "Matrix.h"
#include "stdio.h"

int main(int argc, char** argv) {



    Matrix matrix = readFile(argv[1]);
    double determinant = det(matrix);
    printf("The determinant is %.2lf.\n", determinant);
    free(&matrix);
    return 0;
}
