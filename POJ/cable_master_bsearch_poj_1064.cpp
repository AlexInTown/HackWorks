#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int N, K;
double arr[10000];
const double eps = 0.00001;   // 使用eps 限定精度
bool equals(double a, double b){
    if (a > b) return a - b < eps;
    return b-a <eps;
}
int count(double len){
    int i;
    int cnt = 0;
    for(i = 0; i < N; ++i){
        cnt += (int)(arr[i]/len);
    }
    return cnt;
}

int main(){
    scanf("%d%d", &N, &K);
    int i; 
    double l = 0;
    double r = 0;
    for(i = 0; i < N; ++i){
        scanf("%lf", &arr[i]);
        r = max(r, arr[i]);
    }
    r += 1;
    double mid;
    while(!equals(l,r)){
        mid = (l+r)/2;
        int cnt = count(mid);
        if(cnt < K){
            r = mid;
        }else{
            l = mid;
        }
    }
     
    printf("%.2lf\n",  floor(r* 100) / 100.0 );   // 使用上限加上floor函数肯定可以***
    return 0;
}
