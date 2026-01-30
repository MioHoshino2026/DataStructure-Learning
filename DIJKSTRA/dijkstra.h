//针对非负边值的图, 利用Dijkstra算法寻找最短路
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

struct Node;
typedef struct Node* Vertex;
typedef struct Node** AdjList;
struct Graph;
typedef struct Graph* GraphList;

Vertex CreateNode( int dest, int CurrWeight );
GraphList CreateGraph( int vertices );
void AddEdge( GraphList graph, int src, int dest, int CurrWeight );
void PrintGraph( GraphList graph );
void DeleteGraph( GraphList graph );

//因无权最短路径需要而新增
struct Table{
    int Known;
    int Dist;
    int Path;
};
typedef struct Table* TableList;

TableList Initialize( int Start, GraphList graph );
TableList Dijkstra( int Start, GraphList graph );

#endif