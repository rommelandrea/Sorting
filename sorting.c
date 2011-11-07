/* 
 * File:   sorting.c
 * Author: Andrea Romanello
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
void print(int [], int);
void tester(int, int, int);
int ricBin(int, int [], int);

/**
 * ordinamento per insertion sort
 * @param a
 * @param length
 */
void isort(int a[], int length) {
    int i;

    for (i = 1; i < length; i++) {
        while (a[i - 1] > a[i] && i > 0) {
            swap(a, i - 1, i);
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
    int i, j, min;

    for (i = 0; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (a[min] > a[j])
                min = j;
        }
        swap(a, i, min);
    }
}

/**
 * ordinamento per selection sort variante
 * @param a
 * @param length
 */
void ssort2(int a[], int length) {
    int i, j, max;
    j = length - 1;
    i = 0;

    while (i <= j) {
        max = i;
        for (i = 0; i <= j; i++) {
            if (a[max] < a[i])
                max = i;
        }
        swap(a, j, max);
        j--;
        i = 0;
    }
}

int ricBin(int x, int a[], int length) {
    int inf, mid, sup;

    inf = 0;
    sup = length - 1;

    while (inf <= sup) {
        mid = ((sup - inf) / 2) + inf;
        if (a[mid] == x)
            return 1;
        else {
            if (a[mid] > x) {
                sup = mid - 1;
            } else {
                inf = mid + 1;
            }
        }
    }
    return 0;
}

int ricBinr(int x, int a[], int inf, int sup) {
    if (inf > sup)
        return 0;

    int mid = ((sup - inf) / 2) + inf;

    if (a[mid] == x)
        return 1;
    else {
        if (a[mid] > x) {
            return ricBinr(x, a, inf, mid-1);
        } else {
            return ricBinr(x, a, mid+1, sup);
        }
    }
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
 * copia l'array a nell'array b
 * @param a
 * @param b
 * @param length
 */
void copyArray(int a[], int b[], int length) {
    int i = 0;

    for (i = 0; i < length; i++)
        b[i] = a[i];
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

    for (i = 0; i < length; i++)
        a[i] = rand() % max;
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

/**
 * stampo l'array
 * @param a array da stampare
 * @param length lunghezza dell'array
 */
void print(int a[], int length) {
    int i;
    printf("stampo l'array\n");
    for (i = 0; i < length; i++) {
        printf("%d-->", a[i]);
    }
    printf("\n");
}

void tester(int start, int end, int step) {

    FILE *f = fopen("misure_tempi.txt", "w+");
    clock_t start1, start2, start3;
    clock_t end1, end2, end3;

    float tot1, tot2, tot3;

    int a1[end];
    int a2[end];
    int a3[end];

    for (; start <= end; start += step) {
        printf("testo con %d\n", start);

        fillRandomArray(a1, start, start / 5);
        copyArray(a1, a2, start);
        copyArray(a1, a3, start);

        start1 = clock();
        ssort(a1, start);
        end1 = clock();


        start2 = clock();
        ssort2(a2, start);
        end2 = clock();

        start3 = clock();
        isort(a3, start);
        end3 = clock();

        tot1 = (float) (end1 - start1) / (float) CLOCKS_PER_SEC;
        tot2 = (float) (end2 - start2) / (float) CLOCKS_PER_SEC;
        tot3 = (float) (end3 - start3) / (float) CLOCKS_PER_SEC;


        printf("tempo selection = %.4f \ntempo selectionMax = %.4f \ntempo insertion = %f\n", tot1, tot2, tot3);


        if (sorted(a1, start))
            printf("a e' ordinato\n");
        else
            printf("a non e' oridinato\n");

        if (sorted(a2, start))
            printf("b e' ordinato\n");
        else
            printf("b non e' oridinato\n");

        if (sorted(a3, start))
            printf("c e' ordinato\n");
        else
            printf("c non e' oridinato\n");

        fprintf(f, "----Tempo di esecuzione degli algoritmi di ordinamento con %d elementi----\n\n", start);
        fprintf(f, "Insertion Sort                                        --> : \t%5.4f secondi\n", tot3);
        fprintf(f, "Selection Sort con estrazioni successive del minimo   --> : \t%5.4f secondi\n", tot1);
        fprintf(f, "Selection Sort con estrazioni successive del massimo  --> : \t%5.4f secondi\n\n\n", tot2);
    }

    fclose(f);
}

int main(int argc, char** argv) {

    //tester(5000, 100000, 5000);

    int length = 20;
    int a[length];
    int result;

    fillRandomArray(a, length, length);
    ssort(a, length);

    print(a, length);

    result = ricBinr(3, a, 0, length-1);

    printf("risultato ricerca binaria: %d \n", result);

    return (EXIT_SUCCESS);
}

