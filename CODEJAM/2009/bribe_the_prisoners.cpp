#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
using namespace std;
int T;
int P, Q;
int arr[102];
int dp[102][102];
int solve(int s, int e){
    if(s>=e) return 0;
    if(dp[s][e] != -1)
        return dp[s][e];
    int i;
    int res = INT_MAX;
    int temp;
    for(i = s; i < e; i++)
    {
        temp = arr[i] - arr[s-1] -1;
        temp += arr[e] - arr[i] -1;
        temp += solve(s, i);
        temp += solve(i+1, e);
        if(temp < res)
            res = temp;
    }
    dp[s][e] = res;
    return res;
}

int main(){
    scanf("%d", &T);
    int i;
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d%d", &P, &Q);
        arr[0] = 0;
        for(i = 1; i <= Q; ++i){
            scanf("%d", &arr[i]);
        }
        arr[i] = P+1;
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %d\n", tt, solve(1, Q+1));

    }
    return 0;
}
