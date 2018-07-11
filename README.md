# Dynamic-memory-allocation
## 计算机操作系统 课程作业 By NUAA(引用了交作业的路过的给个❤支持一下呗)
计算机操作系统-动态内存分配

### 1.首次适应算法(first fit,FF)
空闲分区以地址递增的次序链接，分配:从链首开始顺序查找，找到后，按照作业大小，从该分区中划出一块内存空间分配给请求者，余下的空闲分区仍留在空闲链中。
### 2.循环首次适应算法(next fit,NF)
是FF的改进。从上次找到的空闲分区的下一个开始查找.
### 3.最佳适应算法(best fit,BF)
空闲分区按其大小以递增的顺序链接。顺链找第一个满足要求的空闲区.链首留碎片,尾留大块,查找大块慢.
### 4.最坏适应算法(worst fit,WF)
空闲分区按其大小以递减的顺序链接。顺链找第一个满足要求的空闲区.链首留碎片,尾留大块,查找大块慢.

## HOW TO USE
### 1.输入总内存大小
数字，有正确性检验，建议在20左右视觉效果会比较良好
### 2.选择分配策略
数字，有正确性检验，范围为1-4
***
[这里在窗口顶端会显示已选择的信息和输入的信息]
***
### 3.选择所要执行的操作
数字，有正确性检验，范围1-3
```
    1-申请内存
    2-释放内存
    3-退出程序
```
### 4.选择对应的功能后
```
    1-输入程序进程号(进程号不能存在)以及申请的空间
    2-输入需要释放的程序进程号(程序号需要存在)
    3-直接退出程序
```
### 5.下一步
后台检验用户输入并执行后，返回执行结果，并且将现在内存分配的状况显示输出给用户，并等待用户下一次输入。如果执行出错，返回输出错误原因。
