# Day13  
### 一、联合体（Union）#同一时间只有最后一次被赋值的值是有效的;#联合体的大小是其最大成员的长度的倍数  
**定义**：union Var{int a,float b,char d,short d};  
**使用**：union Var var; var.a=10;var.b=2;//其中只有var.b有值  
### 二、枚举  
**定义**：enum Color{red,green,blue,white}color;//这里的red从0开始，也可以手动赋值，使red=10，这样后面的都会依次加1  
**使用**：enum Color color；switch(color){case red...break;case green...break}  
### 三、typedef（关键字）  
**使用**：typedef unsigned int ui；ui a=10；  
**用途**：1. 为已经存在的数据类型起别名；2.定义函数指针  
**定义结构体**：  
>typedef struct stu{  
>int age;...    
>}ss;//由于前面加了typedef，这里的ss是struct stu的别名，如果不加typedef，这里的ss只能是一个结构体变量名
