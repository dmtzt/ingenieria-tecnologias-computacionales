#include <stdio.h>
#include <stdlib.h>

enum _direction {ROW, COLUMN};

void printMatrix(int nrow, int ncol, int* matrix){
    for(int i=0; i < nrow*ncol; i++){
        if (i%ncol == 0){
            printf("\n");
        }
        printf("%d \t", *(matrix+i));
    }
    printf("\n");
}

void fillMatrix(int nrow, int ncol, int*matrix){
    for(int i=0; i < nrow*ncol; i++){
        *(matrix+i) = i;
    }
}

void sum(int nelements, int* vector)
{
    int result = 0;
    for(int i=0; i<nelements; i++){
        result+= *(vector+i);
    }
    printf("%d\n", result);
}

void product(int nelements, int* vector)
{
    int result = 1;
    for(int i=0; i<nelements; i++){
        result*= *(vector+i);
    }
    printf("%d\n", result);
}

void apply(int nrow, int ncol, int*mat,  void (*operation)(int, int*), enum _direction direction){
    if (direction == ROW){
        int* vector = (int*) malloc(sizeof(int)*ncol);
        for (int i=0; i<nrow; i++){
            for(int j=0; j<ncol; j++){
                *(vector+j) = *( mat+j+(i*ncol) );
            }
            operation(ncol, vector);
        }
    } else if(direction == COLUMN){
        int* vector = (int*) malloc(sizeof(int)*nrow);
        for (int i=0; i<ncol; i++){
            for(int j=0; j<nrow; j++){
                *(vector+j) = *(mat+i+(j*ncol) );
            }
            operation(nrow, vector);
        }

    }
}