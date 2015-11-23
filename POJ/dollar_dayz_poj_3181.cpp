#include <stdio.h>
#include <memory.h>
using namespace std;
long long dp[1001];
//完全背包, 加上高精度加法
int N, K;
int main(){
    //cin>>N>>K;
    scanf("%d%d", &N, &K);
    int i,j;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(i = 1; i <= K; ++i){
        for(j = i; j <= N; ++j){
            dp[j] += dp[j-i];
        }
    }
    //cout<<dp[!cur][N]<<endl;
    printf("%lld\n", dp[!cur][N]);
    return 0;
}
