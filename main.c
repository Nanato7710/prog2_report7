#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"


void random_array(int a[], int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        a[i] = rand() % 100;
    }
}


void print_array(int a[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    const int SIZE = 5;
    int scores[SIZE] = {0, 60, 70, 100, 90};
    merge_sort(scores, 0, SIZE-1);
    print_array(scores, SIZE);

    return 0;
}
