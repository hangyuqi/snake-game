#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "head.h"
#include "move-fun.c"
#include "food-fun.c"
#include "startend.c"

int main(int num,char * string[])
{
    list head;
    srand((unsigned int)time(0));
    print_border();
    initialization(&head);
    print(&head);
    turn_above(&head);
    while(mood!='q')
    {
        switch(mood)
        {
            case 'a':turn_left(&head);
                     break;
            case 'd':turn_right(&head);
                     break;
            case 's':turn_under(&head);
                     break;
            case 'w':turn_above(&head);
                     break;
        }
    }
}