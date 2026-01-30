#include "heappair.h"
#include <stdlib.h>
#include <stdio.h>

struct Nodel{
    int Rank;  //记录Node的编号
    int Element;
    Position Prev;  //指向上一位父节点或左兄弟节点的指针
    Position LeftChild;
    Position NextSibling;
};

Position CreateNodel( int rank, int Element ){
    Position P;
    P = malloc(sizeof(struct Nodel));
    if ( P == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    P->Rank = rank;
    P->Element = Element;
    P->Prev = NULL;
    P->NextSibling = NULL;
    P->LeftChild = NULL;
    return P;
}

//合并子堆, 其中First堆不允许有NextSibling, 而对Second堆无限制
PairHeap Merge( PairHeap First, PairHeap Second ){
    if ( Second == NULL ){
        return First;
    }
    else if ( First->Element <= Second->Element ){
        Second->Prev = First;
        First->NextSibling = Second->NextSibling;
        if( First->NextSibling != NULL ){
            First->NextSibling->Prev = First;
        }
        Second->NextSibling = First->LeftChild;
        if ( Second->NextSibling != NULL ){
            Second->NextSibling->Prev = Second;
        }
        First->LeftChild = Second;
        return First;
    }
    else{
        Second->Prev = First->Prev;
        First->Prev = Second;
        First->NextSibling = Second->LeftChild;
        if ( First->NextSibling != NULL ){
            First->NextSibling->Prev = First;
        }
        Second->LeftChild = First;
        return Second;
    }
}

PairHeap Insertl( int rank, int Item, Position P, PairHeap H ){
    Position NewNode = CreateNodel(rank, Item);
    if (P != NULL) P = NewNode;
    if ( H == NULL ) return NewNode;
    return Merge(H, NewNode);
}

PairHeap DecreaseKey( Position P, int Delta, PairHeap H ){
    if ( Delta < 0 ){
        printf("DecreaseKey called with negative Delta.");
        exit(1);
    }
    P->Element -= Delta;
    if ( P == H ){
        return H;
    }
    if ( P->NextSibling != NULL ){
        P->NextSibling->Prev = P->Prev;
    }
    if ( P->Prev->LeftChild == P ){
        P->Prev->LeftChild = P->NextSibling;
    }
    else{
        P->Prev->NextSibling = P->NextSibling;
    }
    P->NextSibling = NULL;
    return Merge(H, P);
}

//合并算法, 注意Sibling总数不要超过1000
PairHeap CombineSiblings( Position FirstSibling ){
    static Position TreeArray[ 1000 ];
    int i, j, NumSiblings;  //NumSiblings在接下来的算法中保留了Siblings个数
    if ( FirstSibling->NextSibling == NULL ){
        return FirstSibling;
    }
    for ( NumSiblings = 0; FirstSibling != NULL; NumSiblings++ ){
        TreeArray[ NumSiblings ] = FirstSibling;
        FirstSibling->Prev->NextSibling = NULL;
        FirstSibling = FirstSibling->NextSibling;
    }
    TreeArray[ NumSiblings ] = NULL; //防止奇偶配位溢出

    for( i = 0; i<=NumSiblings; i+=2 ){
        TreeArray[i] = Merge( TreeArray[i], TreeArray[i+1] );
    }
    j = i-2;
    if ( j == NumSiblings - 3 ){
        TreeArray[j] = Merge(TreeArray[j], TreeArray[j+2]);
    }
    for(;j>=2;j-=2){
        TreeArray[j-2] = Merge(TreeArray[j-2], TreeArray[j]);
    }
    return TreeArray[0];
}

PairHeap DeleteMin(int* Number, PairHeap H ){
    Position NewRoot = NULL;
    if ( H == NULL ){
        printf("PairHeap is Empty.");
        exit(1);
    }
    *Number = H->Rank;
    if ( H->LeftChild != NULL ){
        NewRoot = CombineSiblings( H->LeftChild );
    }
    free(H);
    return NewRoot;
}