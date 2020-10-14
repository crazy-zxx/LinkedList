#include <stdio.h>
#include <stdlib.h>
#include "commonDefine.h"
#include <iostream>

using namespace std;

/*-------------- 尾插法构造单链表 ---------------*/
void CreateListByTail_L(LinkedList &L) {
    //创建头结点,r始终指向尾结点
    LinkedList r = L = (LinkedList) malloc(sizeof(LNode));
    r->next = NULL;
    int n;
    printf("input nodes number：");
    scanf("%d", &n);
    printf("input %d nodes number：", n);
    //创建数据节点
    for (int i = 1; i <= n; ++i) {
        LinkedList p = (LinkedList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = NULL;
        //尾插
        r->next = p;
        r = p;
    }
}

/*-------------- 头插法构造单链表 ---------------*/
void CreateListByHead_L(LinkedList &L) {
    //创建头结点
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    int n;
    printf("input nodes number：");
    scanf("%d", &n);
    printf("input %d nodes value：", n);
    //创建数据节点
    for (int i = 1; i <= n; ++i) {
        LinkedList p = (LinkedList) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        //头插
        p->next = L->next;
        L->next = p;
    }
}

/*-------------- 获得单链表第i个元素 ---------------*/
Status GetElem_L(LinkedList L, int i, ElemType &e) {
    LinkedList p = L->next;     //首结点
    int j = 1;
    while (p && j < i) {        //查找第i个元素
        p = p->next;
        j++;
    }
    if (!p || j > i) {          //查找失败
        return ERROR;
    }
    //查找成功返回值
    e = p->data;

    return OK;
}

/*-------------- 单链表在第i个位置插入元素 ---------------*/
Status ListInsert_L(LinkedList &L, int i, ElemType &e) {
    //p要从头结点开始，否则无法插入第一个位置的元素
    LinkedList p = L;
    int j = 0;
    while (p && j < i - 1) {    //查找插入位置的前驱（第i-1个元素）
        p = p->next;
        j++;
    }
    if (!p || j > i) {          //插入位置不合法
        return ERROR;
    }
    //插入
    LinkedList s = (LinkedList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

/*-------------- 单链表删除在第i个位置的元素 ---------------*/
Status ListDelete_L(LinkedList &L, int i, ElemType &e) {
    //p要从头结点开始，否则无法删除第一个位置的元素
    LinkedList p = L;
    int j = 0;
    while (p && j < i - 1) {    //查找插入位置的前驱（第i-1个元素）
        p = p->next;
        j++;
    }
    if (!p || j > i) {          //插入位置不合法
        return ERROR;
    }
    //删除
    LinkedList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return OK;
}

/*-------------- 归并两个单链表(非递减有序，新建结点，保留相同值) ---------------*/
void MergeListNewNode(LinkedList &La, LinkedList &Lb, LinkedList &Lc) {
    //pa、pb分别指向La、Lb首结点,pc、Lc指向新建的头结点
    LinkedList pa = La->next, pb = Lb->next, pc = Lc = (LinkedList) malloc(sizeof(LNode)), temp;
    while (pa && pb) {
        temp = (LinkedList) malloc(sizeof(LNode));
        if (pa->data <= pb->data) {
//            if (pa->data==pb->data){    //去除重复结点（仅去除两链表相互之间重复的结点）
//                pb=pb->next;
//            }
            temp->data = pa->data;
            temp->next = NULL;
            pc->next = temp;
            pc = temp;
            pa = pa->next;
        } else {
            temp->data = pb->data;
            temp->next = NULL;
            pc->next = temp;
            pc = temp;
            pb = pb->next;
        }
    }
    if (pb) {
        pa = pb;
    }
    while (pa) {
        temp = (LinkedList) malloc(sizeof(LNode));
        temp->data = pa->data;
        temp->next = NULL;
        pc->next = temp;
        pc = temp;
        pa = pa->next;
    }
}

/*-------------- 归并两个单链表(非递减有序，使用原有结点，保留相同值) ---------------*/
void MergeList(LinkedList &La, LinkedList &Lb, LinkedList &Lc) {
    //pa、pb分别指向La、Lb首结点,pc指向La
    LinkedList pa = La->next, pb = Lb->next, pc = Lc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
//            if (pa->data == pb->data) {   //去除重复结点（仅去除两链表相互之间重复的结点）
//                LinkedList q = pb;
//                pb = pb->next;
//                free(q);
//            }
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);

}

/*-------------- 输出单链表 ---------------*/
void printList(LinkedList L) {
    if (L) {
        LinkedList p = L->next;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
    }
    printf("\n");
}

/*-------------- 单链表去重 -----------------*/
//从第一个结点开始遍历每个结点，删除其后重复结点
void TrimList(LinkedList &L) {
    LinkedList p = L->next;

    //从第一个结点开始遍历每个结点
    while (p) {
        LinkedList q = p;
        while (q->next) {
            //其后存在重复结点
            if (q->next->data == p->data) {
                //删除结点
                LinkedList temp = q->next;
                q->next=temp->next;
                free(temp);
            } else{
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main() {

    LinkedList La, Lb, Lc;
    CreateListByHead_L(La);
    //CreateListByTail_L(Lb);
    printList(La);
    //printList(Lb);
    TrimList(La);
    printList(La);
    //MergeList(La,Lb,Lc);
    //MergeListNewNode(La, Lb, Lc);
    //printList(Lc);

    return 0;
}
