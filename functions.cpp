#include "functions.h"

// Define the variables declared as extern in the header
bool gameOver;
int x, y, vy=0;
int time_step=0;
eDirection dir;
int obstacles[width];

void UpdateObstacles()
{
    for (int i=0; i<width-1; i++)
    {
        obstacles[i]=obstacles[i+1];
    }
    obstacles[width-1]=rand()%3;
}


void Setup() {

    gameOver = false;
    dir = STOP;
    x = width/3; //coordinate of legs
    y = 1;
    
}

void Draw() {
    clear();

    printw("\n");
    for (int i = 0; i <= width; i++) {
        printw("#");
    }
    printw("\n");

    for (int i=height; i>=0; i--)
    {
        for (int j=0; j<=width; j++)
        {
            if (x==j & y==i){
                printw("|"); //legs
            } else if (x==j && y+1==i) //head: one above the lags
            {
                printw("o");
            }else if(i<obstacles[j])
            {
                printw("X");
            }
            
            
            else
            {
                printw(" ");
            }
        }
        printw("\n");
    }

    for (int i = 0; i <= width; i++) 
    {
        if ((i+time_step)%2==0)
        {
            printw(".");
        } else
        {
            printw("-");
        }

    }
    printw("\n");

    printw("\n");
    printw("to move press: \n");
    printw("left->a; right->d \n");
    printw("up->w; down->s \n");
    printw("time step: %d", time_step);
    printw("\n y: %d", y);
    printw("\n vy: %d", vy);

    
    refresh();
}

void Input() {
    nodelay(stdscr, TRUE);
    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
            case 'w':
                dir = UP;
                break;
            case 'x':
                gameOver=true;
                break;
            default:
                dir = STOP;
                break;
        }
    } else {
        dir = STOP;
    }
}

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void Jumps()
{
    switch (dir) {
            case UP:
                if(y==obstacles[width/3]) //leg location
                {
                    vy=3;
                    y+=vy;
                    
                }
                else
                {
                    if(y>obstacles[width/3])
                    {
                        vy--;
                    }
                    else
                    {
                        vy=0;
                    }
                    y+=vy;
                    y = max(y,obstacles[width/3]);
                    //y=max(y,1);
                }
                break;
            
            default:
                if(y>obstacles[width/3])
                {
                    vy--;
                }
                else
                {
                    vy=0;
                }
                y+=vy;
                y = max(y,obstacles[width/3]);
                break;
        }
}

void IfDead()
{
    if(y<obstacles[width/3])
    {
        gameOver=true;
    }
}

void Logic() {

    Jumps();
    UpdateObstacles();
    IfDead();


}



