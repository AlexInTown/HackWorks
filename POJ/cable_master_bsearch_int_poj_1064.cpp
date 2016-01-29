#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int N, K;
int arr[10010];

int count(int len){
    int i;
    int cnt = 0;
    for(i = 0; i < N; ++i){
        cnt += arr[i]/len;
    }
    return cnt;
}

int main(){
    scanf("%d%d", &N, &K);
    int i; 
    int l = 1;  // len 有可能会出现除0的异常
    int r = 0;
    double val;
    for(i = 0; i < N; ++i){
        scanf("%lf", &val);
        arr[i] = (int)(val*100);
        r = max(r, arr[i]);
    }
    r += 1;
    int mid;
    int res = 0;  //没找到一定是返回res
    while(l < r){
        mid = (l+r)/2;
        int cnt = count(mid);
        if(cnt < K){
            r = mid;
        }else{
            l = mid+1;
            res = max(res, mid);
        }
    }
    printf("%.2f\n", (double)res / 100.0);
    return 0;
}
