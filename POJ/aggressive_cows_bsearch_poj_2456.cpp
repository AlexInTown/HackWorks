#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N, C;
int arr[100000];
int main(){
    scanf("%d%d", &N, &C);
    int i;
    for(i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    int l = 0;
    int r = (arr[N-1] - arr[0]+1) / C + 1;
    int res = 0, prev = 0, cnt = 0, mid;
    while(l < r){
        mid = l + ((r-l)>>1);
        //printf("mid=%d\n", mid);
        prev = 0;
        cnt = 0;
        for(i = 1; i < N; i++){
            if(arr[i] - arr[prev] >= mid){
                cnt++;
                prev = i;
            }        
        }
        if(cnt+1 < C){
            r = mid;
        }else{
            l = mid + 1;
            res = max(res, mid);
        }
    }
    printf("%d\n", res);
    return 0;
}
