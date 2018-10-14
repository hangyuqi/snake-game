#ifndef SANKE
#define SANKE
#define SPEED 200
struct point{
    int x;
    int y;
    char body;
};
typedef struct point Item;
typedef struct node
{
    Item item;
    struct node * next;
} Node;
typedef Node * list;
Item pre;
Item food;
Item prefood;
char mood='a';
int length=5;
int count=0;
void gotoxy(int x,int y);
void initialization(list * pt);
void print(list * pt);
void move(list * pt);
void left(list * pt);
void right(list * pt);
void above(list * pt);
void under(list * pt);
void turn_left(list * pt);
void turn_right(list * pt);
void turn_above(list * pt);
void turn_under(list * pt);
void get_food(void);
void print_food(Item pt);
void print_border(void);
void judge(list * pt);
void lengthen(list * pt);
#endif