#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
struct Cow{
  int w;
  int s;
};
Cow cows[50000];
struct Comp{
    bool operator()(const Cow &a, const Cow&b){
        int t1 =  a.w +a.s;
        int t2 = b.w + b.s;
        return t1 < t2 || t1 == t2 && a.w < b.w;
    }   
};
bool check(int risk){
    long long sum_w = 0;
    int i;
    for(i = 0; i < N; ++i){
        if(sum_w - cows[i].s> risk)
            return false;
        sum_w += cows[i].w;
    }
    return true;
}
int main(){
    scanf("%d", &N);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d%d", &cows[i].w, &cows[i].s);
    }
    sort(cows, cows+N, Comp());
    int l = -1000000000;
    int r = 1000000000;
    int mid;
    int res = r;
    while(l < r){
        mid = l + ((r-l)>>1);
        if(check(mid)){
            r = mid;
            res = min(mid, res);
        }else{
            l = mid+1;
        }
    }
    printf("%d\n", res);
    return 0;
}   
