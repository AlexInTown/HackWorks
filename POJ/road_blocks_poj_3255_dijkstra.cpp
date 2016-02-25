#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
struct Edge{
    int v, w;
    bool operator< (const Edge& e) const{
        return w < e.w;
    }
};
int N, R;

vector<Edge> g[5000];
priority_queue<Edge, vector<Edge> > q;
int dist[5000];
int dist1[5000];
bool visited[5000];

int dijkstra(){
    int i;
    memset(visited, 0, sizeof(bool)*N);
    for(i = 0; i < N; ++i){
        dist[i] = 50000000;
        dist1[i] = 50000000;
    }
    dist[0] = 0;
    Edge e, qe;
    e.v = 0;
    e.w = 0;
    q.push(e);
    
    while(!q.empty()){
        e = q.top();
        q.pop();
        int u = e.v;
        visited[u] = true;
        printf("top: %d %d\n", e.v, e.w);
        for(i = 0; i < g[u].size(); ++i){
            // 先和dist比较，如果小的话，替换；将原dist更新到dist1
            Edge & cur = g[u][i];
            printf("   cur: %d %d\n", cur.v, cur.w);
            int temp = dist[u] + cur.w;
            if(dist[cur.v] > temp){
                swap(dist[cur.v], temp);
                qe.v = cur.v; qe.w = dist[cur.v];
                q.push(qe);
            }
            // 和dist1比较，如果小的话
            if(dist1[cur.v] > temp){
                dist1[cur.v] = temp;
                qe.v = cur.v; qe.w = dist1[cur.v];
                q.push(qe);
            }
            // 同时需要入队吗？还是要的
        }
    }
    return dist1[N-1];
}

void add_edge(int u, int v, int w){
    u --; v --;
    Edge e;
    e.v = v; e.w = w;
    g[u].push_back(e);
    e.v = u;
    g[v].push_back(e);
}


int main(){
    scanf("%d%d", &N, &R);
    int i, u,v,w;
    for(i = 0; i < R; ++i){
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    for(i = 0; i < N; ++i){
        printf("%d size %d\n", i, g[i].size());
    }
    printf("%d\n", dijkstra());

    return 0;
}
