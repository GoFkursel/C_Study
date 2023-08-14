#include<stdio.h>

void my_strcpy(char* dest,char* ch){
    int i=0;
    while(ch[i]!='\0'){
        dest[i]=ch[i];
        i++;
    }
    dest[i]=0;
}

int main(){
    char dest[100];
    char ch[]="hello world";
    my_strcpy((char*)dest,(char*)ch);
    printf("%s\n",dest);
    return 0; 
}