# 什么是shell
# 使用PowerShell
## Terminal
Terminal是窗口
Terminal用来获取输入，再给到shell，再shell处理再通过Terminal把其显现出来
shell是从Termianl获取指令，再给到内核去处理
### 什么才是shell
壳层 是用户与系统内核交互的界面

## 为什么要用命令行
+ 命令行是一种操作计算机的方式，理论上可以做任何事

# 基础的shell命令
## prompt
+ prompt命令的提示符，用来等待输入
+ 最重要的是当前路径，是当前shell所处的位置
+ 通常还有当前正在操作的用户
## 命令
+ pwd：输出当前所在路径的位置
+ cd path：切换路径
+ + path可以是相对路径或是绝对路径
+ - path中 ~ 代表home  . 代表当前路径   .. 代表上一层路径
+ 可以..\.. 回到上两层
### 文件/目录操作
+ ls ：列出当前路径下的文件和目录
+ -a：列出所有文件和目录
+ -l：列出详细信息
+ touch file：创建一个文件
+ mkdir dir：创建一个目录
+ rm file：删除一个文件
+ -r：递归删除文件
+ rmdir dir：删除一个空目录：rm -r dir删除目录下全部内容
+ cp src dst ： 复制文件或目录
+ cp test test1 即在test文件基础上增添了test文件
+ -r递归复制目录
+ mv src dst：移动文件或重命名
+ mv test1 test2 此为重命名
+ find path -name pattern：在path下查找文件名匹配pattern的文件
## 文件内容查看命令
+ cat file：输出文件内容
+ head -n lines file:输出文件前lines行
+ tail -n lines file：输出文件后lines行
+ more/less file：分页输出文件内容
+ 空格翻页，回车下一行，q退出
+ less功能更多，用法见less --help
## 其他命令
+ echo：输出字符串
+ echo hello
+ whoami：获取当前用户
+ date：获取当前时间
+ clear：清屏
+ ps：显示进程信息
+ kill：杀死进程
+ man：查看man文档
+ man printf
+ grep：查找文件内容(grep管道使用)
+ diff：比较稳健
+ ln：创建链接
+ whereis：查找命令所在位置
+ curl：发送http请求
+ wegt：下载文件
## 重定向
+ shell中三种流 stdin 标准输入 stdout标准输出 stderr标准错误
+ 通过>file将file重定向到文件，通过<file将文件重定向到stdin
+ 2>file将stderr重定向到文件
+ >>为追加模式，追加到文件末尾
+ 通过&>file将stdout说stderr重定向到文件
+ ex：./output >> stdout.txt
+ ./output 1>stdout.txt
+ echo "hello" > stdout.txt
+ 相当于将hello写入文件之中
+ cat input.cpp > stdout.txt
+ 将input.cpp复制进入stdout.txt
+ cat > stdout.txt
+ 输入什么就可写入stdout.txt
+ ctrl + d 结束输入将全部输入到stdout.txt中
+ diff input.cpp output.cpp > stdout.txt
+ ./a out < file 将文件作为程序的输入 不能使用a.out
+ 执行程序必须要使用./a.out
## 管道
+ 通过管道可以将一个命令的输出作为另一个命令的输入
+ 使用 | 操作符，将左侧stdout重定向到右侧stdin
+ 通过管道可以将多个命令连接起来，形成一个命令序列，通过一行命令来完成
+ 复杂文件看不懂，推荐explainshell
### 常用搭配
+ some command | tail -n lines 输出最后line行
+ some command | less分页输出
+ some command | grep pattern 在输出中查找匹配pattern的行
