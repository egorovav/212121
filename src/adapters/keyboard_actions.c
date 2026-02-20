#include "keyboard_actions.h"

int checkStop(int key_pressed) {
    return key_pressed == ' ';
}

int checkSpeedChange(int key_pressed) {
    return key_pressed == 'A' || key_pressed == 'Z';
}

int checkPause(int key_pressed) {
    return key_pressed == '\n';
}

void speedChange(int key_pressed, int* speed) {
    if (checkSpeedChange(key_pressed)) {
        if (key_pressed == 'A') {
            *speed += 50;
        } else if (key_pressed == 'Z') {
            *speed -= 50;
        }
        
        if (*speed <= 50) {
            *speed = 50;
        }
    }
}
