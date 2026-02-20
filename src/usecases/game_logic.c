#include "game_logic.h"

void fillNewGeneration(int new_data[ROWS][COLLS], int current_data[ROWS][COLLS]) {
    int current_cell = -1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLS; j++) {
            current_cell = is_alive(current_data, i, j);
            new_data[i][j] = current_cell;
        }
    }
}

void copy(int current_data[ROWS][COLLS], int new_data[ROWS][COLLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLS; j++) {
            current_data[i][j] = new_data[i][j];
        }
    }
}


int count_live_cells(int current[ROWS][COLLS], int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                int cell_y = (y + i + ROWS) % ROWS;
                int cell_x = (x + j + COLLS) % COLLS;
                count += current[cell_y][cell_x];
            }
        }
    }
    return count;
}

int is_alive(int current_data[ROWS][COLLS], int y, int x) {
    int live_cells = count_live_cells(current_data, y, x);
    if (current_data[y][x] == 1) {
        return (live_cells == 2 || live_cells == 3) ? 1 : 0;
    } else {
        return (live_cells == 3) ? 1 : 0;
    }
}