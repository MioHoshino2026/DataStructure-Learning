#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueRecord{
    int Capacity;  //最大容量
    int Front;  //前端, 即出口
    int Rear;  //后端, 即入口, 初始为Front的前一位
    int Size;  //元素个数
    int* Array;
};

int IsEmpty( Queue Q ){
    return Q->Size == 0;
}

int IsFull( Queue Q ){
    return Q->Capacity == Q->Size;
}

Queue CreateQueue( int MaxElements ){
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if ( Q == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    Q->Array = malloc(sizeof(int)*Q->Capacity);
    if ( Q->Array == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    return Q;
}

void DisposeQueue( Queue Q ){
    if ( Q == NULL ){ }
    else{
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty( Queue Q ){
    Q->Size = 0;
    Q->Rear = 0;
    Q->Front = 1;
}

int succ( int Value, Queue Q ){
    if ( ++Value == Q->Capacity ) Value = 0;
    return Value;
}
void Enqueue( int X, Queue Q ){
    if (IsFull(Q)){
        printf("The Queue is Full.");
        exit(1);
    }
    else{
        Q->Size++;
        Q->Rear = succ( Q->Rear, Q );
        Q->Array[Q->Rear] = X;
    }
}

int Front( Queue Q ){
    return Q->Array[Q->Front];
}

void Dequeue( Queue Q ){
    if (IsEmpty(Q)){
        printf("The Queue is Empty.");
        exit(1);
    }
    else{
        Q->Size--;
        Q->Front = succ( Q->Front, Q );
    }
}

int FrontAndDequeue( Queue Q ){
    int ft = Q->Array[Q->Front];
    Dequeue(Q);
    return ft;
}