#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mergesort(int arr[], int size, int arrBuf[]) {
  //end of recursive tree
  if (size == 1) {
      arrBuf[0] = arr[0];
      return;
  }
  //half
  int mid = size/2;
  int firstSize = mid;
  int secondSize = size - mid;
  int first[firstSize];
  int second[secondSize];
  for (int i = 0; i < size; i++) {
    if (i < firstSize) {
      first[i] = arr[i];
    }
    else {
      second[i-mid] = arr[i];
    }
  }
  //sort
  int firstArrBuf[firstSize];
  int secondArrBuf[secondSize];
  mergesort(first, firstSize, firstArrBuf);
  mergesort(second, secondSize, secondArrBuf);
  //merge
  int i = 0; 
  int a = 0;
  int b = 0;
  while (i < size) {
      if ((b == secondSize || firstArrBuf[a] < secondArrBuf[b]) && a != firstSize) {
          arrBuf[i] = firstArrBuf[a];
          ++a;
      }
      else if (a == firstSize || firstArrBuf[a] > secondArrBuf[b]) {
          arrBuf[i] = secondArrBuf[b];
          ++b;
      }
        else if (firstArrBuf[a] == secondArrBuf[b]) {
          arrBuf[i] = firstArrBuf[a];
          ++a;
          ++i;
          arrBuf[i] = secondArrBuf[b];
          ++b;
        }
      ++i;
  }
  return;
}

int main() {
  int arr[100000];
  size_t size = sizeof(arr)/sizeof(int);  
  srand(time(0));
  for (int i = 0; i < size; i++) {
      arr[i] = rand() % size;
  }
  time_t time = clock();
  int arrSorted[size];
  mergesort(arr, size, arrSorted);
  time = clock() - time;  
  double elapseTime = ((double)time)/CLOCKS_PER_SEC; // in seconds 
  printf("Sorted %d elements in %f seconds \n", (int) size, elapseTime);

  //print
  //for (int i = 0; i < size; i++) {
  //    printf("%d ",arrSorted[i]);
  //}
  return 0;
}