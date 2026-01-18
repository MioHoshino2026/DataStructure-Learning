//实现二叉查找树的C文件, 事先假定所有关键字互异
#include "tree.h"
#include "fatal.h"
#include <stdlib.h>

//建立树节点
struct TreeNode{
    double Element;
    SearchTree Left;
    SearchTree Right;
};

//建立空树
SearchTree MakeEmpty( SearchTree T ){
    if ( T != NULL ){
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free(T);
    }
    return NULL;
}

//二叉查找树的FIND操作
Position Find( double X, SearchTree T ){
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
Position FindMin( SearchTree T ){
    if ( T == NULL ){ return NULL; }
    else if ( T->Left == NULL ){ return T; }
    else{
        return FindMin( T->Left );
    }
}
Position FindMax( SearchTree T ){
    if ( T == NULL ){ return NULL; }
    else if ( T->Right == NULL ){ return T; }
    else{
        return FindMax( T->Right );
    }
}

//插入元素
SearchTree Insert( double X , SearchTree T ){
    //若树为空树, 就创建一个单节点树
    if ( T == NULL ){
        T = malloc( sizeof( struct TreeNode ) );
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
    }
    else if ( X > T->Element ){
        T->Right = Insert( X, T->Right );
    }
    else{
        printf("X is already in Tree T");
    }
    return T;
}

//删除元素
SearchTree Delete( double X, SearchTree T ){
    Position Tmpcell;

    if ( T == NULL ){
        FatalError("Element not Found");
    }
    else if( X < T->Element ){
        T->Left = Delete( X, T->Left);
    }
    else if( X > T->Element ){
        T->Right = Delete( X, T->Right);
    }
    else if( T->Left && T->Right ){
        T->Right = DeleteMin( T->Right, &T->Element );
    }
    else{
        Tmpcell = T;
        if( T->Left == NULL ) T=T->Right;
        else if( T->Right == NULL ) T=T->Left;
        free(Tmpcell);
    }
    return T;
}
//查找并删除T的最小元, 其值保存到MinItem中
SearchTree DeleteMin( SearchTree T, double* MinItem ){
    Position Tmpcell;

    if ( T == NULL ){
        return NULL;
    }
    if ( T->Left == NULL ){
        *MinItem = T->Element;
        Tmpcell = T;
        T = T->Right;
        free(Tmpcell);
        return T;
    }
    else{
        T->Left = DeleteMin( T->Left, MinItem );
        return T;
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