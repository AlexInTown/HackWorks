#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define X first
#define Y second

typedef long long LL;

template<typename T>
class BIT{
    T * arr;
    int n;
public:
    BIT(int n){
        arr = new T[n+1];
        this->n = n;
        memset(arr, 0, sizeof(T) * n);
    }
    void add(int i, T x){
        while(i <= n){
            arr[i] += x;
            i += i & (-i);
        }
    }
    T get_sum(int i){
        T res = 0;
        while(i){
            res += arr[i];
            i -= i&(-i);
        }
        return res;
    }
    ~BIT(){
        delete [] arr;
    }
};

LL arr[100000];
LL ordered[100000];

int main(){
    int n;
    scanf("%d", &n);
    int i;
    int r,h;
    for(i = 0; i < n;++i){
    	scanf("%d%d", &r, &h);
	arr[i] = r;
	arr[i] *= r * h;
    }
    memcpy(ordered, arr, n);
    sort(ordered, ordered + n);
    i = n;
    int sz;
    while(i){
    	sz = i;
	i -= i & (-i);
    }
    sz = sz << 1;
    BIT<LL> bit(sz);
    int idx;
    LL res = 0;
    set<LL> added;
    for(i = 0; i < n; ++i){
    	idx = lower_bound(ordered, ordered+n, arr[i]) - ordered;
    	if(added.find(arr[i]) == added.end()) {
	    bit.add(idx+1, arr[i]);
	    added.insert(arr[i]);
	} 
	printf("%d\n", bit.get_sum(idx+1));
	res = max(res, bit.get_sum(idx+1));

    }
    printf("%.9f", res * M_PI);
    return 0;
}
