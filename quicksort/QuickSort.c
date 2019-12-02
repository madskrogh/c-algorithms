//1. pick random pivot element in array
//2. partition arround array arround the pivot so all numbers left of pivot are smaller and all to the right are larger
//2. do two recursive calls to quicksort() - one with each side of pivot

#include <stdio.h>
#include <stdlib.h> 
#include<time.h> 

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

int choosepivot(int arr[], int n, int left) {
    srand(time(0));
    return rand() % (n) + left;
}

int partition(int arr[], int n, int left, int pivot) {
    int i, j, k;
    //Swap pivot with left most element
    swap(arr, pivot, left);
    i = left + 1;
    j = left + 1;
    for (k = 0; k < n-1; k++, j++) {
        if (arr[j] < arr[left]) {
            swap(arr, j, i++);
        }
    }
    swap(arr, left, i-1);
    return i;
}

void quicksort(int arr[], int n, int left) {
    if (n <= 1) {
        return;
    }
    int pivot = choosepivot(arr, n, left); //This is an index
    int i = partition(arr, n, left, pivot);
    quicksort(arr, i - 1 - left, left); //Left side of arr, excluding pivot
    quicksort(arr, n - i + left, i); //Right side og arr, excluding pivot
}

int main() {
    int n, i;
    int arr[] = {9,3,8,13,2,5,10,0,1,12,11,4,7,6};
    n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, n, 0);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }