#include "avltree.h"
#include "fatal.h"
#include <stdlib.h>

#define MAX( a, b )((a) > (b) ? (a) : (b))

//建立AVL树节点
struct AvlNode{
    double Element;
    AvlTree Left;
    AvlTree Right;
    int Height;  //新增高度参数
};

//返回节点高度
static int Height( Position P ){
    if ( P == NULL ){
        return -1;  //空树高度定义为-1
    }
    else{ return P->Height; }
}

//插入操作
static Position SingleRotateWithLeft( Position K2 );
static Position SingleRotateWithRight( Position K2 );
static Position DoubleRotateWithLeft( Position K3 );
static Position DoubleRotateWithRight( Position K3 );

AvlTree Insert( double X, AvlTree T ){
    if ( T == NULL ){
        T = malloc( sizeof( struct AvlNode ) );
        if ( T == NULL ){
            FatalError("Out of Space!!!");
        }
        else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if ( X < T->Element ){
        T->Left = Insert( X, T->Left );
        if ( Height( T->Left ) - Height( T->Right ) == 2 ){
            if ( X < T->Left->Element ) T = SingleRotateWithLeft( T );
            else T = DoubleRotateWithLeft( T );
        }
    }
    else if ( X > T->Element ){
        T->Right = Insert( X, T->Right );
        if ( Height( T->Right ) - Height( T->Left ) == 2 ){
            if ( X > T->Right->Element ) T = SingleRotateWithRight( T );
            else T = DoubleRotateWithRight( T );
        }
    }
    else{ printf("X is already in T."); }
    T->Height = MAX( Height( T->Left ), Height( T->Right ) ) + 1;
    return T;
}
static Position SingleRotateWithLeft( Position K2 ){
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = MAX( Height(K2->Left), Height(K2->Right) ) + 1;
    K1->Height = MAX( Height(K1->Left), K2->Height ) + 1;
    return K1;
}
static Position SingleRotateWithRight( Position K2 ){
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = MAX( Height(K2->Left), Height(K2->Right) ) + 1;
    K1->Height = MAX( Height(K1->Right), K2->Height ) + 1;
    return K1;
}
static Position DoubleRotateWithLeft( Position K3 ){
    K3->Left = SingleRotateWithRight( K3->Left );
    return SingleRotateWithLeft( K3 );
}
static Position DoubleRotateWithRight( Position K3 ){
    K3->Right = SingleRotateWithLeft( K3->Right );
    return SingleRotateWithRight( K3 );
}

//剩余内容与TREE结构一致

//建立空树
AvlTree MakeEmpty( AvlTree T ){
    if ( T != NULL ){
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free(T);
    }
    return NULL;
}

//二叉查找树的FIND操作
Position Find( double X, AvlTree T ){
    if ( T == NULL ){
        return NULL;
    }
    else if( X < T->Element ){
        return Find( X, T->Left);
    }
    else if( X > T->Element ){
        return Find( X, T->Right );
    }
    else{ return T; }
}

//返回树的最大元和最小元的位置
Position FindMin( AvlTree T ){
    if ( T == NULL ){ return NULL; }
    else if ( T->Left == NULL ){ return T; }
    else{
        return FindMin( T->Left );
    }
}
Position FindMax( AvlTree T ){
    if ( T == NULL ){ return NULL; }
    else if ( T->Right == NULL ){ return T; }
    else{
        return FindMax( T->Right );
    }
}

//返回当前节点所存储数据
double Retrieve( Position P ){
    if( P == NULL ){
        FatalError("Empty Position");
    }
    else{
        return P->Element;
    }
}