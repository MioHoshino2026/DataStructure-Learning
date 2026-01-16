//链表H文件的函数功能实现
#include "list.h"
#include "fatal.h"
#include <stdlib.h>

//建立节点结构体
struct Node{
    double Element;  //节点存储数据, 以double类型为例
    Position Next;   //指向下一节点位置的指针
};

//测试链表是否为空表, 其中L是表头
int IsEmpty( List L ){
    return L->Next == NULL;
};

//测试当前位置是否是链表末尾
int IsLast( Position P, List L ){
    return P->Next == NULL;
}

//返回元素X在表中的位置, 即指向X第一次出现的节点的指针
Position Find( double X, List L ){
    Position P;

    P = L->Next;
    while ( P != NULL && P->Element != X ){
        P = P->Next;
    }
    return P;
}

//返回元素X在表中位置的前一项
Position FindPrevious( double X, List L ){
    Position P;

    P = L;
    while ( P->Next != NULL && P->Next->Element != X ){
        P = P->Next;
    }
    return P;
}

//删除元素X, 如果X出现多次则删除第一个, 如果没出现则什么也不做
void Delete( double X, List L ){
    Position P , Tmpcell;  //Tmpcell为临时指针, 使用完后释放
    P = FindPrevious(X, L);

    if ( !IsLast(P, L) ){
        Tmpcell = P->Next;
        P->Next = Tmpcell->Next;
        free( Tmpcell );
    }
}

//在位置P后插入元素X
void Insert( double X, List L, Position P ){
    Position Tmpcell;

    Tmpcell = malloc( sizeof( struct Node ));  //申请跟一个节点大小相同的内存
    if ( Tmpcell == NULL ){  //没有申请成功则报错
        FatalError( "Out of Space!!! ");
    }

    Tmpcell->Element = X;
    Tmpcell->Next = P->Next;
    P->Next = Tmpcell;
}

//删除整个链表并释放内存
void DeleteList( List L ){
    Position P, Tmpcell;

    P = L;
    while ( P != NULL ){
        Tmpcell = P->Next;
        free( P );
        P = Tmpcell;
    }
}

//创建新的空表,如果L已存在则先销毁旧表,然后创建新的头节点
List MakeEmpty( List L ){
    if ( L != NULL ){
        DeleteList( L );
    }

    L = malloc(sizeof( struct Node ));
    if ( L == NULL ){
        FatalError("Out of Space!!!");
    }
    L->Next = NULL;
    return L;
}

//返回头节点
Position Header( List L ){
    return L;
}

//返回第一个存储数据的节点
Position First( List L ){
    return L->Next;
}

//返回当前位置的下一个位置
Position Advance( Position P ){
    if ( P == NULL ){
        FatalError("Cannot Advance past NULL!!!");
    }
    return P->Next;
}

//返回当前节点所存储的数据
double Retrieve( Position P ){
    if ( P == NULL ){
        FatalError("Cannot Retrieve Element!!!");
    }
    return P->Element;
}