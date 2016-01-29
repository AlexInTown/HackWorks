#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
using namespace std;
map<int, int> covered;
void add_into_map(int val){
    if(covered.find(val) != covered.end()){
        covered[val] += 1;
    }else{
        covered[val] = 1;
    }
}
void del_from_map(int val){
    if(covered[val] > 1){
        covered[val] --;
    }else{
        covered.erase(val);
    }
}
int N;

int arr[1000000];
int main(){
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        covered[arr[i]] = 1;
    }
    int size = covered.size();
    int last = 0;
    int res = N+1;
    covered.clear();
    for(i = 0; i < N; ++i){
        add_into_map(arr[i]);
        while(covered.size() >= size){
            res = min(res, i - last + 1);
            del_from_map(arr[last]);
            last ++;
        }
    }
    printf("%d\n", res);
    return 0;
}
