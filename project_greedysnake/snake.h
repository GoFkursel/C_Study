#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 60
#define HEIGHT 20

struct BODY{
    int X;
    int Y;
};
struct SNAKE
{
    int size;
    struct BODY body[WIDTH*HEIGHT];
}snake;

int food[2]={0};//food[0]为x坐标，[1]为y坐标

int dx=0;
int dy=0;
//记录蛇末尾坐标
int lx=0;
int ly=0;

void InitFood();
void InitSnake();
void ShowUI();
void PlayGames();
void InitWall();

#endif