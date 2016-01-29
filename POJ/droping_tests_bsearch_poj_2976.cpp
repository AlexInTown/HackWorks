#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const double eps = 0.000001;
int n, k;
double avg;
struct Test{
    int a;
    int b;
};
struct Comp{
    bool operator()(const Test & t1, const Test& t2){
        return t1.a-t1.b*avg - t2.a + t2.b*avg > 0;
    }
};
Test tests[1000];
bool check(){
    sort(tests, tests+n, Comp());
    int i;
    double sum_val = 0.0;
    for(i = 0; i < n; ++i){
        sum_val += tests[i].a  - tests[i].b*avg;
        if(sum_val < 0){
            break;
        }
    }
    return n-i <= k;
}
int main(){
    scanf("%d%d", &n, &k);
    while(n + k > 0){
    int i;
    for(i = 0; i < n; ++i){
        scanf("%d", &tests[i].a);
    }
    for(i = 0; i < n; ++i){
        scanf("%d", &tests[i].b);
    }
    double l = 0;
    double r = 1.0;
    while(r-l > eps){
        //printf("%lf %lf %lf \n", l, r, avg);
        avg = (r+l)/2.0;
        if(check()){
            l = avg;
        }else{
            r = avg;
        }
    }
    int res = (avg+0.005) * 100;
    printf("%d\n", res);
    scanf("%d%d", &n, &k);
    }
    return 0;
}
