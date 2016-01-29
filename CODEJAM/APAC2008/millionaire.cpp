#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
// cur[i] = max(prev[i+j]* P + prev[i-j] *(1-P)) foreach j
// 将j拿出来赌，赢了j翻倍i+j；输了j没了，i-j
double dp[2][1<<15+1];
int M, X;
double P;

double solve(){
    int n = (1<<M);
    int i,j;
    double * cur = dp[1];
    double * prev = dp[0];
    //初始化，第 0 次，只有1000000才行，也就是最后一个元素
    for(i = 0; i < n; ++i)
        prev[i] = 0;
    prev[i] = 1;

    for(int r = 0; r < M; ++r){
        for(i = 0; i <= n; ++i){
            cur[i] = 0;//初始化一定要的！！！
            for(j = 0; j <= i && i+j <= n; ++j){
                cur[i] = max(cur[i], prev[i+j] * P + prev[i-j]*(1-P));
            }
        }
        swap(cur, prev);
    }
    int idx = X / (pow(0.5, M) * 1000000.0);
    if(idx > n) idx = n;
    //printf("%d\n",idx);
    return prev[idx];

}

int main(){
    scanf("%d", &N);
    for(int tt = 1; tt <= N; ++tt){
        scanf("%d%lf%d", &M, &P, &X);
        //printf("%d %f %d", M, P, X);
        double res = solve();
        printf("Case #%d: %.6f\n", tt, res);
    }
    return 0;
}
