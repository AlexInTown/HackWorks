#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <memory.h>
using namespace std;

int T, N;
bool wins(vector<int> &arr, map<int, bool> &cache, int cur){
    map<int,bool>::iterator iter = cache.find(cur);
    if(iter!=cache.end()) return iter->second;
    if((cur & (cur-1)) == 0) return false;
    int i, temp = cur;
    int prev = -1;
    bool asc = true;
    for(i = 0; i < N; ++i)
    {
       if(temp & 1){
            if(arr[i] < prev){
                asc = false;
                break;
            }
            prev = arr[i];
       }
       temp = temp >> 1;
    }
    if(asc){cache[cur] = false; return false;}
    temp = cur;
    bool res = false;
    for(i = 0; i < N; ++i){
        if(temp &1){
           if( !wins(arr, cache,  (1<<i)^cur)){
               res = true;
               break;
           }
        }
        temp = temp >> 1;
    }
    cache[cur] = res;
    return res;
}
int main(){
    scanf("%d", &T);
    int i,t;
    for(t = 0; t < T; ++t){
        scanf("%d", &N);
        vector<int> arr(N);
        for(i = 0; i < N; ++i){
            scanf("%d", &arr[i]);
        }
        map<int, bool> cache;
        if(wins(arr, cache, (1<<(N+1))-1)){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }
    
    return 0;
}
