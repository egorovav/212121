#include "../entities/consts.h"

void copy(int current_data[ROWS][COLLS], int new_data[ROWS][COLLS]); // deeannak // Перезаписывание текущей матрицы новыми данными из new_data
int is_alive(int current_data[ROWS][COLLS], int i, int j); // deeannak // Вычисление живой/неживой клетки на основе текущей матрицы, текущих индексов
void fillNewGeneration(int new_data[ROWS][COLLS], int current_data[ROWS][COLLS]); // migaskiw // Вычисление нового поколения
int count_live_cells(int current[ROWS][COLLS], int y, int x);