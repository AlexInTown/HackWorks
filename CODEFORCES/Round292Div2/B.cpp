#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;
int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b, a%b);
}
int main()
{
    int n, m, b, g;
    cin>>n>>m;
    int gcd = GCD(n, m);
    //cout<<"gcd"<<gcd<<endl;
    vector<bool> flag(gcd);
    cin>>b;
    int i, temp;
    for(i = 0; i < b; ++i){
        cin>>temp;
        flag[temp%gcd] = true;
    }
    cin>>g;
    for(i = 0; i < g; ++i){
        cin>>temp;
        flag[temp%gcd] = true;
    }
    bool res = true;
    for(i = 0; i < gcd; ++i){
        if(!flag[i]){
            res = false;
            break;
        }
    }
    if(res){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
