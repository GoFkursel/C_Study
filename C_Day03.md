# Day03  | 数据类型
## 常量与变量
### 关键字
**C的关键字共有32个**  
char，  
short，int，long，整型  
float，double，浮点型分为，单精度，双精度  
unsigned，signed（平时可以不写），  
struct（结构类型），union（联合类型），enum（枚举类型），  
void（void *）可以传递任意类型  
**控制语句关键字（12个）**  
if else  
switch else default  
for  
do while  
break continue  
goto  
return 程序遇到return就结束了  
**存储类关键字**  
auto（一般情况不写，局部变量），  
extern（必须得声明，但是声明关键字可以不写），//用extern声明的时候，不会建立存储空间，但是定义时候会建立存储空间；  
register（有就存放，没有就不存放），  
static（静态函数），  
const（常量，只读变量）  
**其他关键字**  
sizeof（计算一种数据类型在内存占的大小）  
typedef（1）为一个已存在的数据定义类型；2）定义指针）  
volatile(防止编译器优化)  
**指针类型**  
char *：加一颗星表示一星指针  
int **：加两颗表示两星指针...以此类推  
**占位符**  
%f:默认保留6位小数，可以通过加".2"来保留2位小数，即"%.2f"，且会四舍五入（C++不会）  
## 一些例子  
const 数据类型 常量名 = 值 （C中不安全，C++中安全）：const int a;   
#define a 3.14(**没有分号！会被定义为分号**)  
auto： 在函数内部定义局部变量时加的，也可以不加  
标识符：1、不能使用系统关键字；2、只允许使用字母，下划线、数字，下划线、字母可以开头；3、取名有意义