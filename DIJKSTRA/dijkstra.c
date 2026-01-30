#include "dijkstra.h"
#include "heappair.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
//在实现Dijkstra算法时, 对Node作出如下更新: 增加权重Cvw, 并在AddEdge时同步更新该信息

struct Node{
    int Dest;
    int Weight;  //边的非负权重
    Vertex Next;
};

struct Graph{
    int NumVertices;
    AdjList AdjLists;
};

Vertex CreateNode( int dest, int CurrWeight ){
    Vertex NewNode;

    NewNode = malloc( sizeof( struct Node ));
    if ( NewNode == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    NewNode->Dest = dest;
    NewNode->Next = NULL;
    NewNode->Weight = CurrWeight;
    return NewNode;
}

GraphList CreateGraph( int vertices ){
    GraphList graph;
    graph = malloc( sizeof( struct Graph ));
    if ( graph == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    graph->NumVertices = vertices;
    graph->AdjLists = malloc(sizeof( Vertex ) * graph->NumVertices );
    if ( graph->AdjLists == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    for ( int i = 0; i<graph->NumVertices; i++ ){
        graph->AdjLists[i] = NULL;
    }
    
    return graph;
}

void AddEdge( GraphList graph, int src, int dest, int CurrWeight ){
    Vertex NewNode = CreateNode( dest, CurrWeight );
    NewNode->Next = graph->AdjLists[src];
    graph->AdjLists[src] = NewNode;
}

void PrintGraph(GraphList graph){
    Vertex Tmp;
    for ( int i = 0; i<graph->NumVertices; i++ ){
        Tmp = graph->AdjLists[i];
        printf("Vertex %d: ", i);
        while( Tmp ){
            printf("-> %d ",Tmp->Dest);
            Tmp = Tmp->Next;
        }
        printf("-> NULL\n");
    }
}

void DeleteGraph(GraphList graph){
    Vertex Tmp, ToFree;
    for ( int i = 0; i<graph->NumVertices; i++ ){
        Tmp = graph->AdjLists[i];
        while( Tmp ){
            ToFree = Tmp;
            Tmp = Tmp->Next;
            free(ToFree);
        }
    }
    free(graph->AdjLists);
    free(graph);
}

//输入路径起点和图的名称, 以创建路径辅助列表
TableList Initialize( int Start, GraphList graph ){
    TableList T;

    T = malloc(sizeof(struct Table)*graph->NumVertices);
    if ( T == NULL ){
        printf("Out of Space!!!");
        exit(1);
    }
    for ( int i = 0; i < graph->NumVertices ; i++){
        T[i].Known = 0;
        T[i].Dist = INF;
        T[i].Path = -1;
    }
    T[Start].Dist = 0;
    return T;
}

int succ(int i, int n){
    if( ++i == n ){
        return 0;
    }
    else{
        return i;
    }
}
//Dijkstra算法
TableList Dijkstra( int Start, GraphList graph )
{
    TableList T = Initialize( Start, graph );
    T[Start].Dist = 0;

    PairHeap H = NULL;
    Position* P = calloc(graph->NumVertices, sizeof(Position)); 
    H = Insertl(Start, 0, P[Start], H);

    int v; 
    Vertex Tmp;
    int* R = malloc(sizeof(int));

    while( H != NULL ) {
        H = DeleteMin(R, H);
        v = *R;
        
        if (T[v].Known) continue;
        T[v].Known = 1;

        Tmp = graph->AdjLists[v];
        while ( Tmp ) {
            int w = Tmp->Dest;
            if( !T[w].Known ) {
                if ( T[v].Dist + Tmp->Weight < T[w].Dist ) {
                    int OldDist = T[w].Dist;
                    T[w].Dist = T[v].Dist + Tmp->Weight;
                    T[w].Path = v;

                    if (OldDist == INF) {
                        H = Insertl(w, T[w].Dist, P[w], H);
                    } else {
                        H = DecreaseKey(P[w], OldDist - T[w].Dist, H);
                    }
                }
            }
            Tmp = Tmp->Next;
        }
    }
    free(P);
    free(R);
    return T;
}