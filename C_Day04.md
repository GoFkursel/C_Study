# Day04
## 占位符使用操作
### 1. scanf()函数
tips：scanf()安全问题解决，&取值符号  
**在VS里面使用scanf()函数很有可能报错**  
为了避免报错，我们使用提前定义宏定义**井号define _CRT_SECURE_NO_WARNINGS**或者**井号pragma warning(disable:4996)**  
### 2. sizeof 关键字 及 short等约束范围 （整型）  
**定义**：sizeof不是函数，所以不需要包含任何头文件，它的功能是计算一个数据类型的大小，单位为字节；  
**性质**：sizeof的返回值为size_t；size_类型在32位操作系统下是unsigned int，也就是无符号整数
  
**short**：短整型 short a; **占位符**：%hd   
**long**：长整型 long a;**占位符**：%ld  
**long long**：长长整型**占位符**：%lld