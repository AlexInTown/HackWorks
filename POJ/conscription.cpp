#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 10000000;
int T;
int N, M, R;


/*
struct Edge{
    int v, d;
    bool operator< (const Edge&b) const{
        return d < b.d || d==b.d && v<b.v;
        //return d > b.d || d==b.d && v > b.v;
    }
};
bool visited[20000];
vector<Edge> g[20000];
int cost[20000];
set<Edge> q; 

void add_edge(int x, int y, int d){
    y += N;
    Edge e;
    e.v = y;
    e.d = 10000-d;
    g[x].push_back(e);
    e.v = x;
    g[y].push_back(e);
}

// 稀疏图最好还是用 kruskal
// 感觉 prim 会受限 队列的实现，如果V个数较小，不如直接使用线性搜索O(v^2)
int prim(){
    memset(visited, 0, sizeof(int)*(N+M));
    int i,j;
    for(i = 0; i < M+N; ++i){
        cost[i] = INF;
    }
    int res = 0;
    Edge e;
    for(i = 0; i < N+M; ++i){
        if(visited[i]) continue;
        e.v = i; e.d = 0;
        q.insert(e);
        cost[i] = 10000;
        while(q.size()){
            e = *q.begin();
            q.erase(q.begin());
            visited[e.v] = true;
            //printf("top: %d %d\n", e.v, e.d);
            res += cost[e.v];
            for(j = 0; j < g[e.v].size(); ++j){
                Edge cur= g[e.v][j];
                //printf("   cur: %d %d\n", cur.v, cur.d);
                if(visited[cur.v]) continue;
                if(cost[cur.v] > cur.d){
                    swap(cur.d, cost[cur.v]);
                    q.erase(cur);
                    cur.d = cost[cur.v];
                    q.insert(cur);
                }
            }
        }
    }
    return res;
}
*/
struct EdgeK{
    int u, v, d;
    bool operator<(const EdgeK & b) const {
        return d < b.d;
    }
};
EdgeK edges[50000];
int arr[20000];

int unifind(int a, int b){
    int fa = arr[a];
    int fb = arr[b];
    while(fa>=0){
        a = fa;
        fa = arr[a];
    }
    while(fb>=0){
        b = fb;
        fb = arr[b];
    }
    printf("%d %d %d %d\n", a, b, fa, fb);
    if(a==b) return -1;
    if(fb > fa){ // a的秩更大
        arr[a] += arr[b];
        arr[b] = a;
        return a;
    }
    arr[b] += arr[a];
    arr[a] = b;
    return b;
}

int kruskal(){
    //sort by edge
    printf("Before sort.\n");
    sort(edges, edges+R);
    printf("After sort.\n");
    //add edge and test circle
    int i;
    int res = 0;
    for(i = 0; i < R; ++i){
        EdgeK &e = edges[i];
        if(unifind(e.u, e.v) >= 0){
            res += e.d;
        }
    }
    for(i = 0; i < N+M; ++i){
        if(arr[i]<0){
            res += 10000;
        }
    }
    return res;
}

int main(){
    scanf("%d", &T);
    int i, x,y,d;
    while(T--){
        scanf("%d%d%d", &N, &M, &R);
        /*for(i = 0; i < N+M; ++i)
            g[i].clear();
        for(i = 0; i < R; ++i){
            scanf("%d%d%d", &x, &y, &d);
            add_edge(x,y,d);
        }
        printf("%d\n", prim());*/
        for(i = 0; i < R; ++i){
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].d);
            edges[i].v += N;
        }
        memset(arr, -1, sizeof(int)*(N+M));
        printf("%d\n", kruskal());
    }
}
