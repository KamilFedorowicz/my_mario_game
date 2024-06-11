#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <limits>


const int width=40;
const int height=20;
extern int obstacles[width];
extern int obstacleWidth;
extern int lives;

enum eDirection{UP, UP2, STOP} ;
extern bool gameOver;
extern int x, y, vy, xH, yH;
extern int time_step;


void Setup();
void Draw();
void Input();
void Logic();

void Jumps();
void InitialiseObstacles();
void UpdateObstacles();


#endif // FUNCTIONS_H
