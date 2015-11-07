#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>
#include <unordered_map>
#include <vector>

#define FORMAT I64d
using namespace std;
typedef long long LL;

const int MOD = 1e9+7;
const int DIM = 101;
const int MAX_IDX = 100;

vector<int> counts(MAX_IDX);

struct Matrix{
    LL ma[DIM][DIM];
};


Matrix Mult(const Matrix &a, const Matrix &b){
    Matrix res;
    int i,j,k;
    for(i = 0; i < DIM; ++i){
    for(j = 0; j < DIM; ++j){
        res.ma[i][j] = 0;
        for(k = 0; k < DIM; ++k){
            res.ma[i][j] = res.ma[i][j]+ a.ma[i][k]*b.ma[k][j];
            if(res.ma[i][j] > MOD) res.ma[i][j] %= MOD;
        }
    }
    }
    return res;
}
Matrix Pow(Matrix a, int p){
    Matrix res;
    memset(res.ma, 0, sizeof(res.ma));
    int i, j;
    for(i = 0; i < DIM; ++i){
        for(j = 0; j < DIM; ++j){
            res.ma[i][j] = (i==j);
        }
    }
    while(p){
        if(p&1) { res = Mult(res, a);}
        a = Mult(a, a);
        p = p/2;
    }
    return res;
}
void printMatrix(const Matrix &a){
    int i, j;
    for(i = 0; i < DIM; ++i){
        for(j = 0; j < DIM; ++j){
            printf("%LL_FORMAT ", a.ma[i][j]);
        }
        printf("\n");
    }
}

void printVector(const vector<int> &vi){
    int i;
    for(i = 0; i < vi.size(); ++i)
        printf("%d ", vi[i]);
    printf("\n");
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    int i,j;
    int d;
    for(i = 0; i < n; ++i){
        scanf("%d", &d);
        counts[d-1]++;
    }
    vector<LL> dp(DIM);
    vector<LL> sum(DIM);
    dp[0] = 1;
    sum[0] = 0;
    for(i = 1; i <= MAX_IDX; ++i){
        dp[i] = 0;
        for(j = 1; j <= i; ++j){
            dp[i] = dp[i] + dp[i-j] * counts[j-1];
            if(dp[i] > MOD) dp[i] %= MOD;
        }
        sum[i] = sum[i-1] + dp[i];
        if(sum[i] > MOD) sum[i] %= MOD;
    }
    if(x <= MAX_IDX){
        //printf("%LL_FORMAT\n", (sum[x]+1)%MOD);
        cout<<(sum[x]+1)%MOD<<endl;
        return 0;
    }
    Matrix init;
    memset(init.ma, 0, sizeof(init.ma));
    for(i = 1; i < MAX_IDX; ++i){
        init.ma[i-1][i] = 1;
    }
    for(i = 0; i < MAX_IDX; ++i){
        init.ma[MAX_IDX-1][MAX_IDX-i-1] = counts[i];
        init.ma[MAX_IDX][MAX_IDX-i-1] = counts[i];
    }
    init.ma[MAX_IDX][MAX_IDX] = 1;
    //printMatrix(init);
    //printVector(dp);
    //printVector(sum);
    init = Pow(init, x-MAX_IDX);
    LL res = ((sum[MAX_IDX]+1) * init.ma[MAX_IDX][MAX_IDX]) % MOD;
    //printf("%LL_FORMAT\n", res);
    for(i = 0; i < MAX_IDX; ++i){
        res = res + dp[i+1]*init.ma[MAX_IDX][i];
        if(res > MOD) res %= MOD;
    }
    //printf("%LL_FORMAT\n", res);
    cout<<res<<endl;

    return 0;
}
