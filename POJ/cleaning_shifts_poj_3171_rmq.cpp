#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, M, E;
struct Interval{
    int start;
    int end;
    int salary;
};
struct Comp{
    bool operator()(const Interval& a, const Interval& b){
        return a.end < b.end || a.end == b.end && (a.start < b.start  || a.start == b.start && a.salary < b.salary);
    }
};
const long long MAX_VALUE = 6000000000;
Interval intervals[10001];
long long dp[10001];
int main(){
    scanf("%d%d%d", &N, &M, &E);
    int i;
    intervals[0].start = 0;
    intervals[0].end = 0;
    intervals[0].salary = 0;
    for(i = 1; i <= N; ++i){
        scanf("%d%d%d", &intervals[i].start, &intervals[i].end, &intervals[i].salary);
        dp[i] = MAX_VALUE;
    }
    sort(intervals, intervals + N + 1, Comp());
    if(intervals[N].end < E || intervals[1].start > M) {
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
                dp[i] = min(dp[i], dp[j]+intervals[i].salary);
            //printf("j=%d dp[%d]=%d\n",j, i, dp[i]);
        }
        if(intervals[i].end >= E && dp[i] < MAX_VALUE) break;
        //printf("%d\n", dp[i]);
    }
    if(dp[i] >= MAX_VALUE) dp[i] = -1;
    printf("%lld\n", dp[i]);
    return 0;
}
