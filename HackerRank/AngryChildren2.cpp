#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

void solve(int arr[], int N, int K) {
    int i,j;
    long long cost = 0;
    long long sum = 0;
    long long times = 1-K;
    //两两求差的绝对值，O(n)的算法，简直碉堡了
    for(i = 0; i < K; ++i){
        cost  += arr[i]*times;
        sum += arr[i];
        times += 2;
    }
    long long minCost = cost;
    for(i = 1; i + K -1 < N; ++i){
        // 通过sum来计算更新，注意i下标的推导
        cost += (long long)(arr[i+K-1]+arr[i-1])*(K-1) - 2*(sum-arr[i-1]) ;
        if(minCost > cost)
            minCost = cost;
        sum = sum -arr[i-1] + arr[i+K-1];
    }
    printf("%lld\n", minCost);
}
int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);  //排序,可证明最小的必为相邻元素
    solve(arr, N, K);
    return 0;
}

