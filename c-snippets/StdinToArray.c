#include <stdio.h>

int main() {
    int i;
    //Input and read the number of ints that will be provided 
    scanf("%d", &i);
    int numbers[i];
    //Input and read in whitespace seperated line of integers
    for(int k = 0 ; k < i; k++) {
      scanf("%d",&numbers[k]);
    }
    int sum = 0;
    //Calculate the sum
    for (int j = 0; j < i; j++) {
        sum += numbers[j];
    }
    printf("%d", sum);

    return 0;
}