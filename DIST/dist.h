#ifndef _DIST_H
#define _DIST_H

struct Node;
typedef struct Node* Vertex;
typedef struct Node** AdjList;
struct Graph;
typedef struct Graph* GraphList;

Vertex CreateNode( int dest );
GraphList CreateGraph( int vertices );
void AddEdge( GraphList graph, int src, int dest );
void PrintGraph( GraphList graph );
void DeleteGraph( GraphList graph );

//因无权最短路径需要而新增
struct Table{
    int Dist;
    int Path;
};
typedef struct Table* TableList;

TableList Initialize( int Start, GraphList graph );
TableList Unweighted( int Start, GraphList graph );

#endif