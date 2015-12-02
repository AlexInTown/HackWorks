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
Interval intervals[25001];
int dp[25001];
int main(){
    scanf("%d%d", &N, &T);
    int i;
    intervals[0].start = 0;
    intervals[0].end = 0;
    for(i = 1; i <= N; ++i){
        scanf("%d%d", &intervals[i].start, &intervals[i].end);
        dp[i] = 1000000;
    }
    sort(intervals, intervals + N + 1, Comp());
    if(intervals[N].end < T) {
        printf("-1\n");  // end 还够不着的时候。。
        return 0;
    }
    dp[0] = 0;
    Interval temp;
    temp.start = 0;
    for(i = 1; i <= N; ++i){
        //printf("intervals[%d]=(%d, %d)\n", i, intervals[i].start, intervals[i].end);
        temp.end = intervals[i].start-1; // 假如以6开头，那么最少的end要为5
        int idx = lower_bound(intervals, intervals + i, temp, Comp()) - intervals; //第一个大于等于5的开始
        for(int j = idx; j < i; ++j){
            if (intervals[i].end == intervals[j].end) 
                dp[i] = min(dp[i], dp[j]);
            else
                dp[i] = min(dp[i], dp[j]+1);
            //printf("j=%d dp[%d]=%d\n",j, i, dp[i]);
        }
        //printf("%d\n", dp[i]);
    }
    if (dp[N] >= 1000000) dp[N] = -1;
    printf("%d\n", dp[N]);
    return 0;
}
