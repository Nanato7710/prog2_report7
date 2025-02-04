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
    printf("実行例1（int scores[5] = {0, 60, 70, 100, 90};とした場合の結果）\n");
    int scores[5] = {0, 60, 70, 100, 90};
    printf("scores = ");
    print_array(scores, 5);
    merge_sort(scores, 0, 5-1);
    printf("result = ");
    print_array(scores, 5);

    printf("\n\n\n");

    printf("実行例2（int scores[6] = {100, 60, 70, 100, 90, 80};）\n");
    int scores2[6] = {100, 60, 70, 100, 90, 80};
    printf("scores = ");
    print_array(scores2, 6);
    merge_sort(scores2, 0, 6-1);
    printf("result = ");
    print_array(scores2, 6);

    return 0;
}
