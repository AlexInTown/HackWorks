#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <memory.h>

using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
LL  n, k; // 0<= k <= n <= 1e5

/*MOD reverse   p mod i  =  p - p/i*i
    p mod i = (- p/i * i) mod p
    x = 1/(i * (p mod i)) mod p
    multiply x to both side
    inv(i, p) = (-p/i) inv(p mod i, p)
    a dynamic programming  solution O(n)
*/


/**
 * 0 1 3 3 4  (n-1) plus
 * i to i+l  l <= n-1
 * 
 */

LL inv[100001];
LL fact[100001];
LL invFact[100001];

void Inverse(int n){
    memset(inv, 0, sizeof(inv));
    LL v;  
    int i;
    inv[1] = 1;
    for(i = 2; i <= n; ++i){
        v = MOD-MOD/i;
        v *= inv[MOD % i];
        inv[i] = v % MOD;
    }
}
void Fact(int n){
    int i;
    fact[0] = 1;
    LL v;
    for(i = 1; i <= n; ++i){
        v = fact[i-1];
        v *= i;
        fact[i] = v % MOD;
    }
}

void InvFact(int n){
    int i;
    invFact[0] = 1;
    LL v;
    for(i = 1; i <= n; ++i){
        v = invFact[i-1];
        v *= inv[i];
        invFact[i] = v %MOD;
    }
}

LL nchoosek(int n, int k){
    //cout<<"n"<<n<<" k"<<k<<endl;
    if(n < k || n<0) return 0;
    LL v;
    v = fact[n];
    v *= invFact[k];
    v %= MOD;
    v *= invFact[n-k];
    v %= MOD;
    return v;
}

void print(int a[], int n){
    int i;
    for(i = 0; i < n; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n>>k;
    string s;
    cin>>s;
    Inverse(n);
    Fact(n);
    InvFact(n);

    //print(inv, n);
    //print(invFact, n);
    int i,j;
    LL num, res = 0, temp;
    /*num = 0;
    for(i = 0; i+k+1 <= n; ++i){
        num += s[i]-'0';
        num %= MOD;
        temp = num * nchoosek(n-i-1,k-1);
    }*/
    if(k==0){
        for(i = 0; i < n; ++i){
            res *= 10;
            res += s[i]-'0';   
            res %= MOD;
        }
    }
    else
    for(i=0; i < n; ++i){
        num = 0;
        for(j=0; i+j < n; ++j){
            num = num *10;
            num += s[i+j]-'0';
            num %= MOD;
            if(i ==0 || i+j==n-1){
                temp = nchoosek(n-j-2, k-1);
            }else{
                temp = nchoosek(n-j-3, k-2);
            }
            //cout<<"num"<<num<<" nck"<<temp<<endl;
            temp = (temp * num) % MOD;
            res += temp;
            res %= MOD;
        }
    }
    cout<<res<<endl;
    return 0;
}
