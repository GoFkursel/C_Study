#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "snake.h"

/*
    1. 定义蛇结构体
    2. 初始化蛇和食物
    3. 开始游戏
        蛇和墙的碰撞
        蛇和自身的碰撞
        蛇和食物的碰撞
            重新随机食物
            蛇身体增长
            分数增长
        方向键的控制
    4. 游戏结束
*/

void InitFood(){
    food[0]=rand()%WIDTH+1;
    food[1]=rand()%HEIGHT+1;

}
void InitSnake(){
    snake.size=2;
    snake.body[0].X=WIDTH/2;
    snake.body[0].Y=HEIGHT/2;

    snake.body[1].X=WIDTH/2-1;
    snake.body[1].Y=HEIGHT/2;
}

void ShowUI(){
    COORD coord;
    //显示蛇的位置
    coord.X = lx;
    coord.Y = ly;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    putchar(' ');
    for (int i = 0; i < snake.size; i++)
    {
        coord.X = snake.body[i].X;
        coord.Y = snake.body[i].Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//#include<windows.h>库里的，用于win32直接控制控制台光标位置
        if(i==0)
            putchar('@');
        else
            putchar('*');
    }
    

    //显示食物位置
    coord.X=food[0];
    coord.Y=food[1];
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    putchar('#');
}

void PlayGames(){
    char key ='D';
    while(snake.body[0].X>=0 && snake.body[0].X<WIDTH 
    && snake.body[0].Y>=0 && snake.body[0].Y<HEIGHT){
    //显示界面
        ShowUI();
    //方向控制
    while(_kbhit()){//检测键盘返回状态，有输入返回1，无输入返回0
        key = _getch();//#include<conio.h>从控制台无回显的取回一个字符，没有输入不向下走
         }
        switch (key)
        {
        case 'D':case 'd':  dx=1; dy=0;             break;
        case 'A':case 'a':  dx=-1; dy=0;             break;
        case 'W':case 'w':  dx=0; dy=-1;             break;
        case 'S':case 's':  dx=0; dy=1;             break;
        default:
            break;
        }
    //是否和自身碰撞
    for (int i = 1; i < snake.size; i++)
    {
        if(snake.body[0].X==snake.body[i].X && snake.body[0].Y==snake.body[i].Y)
        return;
    }
    if(snake.body[0].X==food[0] && snake.body[0].Y==food[1]){
        //随机新食物
        InitFood();
        //蛇身体增长
        snake.size++;
        //分数增长
        //关卡 速度 障碍物
        }
    //蛇更新坐标
    lx=snake.body[snake.size-1].X;
    ly=snake.body[snake.size-1].Y;
    for (int i = snake.size-1; i >0 ; i--)//从后向前赋值
    {  
        snake.body[i].X=snake.body[i-1].X;
        snake.body[i].Y=snake.body[i-1].Y;
    }
    //更新蛇头
    snake.body[0].X += dx;
    snake.body[0].Y += dy;

    Sleep(500);//用来控制速度
    //system("cls");//用来更新屏幕显示的内容，清空并重新绘制
    
    }
}

void InitWall(){
    for (int i = 0; i <= HEIGHT; i++)
    {
        for (int j = 0; j <= WIDTH; j++)
        {
            if(i ==HEIGHT-1)
                putchar('&');
            else if(j==WIDTH)
                putchar('&');
            else
                putchar(' ');
            
        }
        putchar('\n');
        
    }
    
}


int main(){
    srand((size_t)time(NULL));

    //使控制台光标消失
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=sizeof(cci);
    cci.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);//这里第二个参数是一个指针类型，因此需要传递地址
    InitWall();
    InitFood();
    InitSnake();
    PlayGames();

    getchar();
    
    return 0;
}