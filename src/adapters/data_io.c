#include "data_io.h"
#include <stdio.h>
#include <ncurses.h>

int input(int data[ROWS][COLLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLS; j++) {
            char c;
            if (scanf("%d%c", &data[i][j], &c) != 1 && c != '\n' && c != ' ' && c != EOF) {
                return -1;
            }
        }
    }
    return 0;
}

void output(int current_data[ROWS][COLLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLS; j++) {
            if (current_data[i][j] == 1) {
                mvaddch(i, j, '*');
            } else {
                mvaddch(i, j, ' ');
            }
        }
    }
}
