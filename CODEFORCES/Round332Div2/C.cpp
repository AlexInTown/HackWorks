#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int idx[100011];
int arr[100011];
int ord[100011];
int n;
int main(){
    cin>>n;
    int i;
    for(i = 0; i < n; ++i){
        cin>>arr[i];
        ord[i] = arr[i];
    }
    sort(ord, ord+n);
    memset(idx, -1, sizeof(int)*n);
    idx[ord[0]] = 0;
    for(i = 1; i < n; ++i){
        if(ord[i] != ord[i-1])
            idx[ord[i]] = i;
    }
    for(i = 0; i < n; ++i){
        ord[i] = idx[arr[i]];
        idx[arr[i]]++;
        //cout<<ord[i]<<endl;
    }
    int res = 0, tmp,j;
    int a = -1, b= -1;
    for(i = 0; i < n; ++i){
        if(ord[i] != -1 && i > b){
           a = i; b = i; res++;
        }
        j = i;
        while(j!=-1 && ord[j] != j && ord[j] != -1){
            tmp = ord[j];
            ord[j] = -1;
            j = tmp;
            if(j > b) b = j;
        }
    }
    cout<<res<<endl;
    return 0;
}
