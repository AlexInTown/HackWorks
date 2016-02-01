#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#include <stdio.h>
using namespace std;
const bool SUBMIT = 0;
struct Edge{
    int v, d, c;
    bool operator<(const Edge & b) const {
        //return d < b.d || d == b.d && c < b.c ;
        return(d==b.d)?((c==b.c)? v < b.v: c < b.c): d < b.d;
    }
};
vector<Edge> g[10000];
set<Edge> mq;  //这里tm的不能使用 SET，如果说只比较Edge d c，且d,c相等，就insert 不进去（小心啊小心）！！！ 用priority que 保险吶！！！
int dist[10000];
//int cost[10000];
int father[10000];
bool visited[10000];
 

int dijkstra(int s, int n){
	memset(father, -1, sizeof(int) * n);
    memset(visited, 0, sizeof(bool) * n);
	int i;
	for(i = 0; i < n; ++i){
	    dist[i] = 100000000;
        //cost[i] = 100000000;
	}
    Edge edge;
    edge.v = s;
    edge.d = 0;
    edge.c = 0;
	mq.insert(edge);
	father[s] = -1;
	dist[s] = 0;
    //cost[s] = 0;
    int res = 0;
	while(mq.size()){
        edge = *mq.begin();
        int u = edge.v;
        //printf("cur top: %d %d %d\n", u, edge.d, edge.c);
		mq.erase(mq.begin());
        if(visited[u]) continue;
        visited[u] = 1;
        res += edge.c;
        for(i = 0; i < g[u].size(); ++i){
            Edge e = edge;
            e.v = g[u][i].v;
            e.d = g[u][i].d + edge.d;
            e.c = g[u][i].c;
            //printf("   insert e: %d %d %di\n", e.v, e.d, e.c);
            mq.insert(e);
		}
	}
    return res;
}
int main(){
	int n, m;
	int u, s;
    if(!SUBMIT)
        freopen("2249-input.txt", "r", stdin);
	scanf("%d%d", &n, &m);

	int i,j;
	while(n !=0 || m != 0){
	for(i = 0; i < n; ++i){
		g[i].clear();
        mq.clear();
	}
    Edge edge;
	for(i = 0; i < m; ++i)
	{
		scanf("%d%d%d%d", &u, &edge.v, &edge.d, &edge.c);
		u--; edge.v--;
		if(i == 0) s = u;
        g[u].push_back(edge);
        int temp = u;
        u = edge.v;
        edge.v = temp;
        g[u].push_back(edge);
	}
    s = 0;
	int cost = dijkstra(s, n);
	/*int cost = 0;
	for(i = 0; i < n; ++i){
		if(father[i] >= 0){
            for(j = 0; j < g[father[i]].size(); ++j){
                int c = g[father[i]][j].c;
                int v = g[father[i]][j].v;
                if(v == i){
                    cost += c;
                    break;
                }
            }
		}
	}*/
	printf("%d\n", cost);
	scanf("%d%d", &n, &m);
	}
    return 0;
}
