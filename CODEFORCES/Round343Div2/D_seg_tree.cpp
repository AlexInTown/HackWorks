#include <bits/stdc++.h>
using namespace std;
typedef LL long long;
typedef pair<LL, int> PLI;
const int MAXN = 100017;
PLI arr[MAXN];
LL tree[MAXN];
int N;
void update(int idx, LL val, int s = 0, int e = N){
    int mid = s+ ((e-s)>>1);
    if(idx==s || e-s==1){
    	tree[idx] = val;
    }	

    if(idx < mid){
    }
}

int main(){
    return 0;
}
