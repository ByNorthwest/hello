# 1. 操作系统
> 系统调用
用户
应用程序
系统调用 终端命令 图形窗口
操作系统(用来调用计算机硬件)
计算机硬件
CPU 内存 硬盘 声卡
>  查找歌曲点击播放
> 将歌曲从硬盘加载到内存
> 使用声卡对音视频数据进行解码
> 将解码后的数据发送给音箱
没有安装操作系统的计算机、通常被称为裸机
## 2. 服务器操作系统
+ Linux
  + 安全稳定免费
  + 占有率高
+ Windindows
  + 付费
  + 占有率低
+ 使用python开发web时服务器必须选用Linux的

# Linux相关
> 先know how再know why
> 先知道怎么操作， 通过后面的项目可以加深前面的理解
> 学会查询互联网
> 计算机在项目的过程中学会而不是先学会在做
> 适当的囫囵吞枣
> Linux 实用指令必须完全掌握
>
# 黑马Linux 从p1到p10是Liux的环境配置
# 虚拟机快照
保存状态
# Linux目录结构
Linux的目录结构是一个树形结构
Linux只有一个更目录/，所有文件都在它下面
# linux命令基础
+ 命令本身  可选选项  参数
## ls命令
ls [-a -l -h][linux路径]
+ -a -l -h是可选的选型
+ linux路径是参数
+ ls -a
  + 表示列出全部文件（包括隐藏的文件与文件夹）
+ ls -l
  + 以列表竖向排序的形式展示内容
+ ls -h
+ 可以ls -a-l /  /指定了根目录
+ ld
+ ls -al
+ ls -h
  + 以易于阅读的形式展示文件的大小
  + 必须与-lh配合使用
## cd命令
cd 为 change director
cd [linux路径]
cd无路径 即返回到根目录HOME
## pwd命令
print work director
显示当前目录
> 绝对路径：以根路径为起点，描述路径的一种写法，路径描述以/为开头
> 相对路径：无需以/为起点
现在，向上回退一级
+ . 表示点当前目录，比如cd ./Desktop 表示切换到当前目录下的Desktop，等于cd Desktop
+ .. 表示上一级目录，比如cd .. 即可切换回上一级目录
+ ~表示HOME目录，比如cd ~即可切换到HOME目录，可以cd ~/Deaktop
## mkdir命令
make director
mkdir [-p] linux路径
参数必填，表示linux路径，即要创建的文件夹的路径，相对路径或绝对路径均可
-p 选项可选，表示自动创建不存在的父目录，是用于创建多层级的目录
> 只能在根目录的home文件夹之中
> 不能除了根目录的home之外
# 文件操作命令
## touch linux路径
相对 绝对路径均可
## cat命令
查看文件内容
cat linux路径
## more linux路径
more支持翻页查看文件
空格进行翻页
q进行退出
## cp命令
用于复制文件与文件夹
有-r选项，用于复制文件夹使用
> cp text.txt test2.txt
文件的复制
> cp -r itheima itheima2
用于文件夹的复制
## mv命令
完成文件/文件夹的移动
mv 参数1 参数2
> mv test.txt Desktop/  这是使test.txt一如Desktop文件夹中
> mv test2.txt test3.txt
可以有改名的效果
移动文件夹
> mv top Dektop/
## rm用于文件与文件夹的删除
rm [-r -f] 参数1 参数2 参数N
-r用于删除文件夹
> rm命令支持通配符*，用来做模糊处理
> 符号* 表示通配符，及匹配任意内容
> test*表示匹配任意以test开始的内容
> *test以test结束的内容
> *test*包含的test内容
## whilch命令
这些linux命令，其实他的本体就是一个个的二进制的可执行的程序
可以通过which，查看所使用的命令
which 要查找的命令
## find命令
find 其实命令 -name “被查找文件名”
find / -name "test"
find 可使用通配符*
### find按文件大小查找文件
find 其实路径 -size +|- [kmg]
+ 查找小于10kb的文件 find / -size -10k
+ 大于100mb的文件 find / -size +100M
+ 大于1GB的文件 find / -size +1G
## 管道符 grep wc
## grep
通过grep，从文件中通过关键字过滤文件行
grep [-n]  关键字 文件路径
+ 选项-n 表示在结果中显示匹配的行的行号
+ grep -n "code" test.txt
+ 文件路径不填的话，可作为内容输入端口
## wc 命令
+ 选项 -c 统计bytes数量
+ 选项 -m 统计字符数量
+ -l 统计行数
+ -w 统计单词数量
+ 参数 我呢见路径，被统计的文件
wc test.txt
## 管道
带上  |  以前面的输出作为后面的输入
cat test.txt | grep itheima  
ls | grep test
ls | wc -l
cat test.txt | grep itcast | gre itheima

## 重定向符
echo 输出的内容
echo hello linux
> 反引号`  echo 输出反引号之中的内容
> echo `pwd`
## 重定向符
> 将左侧的结果，覆盖写入到符号右侧文件中
>> 致谢写入到右侧文件
## tail 命令
tail [-f -num] linux路径
查看文件尾部内容，并可以持续跟踪
+ 参数linux路径，表示之宗的文件路径
+ 选项-f表示持续跟踪
+ -num表示查找照尾部多少行
# vi编辑器
使用vi/vim编辑器
三种工作模式
1. 命令模式
  命令模式下索桥的案件编辑器都理解为梦灵，
  此模式下不能自由的进行文本编辑
2. 输入模式
  编辑模式、插入模式
3. 底线命令模式
  用于文件的保存与推出

