#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "head.h"

void print_border(void)
{
    FILE * fp;
    char c;
    if((fp=fopen("start-game","r"))==NULL)
    {
        fprintf(stderr,"can't open file border.\n");
        exit(EXIT_FAILURE);
    }
    while((c=getc(fp))!=EOF)
    {
        putchar(c);
    }
    fclose(fp);
}

void judge(list * pt)
{
    Node * scan;
    scan=(*pt)->next;
    while(scan!=NULL)
    {
        if((*pt)->item.x==scan->item.x&&(*pt)->item.y==scan->item.y)
        {
            exit(1);
        }
        scan=scan->next;
    }
    scan=(*pt);
    if(scan->item.x==0||scan->item.x==81||scan->item.y==13||scan->item.y==34)
    {
        exit(1);
    }
}

void lengthen(list * pt)
{
    Node * scan;
    Node * fnew;
    fnew=(Node *)malloc(sizeof(Node));
    scan=(*pt);
    fnew->next=NULL;
    while(scan->next!=NULL)
    {
        scan=scan->next;
        continue;
    }
    scan->next=fnew;
}