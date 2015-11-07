#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string s;
    cin>>s;
    int i;
    string res;
    
    if(s[0]=='9' || s[0] < '5') res.push_back(s[0]);
    else res.push_back(9-(s[i]-'0')+'0');
    for(i = 1; i < s.size(); ++i){
        if(s[i] >= '5'){
            res.push_back(9-(s[i]-'0')+'0');
        }else{
            res.push_back(s[i]);
        }
        
    }
    cout<<res<<endl;
    return 0;
}
