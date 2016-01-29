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
        return a.start < b.start || a.start==b.start && a.end < b.end;
    }
};
Interval intervals[25001];
int N, T;
int main(){
    scanf("%d%d", &N, &T);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d%d", &intervals[i].start, &intervals[i].end);
    }
    sort(intervals, intervals+N, Comp());
    if(intervals[0].start > 1) 
    {
        printf("-1\n");
        return 0;
    }
    int max_end = intervals[0].end;
    i = 1;
    int j;
    int res = 1;
    while(max_end < T){
        if(i >= N) break;
        int end = -1;
        // 注意条件是 intervals[j].start <= max_end+1
        for(j = i; j < N && intervals[j].start <= max_end+1; j++){
            if(intervals[j].end > end) end = intervals[j].end;
        }
        if(end <= max_end) 
            break;
        else{
            max_end = end;
            ++res;
        }
        i = j; //一旦此次过了这interval，那么下一次就没有必要了
    }
    if(max_end < T) {
        printf("-1\n");
    }else{
        printf("%d\n", res);
    }
    return 0;
}
