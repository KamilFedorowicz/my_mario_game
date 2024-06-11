#include "functions.h"
#include "math_func.h"

// Define the variables declared as extern in the header
bool gameOver;
int x, y, vy, xH, yH; //y=10 makes mario when the game starts
int time_step=0;
eDirection dir;
int obstacles[width];
int obstacleWidth=7; // how wide the obstacles are
int lives = 3;


void InitialiseObstacles()
{
    for (int i=0; i<width; i++)
    {
        obstacles[i] = 5;
    }
}


void UpdateObstacles()
{
    for (int i=0; i<width-1; i++)
    {
        obstacles[i]=obstacles[i+1];
    }
    
    //here we decide on the value of the last obstacle
    //every obstacleWidth iterations, it will change a value
    if( time_step%obstacleWidth==0) // change height every 5 time steps
    {
        int increment = (rand()%2==0) ? 2:-2; // increment obstacle by either +2 or -2
        obstacles[width-1]=min(max(obstacles[width-2] + increment,0),10);
    }
    else
    {
        obstacles[width-1]=obstacles[width-2];
    }
    
}

void GenerateHearts()
{
    if (time_step%60==0)
    {
        xH = width;
        yH=obstacles[width-1]+4;
    }
}

void UpdateHearts()
{
    xH--;
    if ( (xH==width/3 || xH==(width/3-1)|| xH==(width/3+1)) && (y==yH || y+1==yH))
    {
        lives++;
        xH=-1;
        yH=-1;
    }
}



void Setup() {

    gameOver = false;
    dir = STOP;
    x = width/3; //coordinate of legs
    y = 15;
    vy=0;
    
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
            }else if (i==yH && j==xH)
            {
                printw("<3");
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
    printw("to jump press: \n");
    printw("q (high jump); w (low jump) \n");
    printw("time step: %d", time_step);
    printw("\n y: %d", y);
    printw("\n vy: %d", vy);
    printw("\n lives: %d", lives);
    

    
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
            case 'q':
                dir = UP2;
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
        case UP2:
            if(y==obstacles[width/3]) //leg location
            {
                vy=4;
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
        lives--;
        Setup();
    }
    
    if (lives<=0)
    {
        gameOver=true;
    }
}

void IfGameOver()
{
    
}

void Logic() {

    Jumps();
    UpdateObstacles();
    IfDead();
    GenerateHearts();
    UpdateHearts();


}



