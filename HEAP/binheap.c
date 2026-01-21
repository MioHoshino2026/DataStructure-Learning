//用数组实现二叉堆
#include "binheap.h"
#include "fatal.h"
#include <stdlib.h>

//用数组建立堆结构
struct HeapStruct{
    int Capacity;
    int Size;
    int* Elements;  //Elements为指向数组的指针
};

//初始化给定容量的堆结构
PriorityQueue Initialize( int MaxElements ){
    PriorityQueue H;

    H = malloc( sizeof( struct HeapStruct ));
    if ( H == NULL ){
        FatalError("Out of Space!!!");
    }

    H->Elements = malloc( sizeof( int ) * ( 1 + MaxElements ));
    if ( H->Elements == NULL ){
        FatalError("Out of Space!!!");
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = -1;  //在数组第一位预设一个比数组所有元素都小的值
    return H;
}

//清空与毁坏函数
void MakeEmpty( PriorityQueue H ){
    if ( H != NULL ){
        H->Size = 0;
    }
}
void Destroy( PriorityQueue H ){
    if ( H != NULL ){
        if ( H->Elements != NULL ){
            free( H->Elements );
        }
        free( H );
    }
}

//IsFull与IsEmpty函数
int IsFull( PriorityQueue H ){
    if( H == NULL ){
        FatalError("PriorityQueue is Empty");
    }
    else{
        return H->Size == H->Capacity;
    }
}
int IsEmpty( PriorityQueue H ){
    if( H == NULL ){
        FatalError("PriorityQueue is Empty");
    }
    else{
        return H->Size == 0;
    }
}

//插入操作: 上滤
void Insert( int X, PriorityQueue H ){
    int i;
    if( IsFull(H) ){
        FatalError("PriorityQueue is Full");
    }
    else{
        for ( i = ++H->Size; H->Elements[i/2] > X; i/=2 ){
            H->Elements[i] = H->Elements[i/2];
        }
        H->Elements[i] = X;
    }
}

//删除操作: 下滤
int DeleteMin( PriorityQueue H ){
    int i, child;
    int MinElement, LastElement;
    if ( H == NULL ){
        FatalError("PriorityQueue is Empty");
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for( i = 1; i*2 <= H->Size; i = child ){
        child = i*2;
        if(child!=H->Size&&H->Elements[child+1]<H->Elements[child]){
            child++;
        }
        if( LastElement > H->Elements[child] ){
            H->Elements[i] = H->Elements[child];
        }
        else{
            break;
        }
    }
    H->Elements[i] = LastElement;
    return MinElement;
}