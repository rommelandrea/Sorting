/* 
 * File:   sorting.c
 * Author: rommel
 *
 * Created on October 28, 2011, 11:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */
int sorted(int [], int);
void isort(int [], int);
void ssort(int [], int);
void ssort2(int [], int);
void fillRandomArray(int [], int, int);
void copyArray(int [], int [], int);
void swap(int [], int, int);

/**
 * ordinamento per insertion sort
 * @param a
 * @param length
 */
void isort(int a[], int length) {
    int i;
    
    for(i=1; i<length; i++){
        while(a[i-1]>a[i]){
            swap(a, i-1, i);
            i--;
        }
    }
}

/**
 * ordinamento per selection sort
 * @param a
 * @param length
 */
void ssort(int a[], int length) {

}

/**
 * ordinamento per selection sort variante
 * @param a
 * @param length
 */
void ssort2(int a[], int length) {

}

/**
 * controlla se l'array è ordinato
 * restituisce 1 se ordinato 0 altrimenti
 * @param a array
 * @param length lunghezza array
 * @return restituisce 0 o 1
 */
int sorted(int a[], int length) {
    int i;
    for (i = 1; i < length; i++)
        if (a[i - 1] > a[i])
            return 0;

    return 1;
}

/**
 * riempie l'array di elementi casuali compresi tra 0 e max
 * @param a array
 * @param length lunghezza array
 * @param max valore massimo
 */
void fillRandomArray(int a[], int length, int max) {
    srand(time(NULL));
    int i;
    
    for(i=0; i<length; i++)
        a[i] = rand()%max;
}

/**
 * scambia l'elemento i con l'elemento j
 * @param a array
 * @param i primo elemento da scambiare
 * @param j secondo elemento da scambiare
 */
void swap(int a[], int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void print(int a[], int length){
    int i;
    printf("stampo l'array\n");
    for(i=0; i<length; i++){
        printf("%d-->", a[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int length = 10;
    int a[length];
    
    fillRandomArray(a, length, 10);
    print(a, length);
    isort(a, length);
    print(a, length);
    
    return (EXIT_SUCCESS);
}

