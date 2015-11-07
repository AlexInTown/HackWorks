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

using namespace std;

typedef long long LL;

int main()
{
    int v[26];
    map<char, vector<int> > idx;
    int i;

    for(i = 0; i < 26; ++i){
        cin>>v[i];
    }
    string s;
    cin>>s;
    vector<LL> pre_sum;
    pre_sum.push_back(v[s[0]-'a']);
    for(i = 0; i < s.size(); ++i){
        idx[s[i]].push_back(i);
    }
    for(i = 1; i < s.size(); ++i){
        pre_sum.push_back(pre_sum.back() + v[s[i]-'a']);
    }
    int j;
    LL res = 0;
    map<LL, int> sum_cnt;
    for(auto iter = idx.begin(); iter != idx.end(); ++iter){
        vector<int> &vec = iter->second;
        for(i = 0; i < vec.size(); ++i){
            res += sum_cnt[pre_sum[vec[i]-1]];
            sum_cnt[pre_sum[vec[i]]]++;
        }
        sum_cnt.clear();
    }
    cout<<res<<endl;
    return 0;
}
