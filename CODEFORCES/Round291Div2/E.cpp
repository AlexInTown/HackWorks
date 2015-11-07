#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int, int> result;
vector<int> children;
const int MOD = 1000000007;

int findOrCal(int remain){
    if(remain==0) return 1;
    unordered_map<int, int>::iterator iter = result.find(remain);
    if(iter != result.end()){
        return iter->second;
    }
    int i;
    int res = 1, temp;
    for(i = 0; i < children.size(); ++i){
        if(remain-children[i] < 0) continue;
        temp = findOrCal(remain-children[i]);
        res = (res+temp)%MOD;
    }
    result[remain] = res;
    return res;
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    children.resize(n);
    int i;
    for(i = 0; i < n; ++i){
        scanf("%d", &children[i]);
    }
    printf("%d\n", findOrCal(x));
    return 0;
}
