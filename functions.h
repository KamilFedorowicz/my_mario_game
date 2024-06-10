#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <limits>

const int width=40;
const int height=20;
extern int obstacles[width];

enum eDirection{UP, STOP} ;
extern bool gameOver;
extern int x, y, vy;
extern int time_step;


void Setup();
void Draw();
void Input();
void Logic();

void Jumps();
void UpdateObstacles();


#endif // FUNCTIONS_H
