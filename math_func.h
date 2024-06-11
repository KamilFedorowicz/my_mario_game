//
//  math_func.h
//  my_mario_game
//
//  Created by Kamil Fedorowicz on 11/06/2024.
//

#ifndef math_func_h
#define math_func_h

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

int min(int a, int b)
{
    if (a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}


#endif /* math_func_h */
