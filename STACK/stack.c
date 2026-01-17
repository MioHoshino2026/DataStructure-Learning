//基于链表建立栈结构
#include "stack.h"
#include "fatal.h"
#include <stdlib.h>

//建立栈节点
struct Node{
    double Element;
    PtrToNode Next;
};

//测试栈是否为空栈, 其中S是栈头
int IsEmpty( Stack S ){
    return S->Next == NULL;
}

//创建一个空栈, 如果栈S已存在则先销毁旧的栈
Stack CreateStack(){
    Stack S;

    S = malloc( sizeof(struct Node) );
    if ( S == NULL ){
        FatalError("Out of Space!!!");
    }
    S->Next = NULL;
    return S;
}
void MakeEmpty( Stack S ){
    if ( S == NULL ){
        FatalError("Must CreateStack First!!!");
    }
    else{
        while ( !IsEmpty(S) ) Pop(S);
    }
}

//从栈中弹出元素
void Pop( Stack S ){
    PtrToNode FirstCell;

    if( IsEmpty(S) ){
        FatalError("Empty Stack");
    }
    else{
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

//元素进栈, 将元素X推入栈中
void Push( double X, Stack S ){
    PtrToNode Tmpcell;

    Tmpcell = malloc( sizeof(struct Node) );
    if ( Tmpcell == NULL ){
        FatalError("Out of Space!!!");
    }
    Tmpcell->Element = X;
    Tmpcell->Next = S->Next;
    S->Next = Tmpcell;
}

//返回栈顶元素
double Top( Stack S ){
    if( IsEmpty(S) ){
        FatalError("Empty Stack");
    }
    return S->Next->Element;
}

//销毁整个栈
void DisposeStack( Stack S ){
    if ( S != NULL ){
        MakeEmpty(S);
    }
    free(S);
}