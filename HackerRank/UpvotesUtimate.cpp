#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<int> arr(N);
    int i,j;
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int start = 0, descend_start = 0;
    for(i = 1; i <= K; ++i){
        if(i==K||arr[i] < arr[i-1]){
            sum += (i-start)*(i-start-1)/2;
            start = i;
        }
        if(i==K||arr[i] > arr[i-1]){
            sum -= (i-descend_start)*(i-descend_start-1)/2;
            descend_start = i;
        }
    }
    int leftAscCnt = 1, leftDescCnt = 1, rightAscCnt = 1, rightDescCnt = 1;
    for(i = 0, j = i+1; j < i+K && arr[j]>=arr[j-1]; ++j); leftAscCnt = j-i;
    for(i = 0, j = i+1; j < i+K && arr[j]<=arr[j-1]; ++j); leftDescCnt = j-i;
    for(i = K-2; i >=0 && arr[i]<=arr[i+1]; --i); rightAscCnt = K-i-1;
    for(i = K-2; i >=0  && arr[i]>=arr[i+1]; --i); rightDescCnt = K-i-1;
    printf("leftAsc=%d leftDesc=%d rightAsc=%d rightDesc=%d\n", leftAscCnt, leftDescCnt, rightAscCnt,  rightDescCnt);    
    printf("%d\n", sum);
    for(i = 0; i + K < N; ++i){
        if(arr[i] >= arr[i-1]) leftAscCnt--;
        if(arr[i] <= arr[i-1]) leftDescCnt--;
        if(arr[i+K] > arr[i+K-1]) {rightAscCnt++; rightDescCnt = 1;}
        else if(arr[i+K] < arr[i+K-1]) {rightDescCnt++; rightAscCnt = 1;}
        else {
            rightAscCnt++; 
            rightDescCnt++;
        }
        if(leftDescCnt==1){
            for(j = i+2; j <= i+K && arr[j]>=arr[j-1]; ++j);
            leftAscCnt = j-i-1;
        }
        if(leftAscCnt==1){
            for(j = i+2; j <= i+K && arr[j]<=arr[j-1]; ++j);
            leftDescCnt = j-i-1;
        }

        if(rightAscCnt>K){
            rightAscCnt--; leftAscCnt++;
        }
        if(rightDescCnt>K){
            rightDescCnt--; leftDescCnt++;
        }
        printf("leftAsc=%d leftDesc=%d rightAsc=%d rightDesc=%d\n", leftAscCnt, leftDescCnt, rightAscCnt,  rightDescCnt);
        sum -= leftAscCnt;
        sum += rightAscCnt-1;
        sum += leftDescCnt;
        sum -= rightDescCnt-1;
        if(sum >= K*(K-1)/2) sum = K*(K-1)/2;
        printf("%d\n", sum);
    }
    return 0;
}



