创建一个heelo.cpp
```#include<stdio.h>
void PrintHello(){
    printf("hello\n");
}

创建一个test.cpp
#include<stdio.h>
void PrintHello()
int main(){
    PrintHello();
    return 0;
}
```
直接再vscode中无法进行编译
可以在cmd中进行多文件编译
g++ hello.cpp test.cpp -o hello.exe
可以把tasks.json中file改为*.cpp 或是hello.cpp 与 test.cpp