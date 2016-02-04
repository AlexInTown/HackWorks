#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
using namespace std;
map<int,int> idx;
int arr[100011];
int ord[100011];
int n;
int main(){
    cin>>n;
    int i;
    for(i = 0; i < n; ++i){
        cin>>arr[i];
	arr[i]--;
        ord[i] = arr[i];
    }
    sort(ord, ord+n);
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
    for(i = 0,j = -1; i < n; ++i){
    	if(ord[i] > b){
	    b = ord[i];
	}
	if(b - a == i-j){
	    res ++;
	    a = b;
	    j = i;
	}
    }
    cout<<res<<endl;
    return 0;
}
