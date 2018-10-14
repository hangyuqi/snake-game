#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "head.h"

void get_food(void)
{
    prefood=food;
    food.x=rand()%80+1;
    food.y=rand()%20+14;
    while(1)
    {
        if(prefood.x==food.x&&prefood.y==food.y)
        {
            food.x=rand()%80+1;
            food.y=rand()%20+14;
        }
        else
        {
            break;
        }
    }
    print_food(food);
}

void print_food(Item pt)
{
    gotoxy(pt.x,pt.y);
    putchar(pt.body);
}