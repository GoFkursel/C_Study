/*
 *
 */
#include<stdio.h>

int main()
{
    //有符号数 signed int ... 无符号数 unsigned int(如果是无符号数，定义时候必须是一个正数，
    //否则使用占位符%u时会出来一个不想要的乱数,但如果占位符是%d就可以正常输出)
    // %d %o %x %X %u
    //八进制数：以0开头
    //十六进制数：以0x开头
    int a;
    scanf("%d",&a);//从键盘中获得值
    printf("%d",a);
    return 0;
}