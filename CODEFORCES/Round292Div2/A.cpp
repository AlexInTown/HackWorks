#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

int main()
{
    int a, b, s;
    cin>>a>>b>>s;
    a = abs(a);
    b = abs(b);
    if(s < a+b || (a+b)%2 != s%2){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
