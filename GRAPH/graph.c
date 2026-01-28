//输入图的信息并存储为邻接表
//添加生成入度数组
#include "adjacency.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M;  //N, M分别为顶点数和边数
    int* Indegree;
    
    printf("Please enter vertices and edges: ");
    if ( scanf("%d %d", &N, &M) != 2 ) return 1;
    GraphList graph = CreateGraph(N);
    printf("Please enter %d edges: \n", M);
    for ( int i = 0; i < M; i++ ){
        int u, v;
        scanf("%d %d",&u,&v);
        if( u<0 || u>=N || v<0 || v>=N ){
            printf("Error! Please enter again!\n");
            i--;
            continue;
        }
        AddEdge(graph, u ,v);
    }
    PrintGraph(graph);
    PrintIndegree(graph);

    //以下为用于清空的代码
    DeleteGraph(graph);
    free(Indegree);
}