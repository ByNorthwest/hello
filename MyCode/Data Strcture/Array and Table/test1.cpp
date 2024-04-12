#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct {
    int row,col;
    int e;
}Tripe;
typedef struct {
    Tripe data[MAXSIZE];
    int m,n,len;
}TSMatrix;
