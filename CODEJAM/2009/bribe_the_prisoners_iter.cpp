#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
using namespace std;
int T;
int P, Q;
int arr[102];
int dp[102][102];
int main(){
    scanf("%d", &T);
    int i,j,k;
    int temp;
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d%d", &P, &Q);
        arr[0] = 0;
        for(i = 1; i <= Q; ++i){
            scanf("%d", &arr[i]);
        }
        arr[i] = P+1;
        memset(dp, 0, sizeof(dp));
        for(k=2; k <= Q+1; ++k){
            for(i = 0; i+k <= Q+1; ++i){
                dp[i][i+k] = INT_MAX;
                for(j = 1; j < k; ++j){
                    dp[i][i+k] = min(dp[i][i+k], dp[i][i+j] + dp[i+j][i+k] + arr[i+k] - arr[i] -2);
                }
            }
        }
        printf("Case #%d: %d\n", tt, dp[0][Q+1]);

    }
    return 0;
}
