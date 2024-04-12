# git & github
some suggestion
+ 什么是tag，以及版本号的规范
+ Git commit message编写规范
+ 集中修改提交记录的方法
+ 远程仓库与GitHub的本质
+ 如何自行探索git的奥秘
+ Github配置好邮箱
+ github issue 与pull request 的注意事项
+ 签署commit 的重要性
## 什么是git
+ 分布式版本控制系统
+ 分布式 不需要联网
git 模型
07：16
## git基础配置
+ 创建一个git仓库
+ 通过git init指令
+ git init 让当前文件夹变成git仓库
+ gt init floder 创建一个i虚拟的文件夹并初始化为git仓库
+ git账号配置
+ 全局配置
## 文件暂存
+ 暂存区：已经修改、等待后续提交的文件
+ 将文件加入暂存区
+ git add file/floder
+ 可以使用echo "hello" file.txt 用以创建一个新的文件
+ 删除文件的几种情况
+ 只在本地删除：rm
+ 同时删除git与本地中的文件：git rm
+ 将一个暂存的新文件取消暂存 git rm --cached name
+ 重命名文件 git mv
+ 查看现在暂存区状态 git status
+ 16：14 gitignore命令
## 提交更改
+ 将暂存内容提交到本地仓库，生成一个新版本
+ git commit 
+ git commit -m "message"//init commit
+ -a(--all)自动暂存所有文件
+ 查看提交历史 git log
+ --online 每一个提交一行
+ --graph显示分支结构
+ --stat显示文件删改信息
+ -p显示详细的修改内容
+ git show id（sha-1值）显示提交详细记录
+ git chekout sha-1值
### 关于commit message
+ 意义是什么：记录更改的原因/内容
+ Angular规范
+ <type>([scope]):<summary>
+ [body]
+ [footer]
+ type:更改类型（fix/feat/docs/refactor
+ scope：影响范围
+ summary：更改的简要描述 
+ body：详细描述
+ footer：解决issue了可以写fixes#id
+ 所以版本控制的版本呢
+ 轻量标签：git tag v0.01
+ 附注标签：git tag -a tag -m "message" id
+ git show v0.02
+ 31：00 版本号的命名规范
### detached head
+ 什么是HEAD：当前工作区在提交历史中的指针
+ 什么时detached HEAD：HEAD只想莫格历史提交，而不是莫格尔顿女孩子
+ 什么情形下会出现detached HEAD
+ git checkout id，此后的修改不会出现在任何分支
+ 切换回master后