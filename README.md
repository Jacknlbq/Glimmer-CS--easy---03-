# CS-EASY-03 内存模型
***
## 心得
这一小节的内容是真的丰富，查了好半天的资料，读着那些闻所未闻的术语时确实是枯燥的。简直就是“那些字分开都认识，连一起就认不出来了”的感觉。尤其是那个<u>**动态链接**</u>,我现在都是有点昏。不过在了解到一些日常经常听得到的东西（CPU，缓存）的工作原理时，那种知识回到生活的感觉还是很美妙的。
***
## 导学题
1. ***什么是“栈溢出”？***
    >栈溢出是指输入的字节超过了最开始申请的变量空间时，影响到其他相邻栈中的变量的值。
2. ***堆区和栈区的区别是什么？***
    >**存储**:堆区存储地址小，且是向上增长。而栈区存储地址大，且是向下增长
    >**使用方式**：堆区需要程序员手动分配并释放，而栈区是系统自动分配。
    >**速度**：栈区更快。
3. ***程序运行过程中，内存模型当中的哪些区是只读的，哪些区是可读写的？***    
    >**只读**：常量区，代码区。
    >**可读写**：全局数据区，堆区，栈区。
4. ***如何使用malloc()、free()函数，它们针对的哪一个区进行操作？***
    >**`malloc()`**:括号里为申请变量的大小，一般可配合`sizeof()`使用。函数本身返回的是地址，可用类型转换将其转换为对应类型的指针。如`* p=(Node*)malloc(sizeof(Node));`其中**Node**为一个变量类型。
    >**`free()`**:括号里为需要释放的内存的地址，一般为一个指针。
5. ***为什么要对程序使用的内存进行管理？***
    >不同分区的**访问读写速度**是不同的，对内存进行管理可以使程序更优。
    >避免不同程序之间出现内存泄漏和冲突。
***
## 应用题
* constValue:**常量区**中，因为定义时使用了const关键字且是在函数外声明的。
* constString:**全局数据区的data段**。首先可以通过更改代码，尝试给其赋值，而系统并没有报错，说明其肯定是变量，而且他是定义在函数外的说明应该在全局数据区。又因为它在被声明时是被初始化了的，所以在data段。这里也可以看出const并没有作用于其，应该是作用于那串字符串字面量了。
* globalVar:**全局数据区的data段**。定义在函数外且被初始化
* staticVar::**全局数据区的data段**。关键字static且被初始化。
* localVar:**堆栈**。定义在子函数中的变量，如果不在栈区，假如其他函数中有同名变量，就会出现冲突。
* ptr:**栈区**。整形且是一个声明在子函数中的变量，理由与上者相同，虽然其赋值式中有malloc函数，但这只意味着其本身是一个指向堆区的指针变量，而不代表其在堆区。
* localVarMain:**堆栈**。理由同localVar。
***
## Cache
1. 什么是冯诺伊曼体系结构？什么是现代计算机的组织结构？这两者的不同点在哪里？  
    >冯诺依曼体系结构：IO设备，运算器，存储器层次结构，控制器，总线，
    >现代计算机的组织结构：CPU，存储器层次结构，IO设备，总线系统。
    >不同点
    >>核心：分别是以运算器和存储器为核心。
    总线：冯诺依曼结构采用单一总线，而现代结构采用总线系统。
    现代计算机的运算器和控制器被合并在CPU上。
2. 主存储器是如何工作的？
    >主存储器的是由若干存储单元构成，每个单元一个字节，同时每个单元都还有一个编号(地址)。于是就可通过按储存单元的地址进行存取。
3. 什么是Cache的局部性原理？它包括哪些方面的内容？
    >高速缓存的局部性原理是指**缓存将最近的未来可能会用的信息存入缓存中**
    包括**时间局部性**和**空间局部性**，其中空间局部性在对二维数组的一个遍历即可体现（顺序和逆序的对比）
4. Cache的运用为什么可以加快系统整体性能？
    >首先，随机存储器分为DRAM和SRAM。其中DRAM的访问速度比SRAM要慢，但DRAM更便宜。（就是那啥好的更贵）。而主存又较大，所以一般采用DRAM。但这样就会使速度变慢。于是就可以在两级之间加一个SRAM，来做中继，利用缓存的局部性，使得CPU可以更多访问更快的SRAM。当然缓存也有很多级，不过上级对下级都类似于此。
***    