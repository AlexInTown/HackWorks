#include <iostream>
#include <stdio.h>
using namespace std;
int N, M;
int arr[100000];
int months(int expense){
    int i;
    int cur_sum = 0;
    int res = 0;
    for(i = 0; i < N; ++i){
        cur_sum += arr[i];
        if(cur_sum > expense){
            res ++;
            cur_sum = arr[i];
        }
    }
    if(cur_sum > 0){
        res ++;
    }
    return res;
}
int main(){
    int i;
    scanf("%d%d", &N, &M);
    int maxVal = 0;
    for(i = 0; i < N; ++i){
        scanf("%d", & arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    int l = maxVal;
    int r = (N/M +1) * 10000 + 1;
    int mid;
    int res = r;
    while(l < r){
        mid = l + ((r-l) >> 1);
        if(months(mid) > M){
            l = mid + 1;
        }else{
            r = mid;
            res = min(res, mid);
        }
    }
    printf("%d\n", res);
    return 0;
}
