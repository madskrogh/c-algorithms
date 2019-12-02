#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* mergesort(int arr[], int size, long *inversions) {
    if (size/sizeof(int) == 1) {
        return arr;
    }
    int firstSize;
    int secondSize;
    if ((size/sizeof(int) % 2 == 0)) {
      firstSize = size/2;
      secondSize = size/2;
    } 
    else {
      firstSize = (size+sizeof(int))/2;
      secondSize = (size-sizeof(int))/2;
    }

    //half
    int* first = malloc(firstSize);
    int* second = malloc(secondSize);
    memcpy(first, arr, firstSize);
    memcpy(second, arr + (firstSize/sizeof(int)), secondSize);

    int* firstSorted = mergesort(first, firstSize, inversions);
    int* secondSorted = mergesort(second, secondSize, inversions);

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
            *inversions += (firstSize/sizeof(int))-a;
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
    char filename[] = "C:\\Users\\DKKRX\\Desktop\\privat\\cygwin64\\home\\DKKRX\\c-algorithms\\inversions\\integerArray.txt";
    int arr[100000];
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to read file: %s", filename);
        return 0;
    }  
    int i = 0;
    int count = 0;
    fscanf (file, "%d", &i); 
    while (!feof (file))
    {  
      fscanf (file, "%d", &arr[count]);
      count += 1;
    }
    fclose (file);   
    size_t size = sizeof(arr); 
    long inversions = 0; 
    int* arrSorted = mergesort(arr, size, &inversions); 
    printf("number of inversions: %llu \n", inversions);
    return 0;
}