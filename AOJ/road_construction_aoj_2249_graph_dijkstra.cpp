#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#include <stdio.h>
using namespace std;
map<int, int> g[10000];
set<pair<int, int> > mq;
map<pair<int, int>,  int> edges;
int dist[10000];
int cost[10000];
int father[10000];

void dijkstra(int s, int n){
	memset(father, -1, sizeof(int) * n);
	int i;
	for(i = 0; i < n; ++i){
	    dist[i] = 100000000;
	    cost[i] = 100000000;
	}
	
	mq.insert(make_pair(0, s));
	father[s] = -1;
	dist[s] = 0;

	while(mq.size()){
		int d = mq.begin()->first;
		int u = mq.begin()->second;
		mq.erase(mq.begin());
		if(g[u].size() == 0) continue;
		for(map<int, int>::iterator iter = g[u].begin(); iter != g[u].end(); iter++){
			int v = iter->first; int w = iter->second;
			int temp = dist[u] + w; 
			int c = edges[make_pair(min(u,v), max(u,v))];
			if(dist[v] > temp|| dist[v]==temp && cost[v] > c ){
				dist[v] = temp;
				cost[v] = c;
				father[v] = u;
				mq.insert(make_pair(dist[v], v));
			}
		}
	}
}
int main(){
	int n, m;
	int u,v,d,c,s;
	scanf("%d%d", &n, &m);

	int i,j;
	pair<int, int> edge;
	while(n !=0 || m != 0){
	for(i = 0; i < n; ++i){
		g[i].clear();
	}
	edges.clear();
	for(i = 0; i < m; ++i)
	{
		scanf("%d%d%d%d", &u, &v, &d, &c);
		u--; v--;
		if(i == 0) s = u;
		if(u > v) swap(u, v);
		g[u][v] = d;
		g[v][u] = d;
		edge.first = u; edge.second = v;
		edges[edge] = c;
	}
    s = 0;
	dijkstra(s, n);
	int cost = 0;
	for(i = 0; i < n; ++i){
		if(father[i] >= 0){
			edge.first = min(father[i], i);
			edge.second = max(father[i], i);
			cost += edges[edge];
		}
	}
	printf("%d\n", cost);
	scanf("%d%d", &n, &m);
	}
    return 0;
}
