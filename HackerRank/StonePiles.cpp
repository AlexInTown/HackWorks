#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[51];

int get(int i, int curMax, int res);
int runDP(int i){
    if(i <=2)  return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i] = 0;
    for(int j = 1; j < (i+1)/2; ++j)
        if(get(i-j, j, runDP(j)) ==0 ) {dp[i] = 1; break;}
    return dp[i];
}

int get(int i, int curMax, int res){
    if(i<=2){printf("%d,%d = %d\n", i, curMax, res); return res;}
    if(curMax+1 >= (i+1)/2) {printf("%d,%d = %d\n", i, curMax, res^runDP(i)); return res ^ runDP(i);}
    if(curMax > 0 && runDP(i)^res==0) return 0;
    int cur ;
    for(int j = curMax+1; j < (i+1)/2; ++j){
        cur = runDP(j); //bob wins, then alice loses
        printf("%d ", j);
        if(get(i-j, j, cur^res)==0) return 0;
    }
    return 1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;//1 stone, can not split, lose

    int T, N;
    int x, res;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        //scanf("%d", &x);
        res = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", &x);
            res = res ^ runDP(x);
        }
        if(res){
            printf("ALICE\n");
        }else{
            printf("BOB\n");
        }
    }
    return 0;
}

