#include <stdio.h>
#include <stdlib.h>

enum _direction {ROW, COLUMN};

void printMatrix(int nrow, int ncol, int* matrix);

void fillMatrix(int nrow, int ncol, int*matrix);

void sum(int nelements, int* vector);

void product(int nelements, int* vector);

void apply(int nrow, int ncol, int*mat,  void (*operation)(int, int*), enum _direction direction);