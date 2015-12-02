#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int N,T;
struct Interval{
    int start;
    int end;
};
struct Comp{
    bool operator()(const Interval& a, const Interval& b){
        return a.end < b.end || a.end == b.end && a.start < b.start;
    }
};
Interval intervals[25000];
int dp[25001];
int main(){
    scanf("%d%d", &N, &T);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d%d", &intervals[i].start, &intervals[i].end);
    }
    sort(intervals, intervals + N, Comp());
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    Interval temp;
    temp.start = 0;
    for(i = 0; i < N; ++i){
        if(i == 0 && intervals[i].start ==1 || i > 0 && intervals[i].start <= intervals[i-1].end+1 && dp[i] >= 0)
            dp[i+1] = dp[i] + 1;
        else //if(i > 0 && intervals[i].start > intervals[i-1].end+1 || intervals[i].start > 1)
            dp[i+1] = -1;
        temp.end = intervals[i].start;
        int idx = lower_bound(intervals, intervals+i, temp, Comp()) - intervals;
        //idx -= 1; idx += 1;
        if(idx > 0 && dp[idx] !=-1){
            if (dp[i+1] >= 0)
                dp[i+1] = min(dp[i+1] , dp[idx] + 1);
            else
                dp[i+1] = dp[idx] + 1;
        }
        printf("%d\n", dp[i+1]);
    }
    printf("%d\n", dp[N]);
    return 0;
}
