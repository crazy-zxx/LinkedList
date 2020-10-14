//
// Created by xylx on 2020/10/14.
//

#ifndef SQLIST_COMMONDEFINE_H
#define SQLIST_COMMONDEFINE_H


/* ----------- 常用返回值预定义 --------------*/
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/*-----------------------------------------*/


/* ----------- 单链表结构定义 ---------------*/
//元素类型
typedef int ElemType;
//单链表节点
typedef struct lNode {
    ElemType data;
    struct lNode *next;
} LNode, *LinkedList;
/*-----------------------------------------*/



#endif //SQLIST_COMMONDEFINE_H
