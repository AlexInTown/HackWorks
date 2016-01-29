#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int N;
int arr[100];
int main(){
    scanf("%d", &N);
    int i = 0;
    for(i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    double res = arr[N-1];
    for(i = N-2; i >= 0; i--)
        res = 2*sqrt(res* arr[i]);
    printf("%.3f\n", res);

    return 0;
}
