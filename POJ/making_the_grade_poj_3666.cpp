#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int N;
int arr[2000];
int ordered[2000];
int dp[2][2000];
int main(){
    cin>>N;
    int i,j;
    for(i = 0; i < N; ++i)
        cin >> arr[i];
    memcpy(ordered, arr, sizeof(int) * N);
    sort(ordered, ordered + N);
    // initialization
    for(i = 0; i < N; ++i){
        dp[0][i] = abs(arr[0] - ordered[i]);
        if(i > 0) dp[0][i] = min(dp[0][i], dp[0][i-1]);
    }
    bool cur = 1;
    // dp
    for(i = 1; i < N; ++i){
        //int minVal =  dp[!cur][0];
        for(j = 0; j < N; ++j){
            //if (minVal > dp[!cur][j])
            //    minVal = dp[!cur][j];
            //dp[cur][j] = minVal + abs(arr[i] - ordered[j]);
            dp[cur][j] = dp[!cur][j] + abs(arr[i] - ordered[j]);
            if(j > 0) dp[cur][j] = min(dp[cur][j-1], dp[cur][j]);
        }
        cur = !cur;
    }
    /*int res = dp[!cur][0];
    for(i = 1; i < N; ++i)
        res = min(dp[!cur][i], res);
    cout<<res<<endl;*/
    cout<<dp[!cur][N-1]<<endl;
    return 0;
}
