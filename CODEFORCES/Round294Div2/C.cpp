#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <set>
#include <math.h>
#include <memory.h>

typedef long long LL;

using namespace std;

int main()
{
    double n, m;
    cin>>n>>m;
    double x = (2*m-n)/3;
    double y = (2*n-m)/3;
    //cout<<x<<" "<<y<<endl;
    int res = m;
    if(x < 0){
        res = m;
    }else if(y < 0){
        res = n;
    }else{
        res = floor(x) + floor((n-floor(x))/2);
        //cout<<floor(x)<<" "<<floor((n-x)/2)<<endl;
        res = max(res, (int)floor(y) + (int)floor((m-floor(y))/2));
        //cout<<floor(y)<<" "<<floor((m-y)/2)<<endl;
    }
    cout<<res<<endl;
    return 0;
}
