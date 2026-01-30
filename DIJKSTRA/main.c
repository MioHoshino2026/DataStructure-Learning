#include "heappair.h"
#include "dijkstra.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M;  //N, M分别为顶点数和边数
    
    printf("Please enter vertices and edges: ");
    if ( scanf("%d %d", &N, &M) != 2 ) return 1;
    GraphList graph = CreateGraph(N);
    printf("Please enter %d edges: \n", M);
    for ( int i = 0; i < M; i++ ){
        int u, v, c;
        scanf("%d %d %d",&u,&v,&c);
        if( u<0 || u>=N || v<0 || v>=N ){
            printf("Error! Please enter again!\n");
            i--;
            continue;
        }
        AddEdge(graph, u ,v, c);
    }
    //PrintGraph(graph);

    //计算两个顶点的有向距离, 先输入起点后输入终点
    printf("Please enter two vertices which you want to count their distance: ");
    int n, m;
    scanf("%d %d", &n, &m);
    if( n<0 || n>=N || m<0 || m>= N ){
        printf("Illegal Vertex!");
        exit(1);
    }
    TableList T = Dijkstra(n,graph);
    if ( T[m].Dist == INT_MAX ) {
        printf("Vertex %d is not reachable from %d.\n", m, n);
    } else {
        printf("The distance from %d to %d is %d.\n", n, m, T[m].Dist);
    }

    //以下为用于清空的代码
    DeleteGraph(graph);
    free(T);
    return 0;
}