#include <iostream>
#include <stdio.h>
using namespace std;
struct Edge{
    int u, v, w;
};
Edge edges[5210];
int dist[510];
int edge_cnt = 0;
void add_edge(int u, int v, int w){
    edges[edge_cnt].u = u;
    edges[edge_cnt].v = v;
    edges[edge_cnt].w = w;
    ++edge_cnt;
}
int N, M, W, F;
int bellman_ford(){
    int i,j;
    for(i = 0; i < N; ++i)
        dist[i] = 5000000;
    for(i = 0; i < N-1; ++i){
        for(j = 0; j< edge_cnt; ++j){
            if(dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
        }
    }
    for(i = 0; i < edge_cnt; ++i)
        if(dist[edges[i].v] > dist[edges[i].u] + edges[i].w)
            return 1;
    return 0;
}
int main(){
    scanf("%d", &F);

    int i,f, u,v,w;
    for(f = 0; f < F; ++f){
        edge_cnt = 0;   //这里有个坑哦
        scanf("%d%d%d", &N, &M, &W);
        for(i = 0; i < M; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        for(i = 0; i < W; ++i){
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            add_edge(u,v,-w);
        }
            
        if(bellman_ford()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
