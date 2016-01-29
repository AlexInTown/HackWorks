#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int L, M, N;
int arr[50002];
int skip_cnt(int gap){
    int i;
    int last = 0;
    int cnt = 0;
    for(i = 1; i <= N+1; ++i){
        if(arr[i] - arr[last] < gap){
            cnt += 1;
        }else{
            last = i;
        }
    }
    return cnt;
}
int main(){
    scanf("%d%d%d", &L, &N, &M);
    int i;
    arr[0] = 0;
    for(i = 1; i<= N; ++i){
        scanf("%d", &arr[i]);
    }
    arr[i] = L;
    sort(arr, arr + N + 2);
    int l = 0; 
    int r = L / (N+1-M) + 1;
    int mid;
    int res = 0;
    while(l < r){
        mid = l + ((r-l)>>1);
        // check the minimal gap
        //printf("%d %d %d\n", l, r, mid);
        if(skip_cnt(mid) > M){
            r = mid;
        }else{
            l = mid + 1;
            res = max(res, mid);
        }
    }
    printf("%d\n", res);
    return 0;
}
