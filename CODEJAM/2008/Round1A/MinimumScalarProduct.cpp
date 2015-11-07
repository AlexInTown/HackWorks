#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
LL minScalarProd(vector<int> &x, vector<int> &y){
    int n = x.size();
    sort(x.begin(), x.end());
    sort(y.begin(), y.end(), greater<int> ());
    int i;
    LL res = 0;
    for(i = 0; i < n; ++i){
        res  += ((LL)x[i]) * y[i];
    }
    return res;
}

int main(){
    int T, n;
    scanf("%d", &T);
    int i, j;
    vector<int> x, y;
    for(i = 1; i <= T; ++i){
        scanf("%d", &n);
        x.resize(n); 
        y.resize(n);
        for(j = 0; j < n; ++j){
            scanf("%d", &x[j]);
        }
        for(j = 0; j < n; ++j){
            scanf("%d", &y[j]);
        }
        printf("Case #%d: %lld\n", i, minScalarProd(x, y));
    }
    return 0;
}
