#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "dict.h"
#define SIZE 3

typedef struct  DICT
{
    char* word;
    char* trans;
}dict;

dict* list=NULL;


int GetWord(){
    FILE* fp=fopen("D:/WJW_Study_log/C/project_translator/a.txt","r+");
    if(!fp){printf("调用失败\n"); return -1;}
    list=(dict*)malloc(sizeof(dict) * SIZE);
    int i=0;//数组下标
    char* temp=(char*)malloc(sizeof(char) * 1024);
    while(!feof(fp))
    {
        memset(temp,0,1024);
        fgets(temp,1024,fp);
        //格式化
        temp[strlen(temp)-1]=0;//去除\n
        //开辟单词堆空间
        list[i].word=(char*)malloc(sizeof(char) * strlen(temp));
        //将单词放进指定堆空间中
        strcpy(list[i].word,&temp[1]);

        memset(temp,0,1024);
        fgets(temp,1024,fp);
        temp[strlen(temp)-1]=0;


        list[i].trans=(char*)malloc(sizeof(char) * strlen(temp)-5);//去除#Trans
        strcpy(list[i].trans,temp);
        
        i++;
    }
    free(temp);
    fclose(fp);

    // for (int i=0;i<SIZE;i++)
    // {
    //     printf("list.word=%s\n",list[i].word);
    //     printf("list.trans=%s\n",list[i].trans);
    // }
    return i;
}

int SearchWord(char* word,char* trans){
    if(!word || !trans){
        printf("输入发生异常\n");
        return -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if(!strcmp(word,list[i].word)){//这两个比较的值相同，值返回0
            strcpy(trans,list[i].trans);
            return 0;
        }
    }
    return 1;
}

void DestroySpace(){
    if(list==NULL){
        return ;
    }
    for (int i = 0; i < SIZE; i++)
    {
        free(list[i].word);
        free(list[i].trans);
    }
    free(list);
    list=NULL;
    
}

int main(void){
    GetWord();
    char* word=(char*)malloc(sizeof(char)*1024);
    char* trans=(char*)malloc(sizeof(char)*1024);

    while(1){
        scanf("%s",word);

        if(!strcmp(word,"comm=exit")){
            break;
        }

        if(!SearchWord(word,trans))
            printf("%s",trans);
        else
            printf("未找到");
    }
    DestroySpace();
    system("pause");
    return 0;
}