#ifndef _SORTS_H_
#define _SORTS_H_

void swap(int *a, int *b);

void selection_sort(int array[], int size);

void bubble_sort(int array[], int size);

void insertion_sort(int array[], int size);

void heap_sort(int array[], int size);
void heapify(int array[], int size, int i);

void merge_sort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);

void quick_sort(int array[], int low, int high);
int partition(int array[], int low, int high);

#endif