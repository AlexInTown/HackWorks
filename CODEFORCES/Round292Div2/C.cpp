#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <memory.h>

using namespace std;

int main()
{
    string s;

    cin>>s;
    cin>>s;

    int i,j;
    int fact[10][4];
    int prime[4] = {2, 3, 5, 7}; 
    memset(fact, 0, sizeof(fact));
    fact[2][0] = 1;
    for(i = 3; i < 10; ++i){
        for(j = 0; j < 4; ++j){
            fact[i][j] = fact[i-1][j];
        }
        int temp = i;
        for(j = 0; j < 4 && temp > 0; ++j){
            while(temp % prime[j]==0 && temp!= 0){
                fact[i][j] ++;
                temp /= prime[j];
            }
        }
    }
    int b[4] = {0, 0, 0, 0};
    for(i = 0; i < s.size(); ++i){
        for(j = 0; j < 4; ++j){
            b[j] += fact[s[i]-'0'][j];
        }
    }
    string res;
    
    for(i = 3; i >=0; --i){
        while(b[i] > 0){
            for(j = 0; j < 4; ++j){
                b[j] -= fact[prime[i]][j];
            }
            res.push_back('0'+prime[i]);
        }
    }
    cout<<res<<endl;
    return 0;
}
