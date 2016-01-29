#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
};
struct Comp{
    bool operator()(const Interval& a, const Interval& b){
        return a.start < b.start || a.start==b.start && a.end > b.end;
    }
};
Interval intervals[25001];
int dp[1000001]; //利用每个可能的坑，记录下来，找到代价最小的桥梁+1:
int N, T;
int main(){
    scanf("%d%d", &N, &T);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d%d", &intervals[i].start, &intervals[i].end);
    }
    dp[0] = 0;
    for(i = 1; i <= T; ++i){
        dp[i] = 1000000;
    }

    sort(intervals, intervals+N, Comp());
    int last_end = 0, j;
    for(i = 0; i < N; ++i){
        if(intervals[i].end <= last_end) continue;
        else last_end = intervals[i].end;
        for(j = intervals[i].start; j <= intervals[i].end; ++j){
            dp[j] = min(dp[j], dp[intervals[i].start-1] + 1);
        }
    }
    if(dp[T] >= 1000000)
        printf("-1\n");
    else
        printf("%d\n", dp[T]);
    return 0;
}
