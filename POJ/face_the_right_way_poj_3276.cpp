#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int N;
char str[5000];
bool flip[5000];
char buffer[10];
int main(){
    int i;
    scanf("%d", &N);
    for(i = 0;  i < N; ++i){
        scanf("%s", buffer);
        str[i] = buffer[0];
    }
    int size, j;
    int minCnt = N;
    int minCntSize = 1;
    for(size = 1; size <= N; ++size){
        int cnt = 0;
        bool success = 1;
        int covered_cnt = 0;
        memset(flip, 0, N);
        for(i = 0; i < N; ++i){
            if(i >= size){
                covered_cnt -= flip[i-size];
            }
            //printf("  i=%d  cov=%d ", i, covered_cnt);
            if((covered_cnt%2)^(str[i]=='B')){ // back
                if(i + size <= N){
                    flip[i] = 1;
                    covered_cnt ++;
                    cnt ++;
                }else{
                    success = 0;
                }
            }
            //printf("%d \n", flip[i]);
        }
        //printf("size=%d cnt=%d suc=%d\n", size, cnt, success); 
        if(success && cnt < minCnt) {
            minCnt = cnt;
            minCntSize = size;
        }
    }
    printf("%d %d\n", minCntSize, minCnt);
    return 0;
}
