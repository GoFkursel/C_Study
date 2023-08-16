# Day13  
### 一、文件  
**文件打开**:FILE*,用一个指针变量指向文件，这个指针称为文件指针：FILE* fp=fopen("D:\\a.txt","rb/wb/ab/r+/w+/a+/rb+..."),文件打开，成功返回指针，失败返回NULL;//最多可以打开65535个文件  
**文件关闭**：fclose(fp)//不可以更改fp  
**字符读取**：ch=fgetc(fp)//文件默认结尾是-1，常用#define EOF （-1），用EOF判断  
**字符写入**：fputc(ch,fp)  
**文件加密解密**：md5算法  
**文件行读写**：（读取效率比字符读取高）fgets(),fputs(),逐行读写，会在读出内容后自动加一个\0，fgets(p,读的大小，fp),fputs(ch,fp)  
**判断是否到文件结尾**：feof(fp),如果到文件结尾，返回1，没到返回0  
**文件格式化读写**：（格式化读写）fprintf(fp,"%x",**a**),可以读到非16进制数停止；fscanf(fp,"%s/%3d",p),遇到空格或回车就停止，或者在读3个后停止，会根据格式来读写如fscanf(fp,"%d+%d=%d",**&a**,&b,&c)  
**对文件数据进行排序**  
>1. 冒泡排序，运行次数太多，太占内存；  
>2. 采用插入排序，即判断数据是否在某一区域内，然后让其出现次数+1（用在数 比较多的情况下）

//一些补充 
>scanf("%[^\n]",p);//除了换行符，其他都读入  
>getchar();//跟在前一句后面，用来接收换行符，从而继续输入   
>strcat(p,"\n");//后面追加一个换行符  

>sscanf(*str,*format)//str：函数检索数据的源  
>sprintf(*str,*format)//sprintf(str,"pi=%f",PI);puts(str)  

**文件块读写**：（用“wb/rb”来读写）fwrite(arr(地址),sizeof(int),数据多少，fp)，fread(arr,sizeof(int),数据多少,fp)//这里面的arr都相当于一个buffer，且读中的sizeof(int)*数据多少，只要满足整体大小，写成多少都可以
