#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem


void calculate_the_maximum(int n, int k) {
    //Write your code here.
    int and, or, xor;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            if(and < a&b < k ) {
                and = a&b; 
            } 
            if(or < a|b < k ) {
                and = a&b; 
            } 
            if(xor < a^b < k ) {
                and = a&b; 
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