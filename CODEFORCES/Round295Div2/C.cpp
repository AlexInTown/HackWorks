#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <memory.h>
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;

LL powMod(LL a, int n){
    LL res = 1;
    while(n){
        if(n&1) res = (res*a)%MOD;
        a = a * a;
        a %= MOD;
        n = n >>1;
    }
    return res;
}

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    LL res = 0;
    map<char, int> cnts;
    for(int i = 0; i < s.size(); ++i){
        cnts[s[i]]++;
    }
    int maxCnt = 0;
    for(auto iter = cnts.begin(); iter!= cnts.end();++iter){
        maxCnt = max(maxCnt, iter->second);
    }
    int num = 0;
    for(auto iter = cnts.begin(); iter!=cnts.end(); ++iter){
        if(iter->second==maxCnt){
            num++;
        }
    }
    res = powMod(num, n);
    cout<<res<<endl;
    return 0;
}
