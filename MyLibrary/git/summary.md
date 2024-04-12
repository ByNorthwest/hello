# 2、概述
## 2.1、开发中的实际场景
场景一：备份
场景二：代码还原
场景三：协同开发
场景四：追溯是问题代码的编写人和编写时间
## 2.2、版本控制工具
1. 集中式版本控制工具 ：必须要联网才能工作，个人修改后然后提交到中央版本库 举例SVN和CVS
2. 分布式版本控制工具：每个人你的电脑上都是一个完整那个的版本库，这样工作的时候，无需要联网，因为版本库就在你自己的电脑上，多人协作只需要各自的修改推送给对方，就能互相看到对方的修改了
3. 使用共享版本库来控制
## 2.2、git
> 简单的设计
> 兑现新开发模式的强力支持
> 完全分布式
> 有能力管理linux内核一样的超大规模的项目
## 2.5、git工作流程图
1. clone ：从远程仓库中科龙代码到本地仓库

# 3、 git安装
## 3.1 
+ git gul：图形工具
+ git bash：命令行工具
### 3.1.2 基本配置
2. 设置用户信息
 git config --global user.name
 git config --global user.email
上述指令可以查看自己的配置
## 3.2 获取本地仓库
> 要使用git对我们的代码进行版本控制，首先获取本地仓库
1. 在电脑任意一个位置创建一个空目录
2. 右键点击打开git bash窗口
3. git init
4. 创建成功共之后可以看见产生了一个git的隐藏文件
## 3.3 基础操作指令
### 提交操作与查看操作
git工作目录下对文件的修改会存在仓库、暂存区、工作区几个状态，这些修改状态会随着我们执行git 命令而发生变化
|仓库|暂存区|工作区|
|git commit|git add 以暂存|未暂存未跟踪|

> git status
> git add .
> git committ -m "file01"
> git log 查看日志
> vi file01.txt
> > i或是insert键进入编辑 esc 加上 ：wq退出并保存
1. 文件首先是从工作区加入到暂存区  git add .
2. 再是工作区从暂存区到本地仓库 git commmit -m "message"
### 3.3.1 git log 的扩展指令
> 命令形式
> 重命名了 既可以直接使用git-log使用
> > options:
> 1. ~all显示所有分支
> 2. ~pretty=oneline将提交信息显示为一行
> 3. ~abbrev-commmit 僵尸的输出的commitid更简短
> 4. ~graph 以图的形式显示
### 版本回退
+ 作用：版本回退
+ 命令：git reset --hard commitID
+ 复制双击即可，黏贴右键复制
+ 可以通过git reflog查看所有的版本 包括已经删除的操作  包括版本回退的操作
### 3.3.6 添加文件至忽略列表
一般我们总会有些五年间无需纳入git的管理，也不希望他们总出现在为跟踪文件列表，通常都是些自动生成的文件
我们剋在工作目录之中创建一个名为.gitignore的文件
示例
> #no .a file
> *.a
> #but do track lib.a even though you are ignoring .a files above
> !lib.a
> #only ignore th TODO file in the current director,not subdir/TODO
> /TODO
> #ignore all files in the build/director
> build/
> ignore doc/notes.txt but doc/server/atch/txt
> doc/*.txt
> ignore all .pdf files in the doc/director
> doc/**/*.pdf
## 3.4 分支
几乎所有的版本控制系统都以某种形式支持分支
分支就是使个人改个人的互不影响
1. git branch查看分支
2. git branch name 创建新的分支
3. git checkout name 切换分支
4. 我们还可以创建并且切换到一个分支命令为 git checkout -b name
5. 合并分支merge :git merge dev01(即为将dev01分支与现在HEAD指向的分支合并)
6. git branch -d name 删除分支
7. 删除分支前必须要先转移到其他分支
8. 当dev02未merge到其他分支上，进行删除时会error此时可以进行-D删除，强行删除
### 解决冲突
当两个分支上对文件的修改可能会存在冲突，例如同时修改了同一个文件的同一行，这时就需要手动解决冲突，解决冲突步骤如下
先是git merge dev再进行处理
1. 处理文件中冲突的部分
2. 将解决完冲突的文件加入暂存区
3. 提交到仓库
### 开发中分支使用的原则与流程
使用分支意味着你可以把你的工作从开发主线上分离开进行重大bug的修改、开发新的功能，以免影响开发主线
+ master（生产）分支
  线上分支、线上运行对应的分支
