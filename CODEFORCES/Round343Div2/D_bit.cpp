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
    T sum(int i){
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

int main(){
    int n;
    
    return 0;
}
