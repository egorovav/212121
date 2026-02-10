// src/arithmetic.c
#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d %d", a + b, a - b, a * b);
    if (b == 0){
        printf(" n/a");
    } else {
        printf(" %d", a / b);
    }


    return 0;
}