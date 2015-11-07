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

int main()
{
    int n;
    string s;
    cin>>n>>s;
    int i;
    set<char> ss;
    
    for(i = 0; i < n; ++i){
        if(s[i]>='A' && s[i] <= 'Z'){
            s[i] = s[i]-'A'+'a';
        }
        ss.insert(s[i]);
    }
    if(ss.size()==26){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
