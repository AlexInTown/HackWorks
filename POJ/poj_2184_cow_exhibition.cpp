#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

const int INVALID_VALUE = -1000000;
const int MAX_VALUE = 100000;
int dp[2][MAX_VALUE *2+1]; // 可以将空间减半， 本质上和背包问题是一致的？
int N;

int main(){
    cin>>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    int i,j,s,f;
    cin>>s>>f;
    for(i = 0; i < MAX_VALUE*2+1; i++)
        dp[0][i] = INVALID_VALUE;
    dp[0][s+MAX_VALUE] = f;
    dp[0][MAX_VALUE] = 0;
    bool cur = 1;
    for(i = 1; i < N; ++i){
        cin>>s>>f;
        for(j = 0; j < MAX_VALUE*2+1; ++j){
            //cout<<dp[!cur][j]<<" ";
            //if(dp[!cur][j] == 0) cout<<"j="<<j<<endl;
            dp[cur][j] = dp[!cur][j];
            if(j >= s && j-s<MAX_VALUE*2 && dp[!cur][j-s]!=INVALID_VALUE){
                // 注意越界问题
                dp[cur][j] = max(dp[cur][j], dp[!cur][j-s] + f);
            }
        }
        //cout<<endl;
        cur = !cur;
    }
    int res = 0;
    for(j = MAX_VALUE; j < MAX_VALUE*2+1; ++j){
        //cout<<dp[!cur][j]<<" ";
        if(dp[!cur][j] >= 0)
        {
            res = max(dp[!cur][j] + j - MAX_VALUE, res);
            //cout<<j - MAX_VALUE<<" "<< dp[!cur][j] <<" "<<dp[!cur][j] + j - MAX_VALUE<<endl;
        }
    }
    //cout<<endl;
    cout<<res<<endl;
    return 0;
}
