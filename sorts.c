#include "sorts.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 選択ソート
/**
 * @brief
 * 概要: 選択ソートは配列の中から最小値を見つけ、
 * それを配列の先頭に移動することを繰り返すことで、
 * 配列をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param size 配列のサイズ
 */
void selection_sort(int array[], int size) {
    for(int i=0; i<size; i++) {
        int min = array[i];
        int min_index = i;
        for(int j=i+1; j<size; j++) {
            if(array[j] < min) {
                min = array[j];
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
}


// バブルソート
/**
 * @brief
 * 概要: バブルソートは隣り合う要素を比較して、
 * 順番が逆であれば交換することを繰り返すことで、
 * 配列をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param size 配列のサイズ
 */
void bubble_sort(int array[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}


// 挿入ソート
/**
 * @brief
 * 概要: 挿入ソートは配列を整列済み部分と未整列部分に分け、
 * 未整列部分の最小要素を整列済み部分に挿入することを繰り返すことで、
 * 配列をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param size 配列のサイズ
 */
void insertion_sort(int array[], int size) {
    for(int i=1; i<size; i++) {
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}


// ヒープソート
void heapify(int array[], int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && array[left] > array[largest]) {
        largest = left;
    }

    if(right < size && array[right] > array[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

/**
 * @brief
 * 概要: ヒープソートは、ヒープ木を使って配列をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param size 配列のサイズ
 */
void heap_sort(int array[], int size) {
    for(int i=size/2-1; i>=0; i--) {
        heapify(array, size, i);
    }

    for(int i=size-1; i>0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}


// マージソート
void merge(int array[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++) {
        L[i] = array[l+i];
    }

    for(int i=0; i<n2; i++) {
        R[i] = array[m+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j<n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief
 * 概要: マージソートは、分割統治法を用いて配列をソートするアルゴリズム。
 * 配列を半分に分割し、それぞれをソートし、
 * それらをマージすることで、配列全体をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param l 配列の先頭インデックス
 * @param r 配列の末尾インデックス
 */
void merge_sort(int array[], int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        merge_sort(array, l, m);
        merge_sort(array, m+1, r);
        merge(array, l, m, r);
    }
}


// クイックソート
/**
 * @brief
 * 概要: クイックソートは、分割統治法を用いて配列をソートするアルゴリズム。
 * 配列の中からピボットを選び、それを基準にして配列を分割し、
 * それぞれをソートすることで、配列全体をソートするアルゴリズム
 * 
 * @param array ソートする配列
 * @param low 配列の先頭インデックス
 * @param high 配列の末尾インデックス
 */
void quick_sort(int array[], int low, int high) {
    if(low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi-1);
        quick_sort(array, pi+1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if(array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);
    return i+1;
}