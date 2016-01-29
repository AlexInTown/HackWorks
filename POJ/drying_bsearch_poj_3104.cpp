#include <iostream>
#include <stdio.h>

using namespace std;
int n, k;
int arr[100010];
bool dry(int t){
    int i, tmp;
    int total = 0;
    // 要么在自己晾干，要么用烘干器，设用烘干器的时间为x
    // x *k + (t - x) >= arr[i]
    // (k-1) x + t >= arr[i]
    // x >= ceil((arr[i] - t) / (k-1))
    // 所有需要的为sum(x)
    for(i = 0; i < n; ++i){
        tmp  = arr[i] - t;
        if(tmp > 0){
            total += (tmp + k -2) / (k -1);  
            if(total > t){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int i;
    int l, r, mid, res;
    int max_val, min_val;
    while(scanf("%d", &n)!=EOF){
        max_val = 0;
        min_val = 1000000000;
        for(i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
            max_val = max(max_val, arr[i]);
            min_val = min(min_val, arr[i]);
        }
        scanf("%d", &k);
        if(k==1){
            printf("%d\n", max_val);
            continue;
        }
        l = min_val / k;    // 初始条件这里一开始用了min_val ，应该是min_val / k
        r = max_val + 1;
        res = r;
        while(l < r){
            mid = l + ((r-l)>>1);
            //printf("%d %d %d\n", l, r, mid);
            if(dry(mid)){
                res = min(res, mid);
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