+ develop分支
  是从mastre创建的分支，一般作为开发部门的主要开发分支，阶段开发完成后，需要是合并到master分支准备上线
+ feature分支
  从develop创价的分支，同期并行开发，但不同期上线时创建的分支
+ hofix分支
  从master派生的分支，作为线上bug修复使用
  
#### 合并的快进模式
p15
# 4. Git远程仓库
## 4.1 常用的托管服务
gitee与github
## 4.4 配置ssh公钥
## 4.5配置远程仓库
1. 添加远程仓库
   命令：git remote add origin（name） 仓库路径（即ssh）
2. 查看远程仓库
   命令：git remote
3. 推送到远程仓库
   命令：git push origin master:master
   如果名字是一样的，则可以省略一个master
   [-f]表示强制覆盖(不用)
   --set-upstream 推送到远端的同时并且建立起和远端分支的关联关系
   git push --set-upsteram origin master
   如果当前分支已经和远端分支关联，则可以直接git push   
### 4.5.4本地分支与远程分支的关联关系
查看关联关系git branch -vv
### 4.5.5 克隆
如果已经有一个远端仓库，我们可以直接clone到本地
命令：git clone <仓库路径>[本地目录] 
git clone ssh。。 hellogit
直接在git bash所处的文件夹内生成一个名为hellogit的文件夹，里面的内容就是克隆远端的仓库
### 4.5.6 从远程仓库中抓取和储存
远程分支与本地分支一样，我们可以进行merge操作，只需要先把远端仓库里的更新下载到本地，在进行操作
+ 抓取 命令：git fetch [remote name][branch name]
  抓取命令就是将仓库里的更新都抓取到本地，不会惊醒合并
  如果不指定远端名称与分支名，则抓取所有分支
  fetch过来之后远端分支名在本地HEAD之上
  此时在进行一次merge操作进行快速合并才能使本地HEAD->master上移一位，并入远端分支的位置
  操作为一次fetch 与 一次merge
+ 拉取命令：git pull [remote name][branch name]
 **拉取命令就是将远端仓库的修改到本地并自动进行合并，等同于fetch + merge**
### 解决合并冲突
在一段时间内，A，B用户修改了同一个文件，且修改了同一个位置的代码，此时会发生合并冲突
A用户在本地修改代码优先推送到远程仓库，此时B用户在本地吸顶代码，提交到本地仓库后，也需要推送到远程仓库，此时B用户晚于A用户，**故需要先拉取远程仓库的提交，经过合并后才能推送到远端分支**
> 经验：为了避免远端的冲突，可以在每次提交之前先git pull一下在本地检测是否出现冲突，如果出现冲突，处理方式为
> vi file.txt进行你的修改
> git add .
> git commit -m "message"做完这一步已经完成了merge
> git-log检查已完成了merge
> 再进行git push提交到远端仓库上去


> 远程仓库练习
> 添加远程仓库：git remote add origin git@gitee.......git
> 将master分支推送到远程仓库，并绑定关系：git push --set-upstream srigin master
> 将远程仓库克隆到本地hellogit目录下: git clone git@gitee.....git hellogit
> 将本地修改推送到远程仓库修改了file03
> git add .
> git commit -m "message"
> git push origin master
> 将远程仓库的修改再拉去到本地
> git pull
> 显示提交记录git-log
> 查看到文件变化出现了file03的修改
# IDEA中使用git
# vscode与git
