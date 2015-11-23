#include <iostream>
#include <memory.h>
using namespace std;
int n, m;
int count[100011];
int findex[100011];
int a[100011];
int main(){
    cin>>n>>m;
    memset(count, 0, sizeof(int)*(n+1));
    memset(findex, 0, sizeof(int)*(n+1));
    memset(a, 0, sizeof(int)*(m+1));
    int i,val;
    bool ambi = false;
    bool poss = true;
    for(i = 1; i <= n; ++i){
        cin>>val;
        count[val] ++;
        findex[val] = i;
    }
    for(i = 1; i <= m; ++i){
        cin>>val;
        if(count[val] > 1) ambi = true;
        if(count[val] == 0) poss = false;
        a[i] = findex[val];
    }
    if(!poss){
        cout<<"Impossible"<<endl;
    }else if (ambi){
        cout<<"Ambiguity"<<endl;
    }else{
        cout<<"Possible"<<endl;
        for(i=1; i <= m; ++i){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
