#include <stdio.h>
#include <stdlib.h>

//Approach one
int* reverseOne(int arr[], int num) {
    int i, temp;
    for(i = 0;i < num/2; i++) {
        temp = arr[i];
        arr[i] = arr[num-i-1];
        arr[num-i-1] = temp;
    }
    return arr;
}

//Approach two
int* reverseTwo(int arr[], int num) {
    int i, temp;
    for(i = 0;i < num/2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + (num-i-1));
        *(arr + (num-i-1)) = temp;
    }
    return arr;
}

int main()
{
    int num, *arr, i, temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    //arr = reverseOne(arr, num);
    arr = reverseTwo(arr, num);

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}