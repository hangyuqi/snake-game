#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "head.h"

void gotoxy(int x,int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initialization(list * pt)
{
    *pt=(Node *)malloc(sizeof(Node));
    (*pt)->item.x=42;
    (*pt)->item.y=25;
    (*pt)->item.body='X';
    int i;
    Node * scan=*pt;
    for(i=1;i<=4;i++)
    {
        Node * new;
        new=(Node *)malloc(sizeof(Node));
        new->item.x=scan->item.x;
        new->item.y=scan->item.y+1;
        new->item.body='o';
        scan->next=new;
        scan=scan->next;
    }
    scan->next=NULL;
    print(pt);
    food.x=rand()%80+1;
    food.y=rand()%20+14;
    food.body='*';
    print_food(food);
}

void print(list * pt)
{
    Node * scan;
    scan=*pt;
    while(scan!=NULL)
    {
        gotoxy(scan->item.x,scan->item.y);
        putchar(scan->item.body);
        scan=scan->next;
    }
}

void left(list * pt)
{
    pre=(*pt)->item;
    pre.body='o';
    (*pt)->item.x-=1;
}

void right(list * pt)
{
    pre=(*pt)->item;
    pre.body='o';
    (*pt)->item.x+=1;
}
void above(list * pt)
{
    pre=(*pt)->item;
    pre.body='o';
    (*pt)->item.y-=1;
}

void under(list * pt)
{
    pre=(*pt)->item;
    pre.body='o';
    (*pt)->item.y+=1;
}
void move(list * pt)
{
    Node * scan;
    scan=(*pt)->next;
    Item mid[length];
    mid[0]=pre;
    int i;
    for(i=1;i<length;i++)
    {
        mid[i]=scan->item;
        scan=scan->next;
    }
    scan=(*pt)->next;
    for(i=0;i<length-1;i++)
    {
        scan->item=mid[i];
        scan=scan->next;
    }
    gotoxy(mid[length-1].x,mid[length-1].y);
    putchar(' ');
}

void turn_left(list * pt)
{
    while(!kbhit())
    {
        left(pt);
        if((*pt)->item.x==food.x&&(*pt)->item.y==food.y)
        {
            get_food();
            count++;
            length++;
            lengthen(pt);
        }
        move(pt);
        judge(pt);
        print(pt);
        gotoxy(1,8);
        Sleep(SPEED);
    }
    mood=getch();
}

void turn_right(list * pt)
{
    while(!kbhit())
    {
        right(pt);
        if((*pt)->item.x==food.x&&(*pt)->item.y==food.y)
        {
            get_food();
            count++;
            length++;
            lengthen(pt);
        }
        move(pt);
        judge(pt);
        print(pt);
        gotoxy(1,8);
        Sleep(SPEED);
    }
    mood=getch();
}

void turn_above(list * pt)
{
    while(!kbhit())
    {
        above(pt);
        if((*pt)->item.x==food.x&&(*pt)->item.y==food.y)
        {
            get_food();
            count++;
            length++;
            lengthen(pt);
        }
        
        move(pt);
        judge(pt);
        print(pt);
        gotoxy(1,8);
        Sleep(SPEED);
    }
    mood=getch();
}

void turn_under(list * pt)
{
    while(!kbhit())
    {
        under(pt);
        if((*pt)->item.x==food.x&&(*pt)->item.y==food.y)
        {
            get_food();
            count++;
            length++;
            lengthen(pt);
        }
        move(pt);
        judge(pt);
        print(pt);
        gotoxy(1,8);
        Sleep(SPEED);
    }
    mood=getch();
}