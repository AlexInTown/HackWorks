#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int dp[2001][2001];
char buffer[2002];
int add_cost[26];
int del_cost[26];
int N, M;
int main(){
    scanf("%d%d", &N, &M);
    //printf("%d%d", N, M);
    int i,j,k;
    scanf("%s", &buffer);
    //printf("%s", buffer);
    for(i = 0; i < M; ++i){
        buffer[i] -= 'a';
    }
    char chr;
    for(i = 0; i < N; ++i)
    {
        do{scanf("%c", &chr);} while(chr=='\r'|| chr=='\n'); 
        scanf("%d", &add_cost[chr-'a']);
        scanf("%d", &del_cost[chr-'a']); //读char的时候不会跳过行尾
        //printf("(%c,%d,%d)",chr, add_cost[chr-'a'], del_cost[chr-'a']);
        //cin>>chr;
        //cin>>add_cost[chr-'a']>>del_cost[chr-'a'];
    }
    for(i = 0; i < M; ++i)
        dp[i][i] = 0;
    for(k = 1; k < M; ++k){
        for(i = 0; i + k < M; ++i){
            dp[i][i+k] = INT_MAX;
            if(buffer[i] == buffer[i+k]){
                if(k==1) dp[i][i+k] = 0;
                else dp[i][i+k] = dp[i+1][i+k-1];
            }
            int minRight = min(add_cost[buffer[i+k]], del_cost[buffer[i+k]]);
            dp[i][i+k] = min(dp[i][i+k], dp[i][i+k-1] + minRight);
            int minLeft = min(add_cost[buffer[i]], del_cost[buffer[i]]);
            dp[i][i+k] = min(dp[i][i+k], dp[i+1][i+k] + minLeft);
            //printf("%d %d %d %d %d\n", i, i+k, dp[i][i+k], minLeft, minRight);
        }
    }
    printf("%d\n", dp[0][M-1]);
    return 0;
}


/*
#include <stdio.h>
#include <string.h>
#define mem(a) memset(a,0,sizeof(a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int DP[2005][2005],cost[30],N,M;
char str[2005];

int main()
{
    while(~scanf("%d%d", &M, &N))
    {
        mem(DP); mem(str); mem(cost);
        scanf("%s%*c",str);
        char ch; int x, y;
        for(int i=0;i<M;i++)
        {
            scanf("%c %d %d%*c", &ch, &x, &y);
            cost[ch-'a'] = MIN(x,y);
        }
        for(int i=1;i<N;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                DP[j][i] = MIN(DP[j+1][i]+cost[str[j]-'a'], DP[j][i-1]+cost[str[i]-'a']);
                if(str[i] == str[j])DP[j][i] = MIN(DP[j][i],DP[j+1][i-1]);
            }
        }
        printf("%d\n", DP[0][N-1]);
    }
    return 0;
}*/