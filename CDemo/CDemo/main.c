//
//  main.c
//  CDemo
//
//  Created by 郑佳 on 2020/4/14.
//  Copyright © 2020 TriangleDemo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



//typedef struct Student {
//    long number;
//    char name[10];
//    char sex[3]; // 由于汉字“男,女” 都是占2个字节, 在C语言中,字符数组安字符串处理,还有自动添加一个结束标记, 所以为3
//    int age;
//} StudentType;

//
//typedef StudentType DataType;
//
//#include "SeqList.h" //需要放在typedef下面


void SeqListDemo() {
//    SeqList myList;
//    int i, x;

//    ListInitiate(&myList);
//    for (i=0; i<10; i++) {
//        ListInsert(&myList, i, i+1);
//    }
//    ListDelete(&myList, 10, &x);
//    for (i=0; i<ListLenght(myList); i++) {
//        ListGet(&myList, i, &x);
//        printf("%d\t",x);
//    }
}


void SeqListDemo2() {
    
//    SeqList myList;
//    int i;
//    StudentType x[3] = {
//        {2001, "zhangsan", "男",20},
//        {2002, "lisi", "男",20},
//        {2003, "wangwu", "女",10}
//    };
//
//    StudentType stu;
//    ListInitiate(&myList);
//    ListInsert(&myList, 0, x[0]);
//    ListInsert(&myList, 1, x[1]);
//    ListInsert(&myList, 2, x[2]);
//
//    for (i=0; i< ListLenght(myList); i++) {
//        ListGet(&myList, i, &stu);
//        printf("%ld %s %s %d\n ", stu.number, stu.name, stu.sex, stu.age);
//    }
    
}

//#include "LinList.h"
//void LinListDemo() {
//    SLNode *head;
//    int i, x;
//    ListInitate(&head);
//    for (i=0; i<10; i++) {
//        ListInsert(head, i, i+1);
//    }
//    ListDelete(head, 10, &x);
//    for (i=0; i<ListLength(head); i++) {
//        ListGet(head, i, &x);
//        printf("%d\t",x);
//    }
//    Destory(&head);
//}



/*
 Demo: 优先级队列的应用
 操作系统中的进程管理 是优先级队列的一个应用实例, 操作系统中使用一个优先级队列来管理进程.
 每个进程由进程任务号和优先级值两部分组成, 进程任务号是每个不同进程的唯一标识, 优先级值通常是一个0-40的值, 规定0位优先级最高, 40位优先级最低.
 
 通常认为打印任务的执行队实时性要求不高, 所以打印任务的优先级定为40, 当队列中有若干个进程排队等待时, 进程管理就可根据其优先级值选择优先级最高的进程首先出队列, 从而达到了系统繁忙时, 所有进程都排队等待, 以及实时性要求高的进程 (即优先级高的进程) 先被服务的双重目标.
 
 */

#define MaxQueueSize 100
typedef int ElemType;
#include "PSeqQueue.h"

void OSTaskDemo() {
    
    PSeqQueue myPQueue;
    FILE *fp; // 文件指针
    DataType task;
    int i;
    
    if ((fp = fopen("task.dat", "r")) == NULL) {
        printf("open file faild");
        exit(0);
    }
    QueueInit(&myPQueue); // 初始化顺序优先级队列
    while (!feof(fp)) {
        // C 库函数 int fscanf(FILE *stream, const char *format, ...) 从流 stream 读取格式化输入
//        返回值
//        如果成功，该函数返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF。
        int scanrRes = fscanf(fp, "%d %d", &task.elem, &task.priority); // 读数据
        if (scanrRes > 0) {
            QueueAppend(&myPQueue, task);
        }
    }
    
    i = 1;
    printf("序列号\t任务号\t优先级\n");
    // 逐个出队并显示 (出队按照优先级由高到低 ,优先级相同的进程先到先服务)
    while(QueueNotEmpty(&myPQueue)) {
        QueueDelete(&myPQueue, &task);
        printf("%d \t\t",i);
        printf("%d \t\t",task.elem);
        printf("%d \t\t\n",task.priority);
        i++;
    }
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
//    LinListDemo();
    OSTaskDemo();
    return 0;
}

