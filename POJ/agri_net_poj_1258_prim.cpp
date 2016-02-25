#include<iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;
const int MAXN = 101;
int g[MAXN][MAXN];
int N;
int min_cost[MAXN];
bool visited[MAXN];
int prim(){
    int i,j;
    memset(visited, 0, sizeof(bool) * N);
    for(i = 1; i < N; ++i){
        min_cost[i] = 100000000;
    }
    int res = 0;
    int min_cost_val, min_cost_v;
    min_cost[0] = 0;
    while(1){
        min_cost_v = -1;
        min_cost_val = 1000000;
        for(j = 0; j < N; ++j){
            if(!visited[j] && min_cost_val > min_cost[j]){
                min_cost_val = min_cost[j];
                min_cost_v = j;
            }
        }
        if(min_cost_v == -1) break;
        //printf("%d %d\n", min_cost_v, min_cost_val);
        res += min_cost_val;
        visited[min_cost_v] = 1;
        for(j = 0; j < N; ++j){
            if(!visited[j] && min_cost[j] > g[min_cost_v][j]){
                min_cost[j] = g[min_cost_v][j];
            }
        }
    }
    return res;
}
int main(){
    int i,j;
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; ++i){
            for(j = 0;j < N; ++j){
                scanf("%d", &g[i][j]);
            }
        }
        printf("%d\n", prim());
    }
    return 0;
}
