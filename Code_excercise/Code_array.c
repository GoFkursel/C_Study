#include <stdio.h>

int main_array(void)
{
    int arr[5][3];
    for (size_t i = 0; i < 5; i++)//size_t：unsigned int型
    {
        for (size_t j = 0; j < 3; j++)
        {
            scanf("%d\n",&arr[i][j]);//&：获取变量地址，在scanf中，将输入的值存入地址中
        }
        
    }
}
int main_chararray(void)
{
    char ch1[]="hello";
    char ch2[]="world";
    char ch3[20];

    int i=0,j=0;
    while (ch1[i]!='\0')
    {
        ch3[i]=ch1[i];
        i++;
    }
    while (ch2[j]!='\0')
    {
        ch3[i+j]=ch2[j];
        j++;
    }
    ch3[i+j+1]='\0';
    printf("%s",ch3);
    return 0;
}

int main(){
    char ch[]="hello world";
    //gets(ch);
    //fputs(ch,stdout);
    puts(ch);
    //printf("%s",ch);
    return 0;
}