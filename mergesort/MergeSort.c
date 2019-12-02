#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* mergesort(int arr[], int size) {
    if (size/sizeof(int) == 1) {
        return arr;
    }
    int firstSize = (size/sizeof(int)/2)*sizeof(int);
    int secondSize = ((size/sizeof(int)) - firstSize/sizeof(int))*sizeof(int);
    //half
    int* first = malloc(firstSize);
    int* second = malloc(secondSize);
    memcpy(first, arr, firstSize);
    memcpy(second, arr + (firstSize/sizeof(int)), secondSize);

    //sort
    int* firstSorted = mergesort(first, firstSize);
    int* secondSorted = mergesort(second, secondSize);

    //merge
    int i = 0; 
    int a = 0;
    int b = 0;
    int* arrSorted = malloc(size);
    while (i < size/sizeof(int)) {
        if ((b == secondSize/sizeof(int) || firstSorted[a] < secondSorted[b]) && a != firstSize/sizeof(int)) {
            arrSorted[i] = firstSorted[a];
            ++a;
        }
        else if (a == firstSize/sizeof(int) || firstSorted[a] > secondSorted[b]) {
            arrSorted[i] = secondSorted[b];
            ++b;
        }
         else if (firstSorted[a] == secondSorted[b]) {
            arrSorted[i] = firstSorted[a];
            ++a;
            ++i;
            arrSorted[i] = secondSorted[b];
            ++b;
         }
        ++i;
    }
    free(first);
    free(second);
    return arrSorted;
}

int main() {
    int elements = 80000;
    int arr[elements];
    int i;
    for (i = 0; i < elements; i++) {
        arr[i] = rand();
    }
    size_t size = sizeof(arr);  
    time_t time = clock();
    int* arrSorted = mergesort(arr, size);
    time = clock() - time;  
    double elapseTime = ((double)time)/CLOCKS_PER_SEC; // in seconds 
    printf("Sorted %d elements in %f miliseconds", size/sizeof(int), elapseTime);

    //print
    //for (i = 0; i < size/sizeof(int); i++) {
    //    printf("%d ",arrSorted[i]);
    //}
    return 0;
}
