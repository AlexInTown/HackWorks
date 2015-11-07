#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<long long>::iterator ITER;
int main() {
    int N, M;
    scanf("%d", &N);
    vector<long long> radius(N);
    int i,j, x, y;
    for(i = 0; i < N; ++i){
        scanf("%d", & radius[i]);
        radius[i] *= radius[i];
    }
    
    sort(radius.begin(), radius.end());
    /*for(i = 0; i < N; ++i)
        printf("%lf ", radius[i]);
    printf("\n");*/
    scanf("%d", &M);
    int ret = 0;
    long long start, end;
    for(i = 0; i < M; ++i){
        scanf("%d%d", &x, &y);
        start  = x*x;
        start = start+y*y;
        
        scanf("%d%d", &x, &y);
        end = x*x;
        end = (end+y*y);
        
        if(start > end) swap(start, end);
        //printf("%lf %lf\n", start, end);
        ITER iter1 = upper_bound(radius.begin(), radius.end(), start);
        ITER iter2 = lower_bound(radius.begin(), radius.end(), end);
        //printf("%d %d\n", iter1-radius.begin(), iter2-radius.begin());
        ret += iter2-iter1;
    }
    printf("%d\n", ret);
    return 0;
}


