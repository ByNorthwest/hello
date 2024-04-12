# 程序编译与调试技术
> 程序设计语言只是计算机的很小的一部分
> 其本质使编译原理、操作系统和计算机体系结构
> 推荐书籍：《计算机科学导论》
> 《深入理解计算机系统》
## 程序编译过程
1. 预处理
2. 汇编
3. 编译
4. 链接

gcc hello.c -o hello在shell中对hello.c进行编译
./hello输出hello
看编译过程 gcc hello.c -o hello -v
多文件编程同理 gcc main.c sum.c -o prog
即多文件编程为prog程序
### 预处理过程：cpp hello.c > hello.i
  + 此时为处理宏与头文件
  + 用双引号#include""包含的头文件，编译器会在当前目录下查找，再再系统目录下查找
  + 用尖括号#include<>包含的头文件，编译器只会在系统目录下查找
### 编译过程gcc -S hello.i
+  cat hello.s
  + 错误：编译器无法继续进行比那一。比如：提供给的参数列表不匹配、使用了未定义的变量函数等
  + 警告warning：违反了语法，但能够继续编译，可能发生隐式转换
    + 大部分警告信息默认不会输出，使用-Wall和-Wextra选项可以打开更多的警告信息
    + 编译时 gcc -Wall -Werror -0 hello hello.c
### 汇编
产生**可重定位目标文件**
as -o hello.o hello.c
./hello.o 终端会告诉你这个文件不能被系统运行
+ 库函数：所有c程序会用到标准库中的函数。标准库中的代码已经被预编译成目标文件，附在编译器的安装目录之下
### 链接
动态链接与静态链接
.dll 就是动态链接库

## 程序调试过程
### bug的类型
1. 编译时错误
2. 运行时错误
3. 逻辑错误和语义错误
> 为什么有感觉调试的过程十分煎熬
>  c语言基础知识不牢：不开-Wall与-Werror编译出来很多坑，如隐式类型转换
> 没有事先想好程序的逻辑（现在智商想好程序的逻辑）
> 不了解基本的调试技术
```c
char *gets(char *s){
    int c;
    char *dest = s;
    while((c =getchar())!='\n' && c !=EOF){
        *dest ++ =c;
    
    }
    if (c==&&dest ==s)
        return NULL;
    *dest++ ='\0';
    return s;
}
```
在编译时加入源代码的信息
gcc -g -o gets gets.c
### gdb的基本使用
file gets
r
b 8 断点
print dest
next 
step
continue
具体的更多命令去网上查找gdb调试
