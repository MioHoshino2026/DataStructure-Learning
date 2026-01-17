#include "stack.h"
#include "fatal.h"
#include <stdlib.h>

//定义栈数组结构
struct StackRecord{
    int Capacity;
    int TopOfStack;  //TopOfStack表示Stack目前Top位置, 不超过MaxElements--
    double* Array;
};

//给定数组大小并创建栈
Stack CreateStack( int MaxElements ){
    Stack S;

    S = malloc( sizeof( struct StackRecord ) );
    if ( S == NULL ){
        FatalError("Out of Space!!!");
    }
    S->Array = malloc( sizeof( double ) * MaxElements );
    if ( S->Array == NULL ){
        FatalError("Out of Space!!!");
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

//判断栈是否为空栈
int IsEmpty( Stack S ){
    return S->TopOfStack == -1;
}

//判断栈是否已满
int IsFull( Stack S ){
    return ( S->Capacity == S->TopOfStack + 1 );
}

//创建一个空栈
void MakeEmpty( Stack S ){
    S->TopOfStack = -1;
}

//释放栈的内存
void DisposeStack( Stack S ){
    if( S != NULL ){
        free( S->Array );
        free(S);
    }
}

//元素进栈
void Push( double X, Stack S ){
    if ( IsFull(S) ){
        FatalError("Full Stack");
    }
    else{
        S->Array[ ++S->TopOfStack ] = X;
    }
}

//返回栈顶元素
double Top( Stack S ){
    if ( !IsEmpty(S) ){
        return S->Array[S->TopOfStack];
    }
    else{
        FatalError("Empty Stack");
        return 0;
    }
}

//弹出栈顶元素
void Pop( Stack S ){
    if( IsEmpty(S) ){
        FatalError("Empty Stack");
    }
    else {
        S->Array[S->TopOfStack] = 0.0;
        S->TopOfStack--;
    }
}

//获取栈顶元素同时弹出
double TopAndPop( Stack S ){
    if ( IsEmpty(S) ){
        FatalError("Empty Stack");
        return 0;
    }
    else{
        double tmp = S->Array[S->TopOfStack];
        Pop(S);
        return tmp;
    }
}