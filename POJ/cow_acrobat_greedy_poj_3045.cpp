#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
struct Cow{
  int w;
  int s;
};

// 先考虑第一种情况，第i头牛叠到第j头牛的上面 
// 那么 a1 ＝ sum －si， b1 ＝ sum ＋ wi －sj 
// 考虑第二种情况，第j头牛叠到第i头牛的上面 
// 那么 a2 ＝ sum － sj， b2 ＝ sum ＋ wj －si
// 采用二元分析方法！！！
Cow cows[50010];
struct Comp{
    bool operator()(const Cow &a, const Cow&b){
        int t1 =  a.w +a.s;
        int t2 = b.w + b.s;
        return t1 < t2 ; //|| t1 == t2 && a.w < b.w;
    }   
};
int  check(){
    long long sum_w = 0;
    long long max_risk  = INT_MIN;  // 这个risk可能为负值，呵呵呵
    int i;
    for(i = 0; i < N; ++i){
        max_risk = max(sum_w - cows[i].s, max_risk);
        sum_w += cows[i].w;
    }
    return max_risk;
}
int main(){
    scanf("%d", &N);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d%d", &cows[i].w, &cows[i].s);
    }
    sort(cows, cows+N, Comp());
    int res = check();
    printf("%d\n", res);
    return 0;
}   
