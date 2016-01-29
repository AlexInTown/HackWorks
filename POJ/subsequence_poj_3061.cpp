#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int T,N,S;
int arr[100000];
int main(){
    int t,i;
    scanf("%d", &T);
    for(t = 1; t <= T; ++t){
        scanf("%d%d", &N, &S);
        for(i = 0; i < N; ++i)
            scanf("%d", & arr[i]);
        int cur_sum = 0;
        int last = 0;
        int res = INT_MAX; 
        for(i = 0; i < N; i++){
            cur_sum += arr[i]; 
            while(cur_sum >= S){
                res = min(res, i - last + 1);
                cur_sum -= arr[last];
                last ++;
            }
        }
        if(res==INT_MAX) res = 0;
        printf("%d\n", res);
    
    }
    return 0;
}
