#include "data_io.h"
#include <stdio.h>
#include <ncurses.h>

int input(int data[ROWS][COLLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLS; j++) {
            char c;
            if (scanf("%d%c", &data[i][j], &c) != 2) {
                return -1;
            }
            if(data[i][j] != 0 && data[i][j] != 1) {
            	return -1;
            }
            if(c != '\n' && c != ' ' && c != EOF && c != '\r') {
            	return -1;
            }
            if(j == COLLS - 1 && c != '\n' && c != '\r') {
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


