#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;
int N, M, X;
int dist[1000];
int temp[1000];
struct Edge{
    int u,v,w;
};
vector<Edge> ve1, ve2;
int bellman_ford(vector<Edge> &ve){
    int i,j;
    for(i = 0; i < N; ++i){
        dist[i] = 100000;
    }
    dist[X-1] = 0;
    for(i = 0; i < N-1; ++i){
        for(j = 0; j < ve.size(); ++j){
            if(dist[ve[j].v] > dist[ve[j].u] + ve[j].w)
                dist[ve[j].v] = dist[ve[j].u] + ve[j].w;
        }
    }
    for(j = 0; j < ve.size(); ++j)
        if(dist[ve[j].v] > dist[ve[j].u] + ve[j].w)
            return 1;
    return 0;
}


int main(){
    scanf("%d%d%d", &N, &M, &X);
    int i, j;
    Edge e;
    for(i = 0; i < M; ++i){
        scanf("%d%d%d", &e.u, &e.v, &e.w);
        e.u--; 
        e.v--;
        ve1.push_back(e);
        swap(e.u, e.v);
        ve2.push_back(e);
    }
    bellman_ford(ve1);
    memcpy(temp, dist, sizeof(int) * N);
    bellman_ford(ve2);
    int res = 0;
    for(i = 0; i < N; ++i){
        res = max(res, dist[i] + temp[i]);
    }
    printf("%d\n", res);
    return 0;
}
