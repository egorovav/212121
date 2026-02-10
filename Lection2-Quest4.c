// src/max.c
#include <stdio.h>

int max(int a, int b){
    if (a >= b){
        return a;
    } else {
        return b;
    } 
}

int main(){
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a\n");
        return 0;
    }

    char next_char;
    while ((next_char = getchar()) != "\n" && next_char != EOF) {
        if (next_char != ' ' && next_char != '\t') {
            printf("n/a");
            return 0;
        }
    }

    int result = max(a, b);
    printf("%d", result);
    return 0;
}