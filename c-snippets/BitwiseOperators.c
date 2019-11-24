#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) {
    int and = 0, or = 0, xor = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a+1; b <= n; b++) {
            if (and < (a&b) && (a&b) < k ) {
                and = a&b; 
            } 
            if(or < (a|b) && (a|b) < k ) {
                or = a|b; 
            } 
            if(xor < (a^b) && (a^b) < k) {
                xor = a^b; 
            } 
        } 
    }   
    printf("%d \n", and); 
    printf("%d \n", or); 
    printf("%d \n", xor); 
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}