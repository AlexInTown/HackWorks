#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Period{
    int start;
    int end;
    int eff;
};

struct Comp{
    bool operator()(const Period & a, const Period &b){
        return a.end < b.end; 
    }
};

Period periods[1000];
int dp[1001];
int N, M, R;
int main(){
    cin>>N>>M>>R;
    int i, j;
    for(i = 0; i < M; ++i){
        cin>>periods[i].start >> periods[i].end>>periods[i].eff;
    }
    sort(periods, periods + M, Comp());
    memset(dp, 0, sizeof(dp));
    dp[0] = periods[0].eff;
    Period p;
    for(i = 1; i < M; ++i){
        p.end = periods[i].start - R;
        int idx = upper_bound(periods, periods + i, p, Comp()) - 1 - periods;  //这里有个坑，数组越界
        dp[i] = periods[i].eff;
        if(idx >= 0)
            dp[i] += dp[idx];
        if(dp[i] < dp[i-1])
            dp[i]= dp[i-1];
    }
    cout<<dp[M-1]<<endl;
    return 0;
}
