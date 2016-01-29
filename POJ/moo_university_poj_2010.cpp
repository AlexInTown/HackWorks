#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,C,F;
struct Cow{
    int score;
    int cost;
};
struct Comp{
    bool operator()(const Cow&a, const Cow &b){
        return a.cost > b.cost;
    }
};
Cow cows[100005];
int values[100005];
void swapCow(Cow* cows, int i, int j){
    if(i == j) return;
    swap(cows[i].score, cows[j].score);
    swap(cows[i].cost, cows[j].cost);
}
void printCows(){
    int i;
    for(i = 0; i < C; ++i){
        printf("(%d,%d) ", cows[i].score, cows[i].cost);
    }
    printf("\n");
}
bool checkValid(int mid){
    int i,j = -1, k = C;
    for(i = 0; i < C; ++i){
        if(cows[i].score < mid){
            swapCow(cows, ++j, i);
        }
    }
    printf("mid=%d j=%d\n",mid, j);
    printCows();
    if(C-j-1 < N/2 +1) 
        return false;
    sort(cows+j+1, cows + C, Comp());
    printCows();
    long long totalCost = 0;
    for(k = C-1; C-k <= N/2+1; --k){
        totalCost += cows[k].cost;
    }
    printf("k=%d\n",k);
    if(totalCost > F)
        return false;
    sort(cows, cows+k+1, Comp());
    printCows();
    for(i = k; k+1-i<= N/2; --i){
        totalCost += cows[i].cost;
    }
    return totalCost <= F;

}
// 给定资金，每条牛对应的智力和花销一致，选N条，使得智力最高 
int main(){
    scanf("%d%d%d",&N,&C,&F);
    int i;
    for(i = 0; i < C; ++i){
        scanf("%d%d", &cows[i].score, &cows[i].cost);
        values[i] = cows[i].score;
    }
    sort(values, values+C);
    int l = 0, r = C, mid;
    int maxMedian = 0;
    while(l < r){
        mid = l + (r-l)/2;
        if(checkValid(values[mid])){
            maxMedian = max(maxMedian, values[mid]);
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    printf("%d\n", maxMedian);
    return 0;
}
