//模拟AVL树结构
#ifndef _AVL_TREE_H
#define _AVL_TREE_H

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty( AvlTree T );
Position Find( double X, AvlTree T );
Position FindMax( AvlTree T );
Position FindMin( AvlTree T );
AvlTree Insert( double X, AvlTree T );
double Retrieve( Position P );

#endif