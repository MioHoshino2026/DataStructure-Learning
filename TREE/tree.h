//模拟二叉查找树结构
#ifndef _TREE_H
#define _TREE_H

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( double X, SearchTree T );
Position FindMax( SearchTree T );
Position FindMin( SearchTree T );
SearchTree Insert( double X, SearchTree T );
SearchTree Delete( double X, SearchTree T );
double Retrieve( Position P );

#endif