#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <memory.h>


using namespace std;
const int MOD = 100003;
typedef long long LL;
int N;
int dp[501][501];
int fact[501];
int inv[501];
int invFact[501];
int nck[501][501];
void calFact(){
    fact[0] = 1;
    for(int i = 1; i < 501; ++i){
        fact[i] = i * fact[i-1];
        fact[i] = fact[i] % MOD;
    }
}
void Inverse(){
    int n = 500;
    memset(inv, 0, sizeof(inv));
    LL v;
    int i;
    inv[1] = 1;
    for(i = 2; i <= n; ++i){
        v = MOD-MOD/i;
        v *= inv[MOD % i];
        inv[i] = v % MOD;
    }
}
void InvFact(){
    int n = 500;
    int i;
    invFact[0] = 1;
    LL v;
    for(i = 1; i <= n; ++i){
        v = invFact[i-1];
        v *= inv[i];
        invFact[i] = v %MOD;
    }
}
LL nchoosek(int n, int k){
    //cout<<"n"<<n<<" k"<<k<<endl;
    if(n < k || n<0) return 0;
    LL v;
    v = fact[n];
    v *= invFact[k];
    v %= MOD;
    v *= invFact[n-k];
    v %= MOD;
    return v;
}
void calNCK(){
    int i,j;
    LL v;
    nck[0][0] = 1;
    for(i = 1; i < 501; ++i){
        for(j = 0; j <=i; ++j){
            if(j==0 || j==i){ nck[i][j] = 1;continue;}
            v = nck[i-1][j-1];
            v += nck[i-1][j];
            nck[i][j] = v % MOD;
        }
    }
}
int main(){
    int t,T, i, j, k, l;
    cin>> T;
    //calFact();
    //Inverse();
    //InvFact();
    calNCK();
    LL v;
    for(t = 1; t <= T; ++t){
        cin>>N;
        memset(dp, 0, sizeof(dp));
        // 5
        // 2 5
        // 2 3 5
        // 2 3 4 5
        // 3 4 5
        // 
        dp[1][1] =1;
        for(i = 2; i <= N; ++i){
            dp[i][1] = 1;
            for(j = 1; j < i; ++j){
                for(k = 1; k <= j; ++k){
                    v = dp[j][k];
                    v = v * nck[i-j-1][j-k-1];
                    dp[i][j] += v % MOD;
                    dp[i][j] = dp[i][j] % MOD;
                }
            }
        }
        int res = 0;
        for(i = 0; i <= N; ++i){
            res += dp[N][i];
            res = res % MOD;
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
