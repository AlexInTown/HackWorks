#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <vector>
#include <map>

#include <functional>
#include <algorithm>
using namespace std;
//vector<double> vol;
typedef long long LL;
map<LL, LL> mymap;
typedef map<LL, LL>::iterator ITER;
int main(){
    int n, i;
    int r, h;
    scanf("%d", &n);
    LL res = 0;
    for(i = 0; i < n; ++i){
        scanf("%d%d", &r, &h);
        LL vol = r;
        vol = vol*r*h;
        if(i == 0){
            mymap[vol] = vol;
            res = vol;
            continue;
        }
        LL val;
        ITER iter = mymap.lower_bound(vol);
        if(iter != mymap.begin()){
            iter--;
            val = iter->second + vol;
        }else{
            val = vol;
        }
        while(1){
            iter = mymap.lower_bound(vol);
            if(iter != mymap.end() && iter->second < val){
                mymap.erase(iter);
            }else{
                break;
            }
        }
        mymap[vol] = val;
        res = max(res, val);
    }
    printf("%.9f", res*3.141592653589793);
    return 0;
}
