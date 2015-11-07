#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
using namespace std;
int T, N;
int main(){
    cin>>T;
    int i;
    for(int  t = 0; t < T; ++t){
        cin>> N;
        vector<int> a(N), b(N);
        for(i = 0; i < N; ++i){
            cin>>a[i];
        }
        for(i = 0; i < N; ++i){
            cin>>b[i];
        }
        int count = 0;
        for(i = 0; i < N; ++i){
            if(abs(b[i]-a[i]) > 1) count ++;
        }
        if(count % 2){
            cout<<"player-2"<<endl;
        }else{
            cout<<"player-1"<<endl;
        }

    }
    return 0;
}
