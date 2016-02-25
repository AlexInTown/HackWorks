#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
using namespace std;

struct Edge{
    int u, v, w;
    bool operator< (const Edge &b) const{
        return w > b.w;
    }
};
int arr[1000];
Edge edges[20000];
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
    if(a == b) return -1;
    int res;
    if(fa < fb){
        arr[a] += fb;
        arr[b] = a;
        res = a;
    }else{
        arr[b] += fa;
        arr[a] = b;
        res = b;
    }
    return res;
}
int N, M;

int kruskal(){
    sort(edges, edges+M);
    int i = 0;
    int res = 0;
    for(i = 0; i < M; ++i){
        if(unifind(edges[i].u, edges[i].v) >= 0){
            res += edges[i].w;
        }
    }
    int cnt = 0;
    for(i = 0; i < N; ++i){
        if(arr[i] < 0) cnt++;
    }
    if(cnt > 1) return -1;
    return res;
}
int main(){
    scanf("%d%d", &N, &M);
    int i;
    for(i = 0; i < M; ++i){
        Edge &e = edges[i];
        scanf("%d%d%d", &e.u, &e.v, &e.w);
        e.u--; e.v --;
    }
    memset(arr, -1, sizeof(int) *N);
    printf("%d\n", kruskal());
    return 0;
}
