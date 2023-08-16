#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char* argv[])//argc:参数个数，argv：参数的具体内容
{
    //argv[1]是输入参数的第二个参数名
    struct stat st;//获得文件的属性
    stat("D:/l.txt",&st);
    printf("%d",st.st_atime);
    
    return 0;
}