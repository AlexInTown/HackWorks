//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <memory.h>
using namespace std;
#ifndef YOUR_RANK_IS_PURE_H
#define YOUR_RANK_IS_PURE_H
long long dp[501][501];
long long cnk[501][501];
class YourRankIsPure{
public:
    int runDP(int x, int y){
        
    }
};
int main(){
    
    //ifstream file("YourRankIsPure.large.in");
    //cin.rdbuf(file.rdbuf());
    //ofstream out("output.txt");
    //cout.rdbuf(out.rdbuf());
    
    int nCases;
    cin>>nCases;
    int i, j, k;
    memset(cnk, 0, sizeof(cnk));
    memset(dp, 0, sizeof(dp));
    cnk[0][0] = 1;
    for(i = 1; i < 501; ++i)
    {
        for(j = 0; j <= i; ++j){
            if(j==0||i==j)
                cnk[i][j] = 1;
            else 
                cnk[i][j] = (cnk[i-1][j-1]+cnk[i-1][j])% 100003;
        }
    }
    //cout<<"Starting to DP."<<endl;
    for(i = 2; i < 501; ++i)
        dp[i][1] = 1;
    for(i = 3; i < 501; ++i)
        for(j = 2; j < i; ++j){
            dp[i][j] = 0;
            for(k = 1; k < j; ++k){
                /*dp[j][k] * cnk[i-j-1][j-k-1] may be larger than INT_MAX*/
                dp[i][j] += dp[j][k]* cnk[i-j-1][j-k-1];
                //if (dp[i][j] >= 100003)
                //    dp[i][j] = dp[i][j] % 100003;
            }
            dp[i][j]%=100003;
        }

    //cout<<"DP Ended."<<endl;
    //cout<<nCases<<endl;

    int N;
    long long res;
    for( i = 0; i < nCases; ++i)
    {
        cin>>N;
        //cout<<N<<endl;
        res = 0;
        for(j = 1; j < N; ++j){
            res += dp[N][j];
            res %= 100003;
        }
        //res %= 100003;
        cout<<"Case #"<<i+1<<": "<<res<<endl;
        //printf("Case #%d: %d\n", i+1, res);
    }
    return 0;

}
#endif
