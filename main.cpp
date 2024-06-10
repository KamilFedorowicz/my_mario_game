#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include "functions.h"



int main(int argc, const char *argv[]) {

    initscr();
    clear(); // clear the screen

    noecho(); // prevents letters from showing on the screen
    cbreak(); // enter is not required
    curs_set(0); // Hide the cursor

    srand(static_cast<unsigned int>(time(0))); // introduces randomness, in this case to the position of F
    Setup();
    

    while (!gameOver) {

            Draw();
            Input();
            Logic();
            usleep(100000);
        time_step++;
        // Sleep for a short period to slow down the game loop
    }

    endwin(); // End ncurses mode

    return 0;
}
