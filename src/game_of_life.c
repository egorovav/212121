#include <stdio.h>
#include <ncurses.h>
#include "adapters/messages.h"
#include "adapters/keyboard_actions.h"
#include "adapters/data_io.h"
#include "usecases/game_logic.h"

int changeStdin() {
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        //printError();
        return -1;
    }

    return 0;
}


int main() {
    int current_data[ROWS][COLLS];
    if (input(current_data) == -1) {
        //printError();
        return -1;
    }

    FILE *tty = fopen("/dev/tty", "r+");
    if (tty == NULL) {
        return -1;
    }

    SCREEN *term = newterm(NULL, tty, tty);
    set_term(term);

    cbreak();
    noecho();
    printHello();
    refresh();
    nodelay(stdscr, TRUE);

    int key_pressed;
    int is_pause = 0;
    int speed = 100;

    while ((key_pressed = getch()) && !checkStop(key_pressed)) {
        if (checkPause(key_pressed)) {
            is_pause = !is_pause;
        }

        speedChange(key_pressed, &speed);
        if (!is_pause) {
            int new_data[ROWS][COLLS];
            fillNewGeneration(new_data, current_data);
            copy(current_data, new_data);
        }
        clear();
        output(current_data);
        mvprintw(ROWS, 0, "Delay: %d ms | Pause: %s", speed, is_pause ? "ON" : "OFF");
        refresh();

        napms(speed);
    }

    endwin();
    return 0;
}
