# Day12 Linux中一个汉字占3个字节，Windows中一个汉字占2个字节 
### 一、结构体  
**1. 定义**：struct 结构体名字{ 结构体成员列表 }；  
>struct MyStruct{  
    char name[21];  
    int age;   
    char addr[51];  
    };stu1={值1，值2...}//这里的stu1是**全局变量**  

**2. 创建结构体变量**：struct 结构体名字 结构体变量名 | struct 结构体名字 结构体变量名={值1，值2，值3...};   
**3. 使用**：结构体变量名.成员=...//如果成员是数组，则不能直接这样赋值，可以通过下标一个一个赋值，或者拷贝函数，因为数组名是一个常量，记录着数组开始的首字母  
>struct MyStruct stu[3]={  
    {值1，值2，...}，  
    {值n，值n+1...},  
    {值...}  
};  

**4. 从键盘接收时**：需要注意数组本身就是地址，因此，如果成员类型是变量类型，则需要加取址符：scanf("%s%d",stu.name,&stu.age)  
**5. 结构体大小**：成员类型不一样时，结构体成员需要偏移，也就是一定等于4的倍数，所以显示的数据一定会大于实际的数据  
### 二、结构体排序及开辟堆空间存储结构体  
struct student* p=(struct student*)malloc(sizeof(struct student)*3)//把struct student看作int，且struct student *的大小是4  
### 三、结构体嵌套结构体  
>struct 人物信息{ 力量，智力，敏捷，struct skills[4]/struct skills sk}  
>struct skills{名称，属性...}  
>sizeof(人物信息)/sizeof(人物信息.sk)/sizeof(人物信息.力量)  
### 四、结构体赋值  
>struct student stu={值1....}  
>struct student stu1 = stu  
>stu1.name=值2//完全不影响，stu和stu1是独立空间（深拷贝和浅拷贝问题）  
### 五、结构体指针  
1. 分配堆空间  
>struct student{char* name}  
>struct student stu  
>stu.name=(char*)malloc(sizeof(char)*21)
2. 结构体指针  
>struct student stu={值1};  
>struct student *p=&stu;  
>printf("%d\n"，p->name);//或者(*p).name  

>struct student{ char* name}  
>struct student stu={值1....}  
>struct student stu1 = stu  
>stu1.name=(char*)malloc(sizeof(char)*10);  
>strcpy(stu1.name,"wjw")//这里面的name会改变，就算赋给别的变量也会改变，因为把结构体赋给的stu1，里面的name是一个地址  