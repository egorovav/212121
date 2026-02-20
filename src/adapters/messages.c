#include <string.h>
#include <ncurses.h>

void printHello() {
    clear();

    if (has_colors()) {
        start_color();
        use_default_colors(); 
        init_pair(1, COLOR_GREEN, -1); 
    }

    int y, x;
    getmaxyx(stdscr, y, x);

    char *t1 = "Glad to see you in The Game of Life";
    char *t2 = "by migaskiw, kerenbea, deeannak";
    char *t3 = "Press any key to start";

    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(y / 2 - 1, (x - strlen(t1)) / 2, "%s", t1);
    attroff(COLOR_PAIR(1) | A_BOLD);

    mvprintw(y / 2 + 1, (x - strlen(t2)) / 2, "%s", t2);
    mvprintw(y - 2, (x - strlen(t3)) / 2, "%s", t3);

    refresh();

    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);
}
