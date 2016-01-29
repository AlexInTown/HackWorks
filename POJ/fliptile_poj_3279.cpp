#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int M, N;
bool arr[15][15];
bool flip[15][15];
bool res[15][15];
int minFlip = 225;
bool get(int x, int y){
    int flipCnt = arr[x][y] + flip[x][y];
    if(x > 0){
        flipCnt += flip[x-1][y];
    }
    if(y > 0){
        flipCnt += flip[x][y-1];
    }
    if(x < M-1){
        flipCnt += flip[x+1][y];
    }
    if(y < N-1){
        flipCnt += flip[x][y+1];
    }
    return flipCnt % 2;
}
int main(){
    int i,j,k;
    int val;
    scanf("%d%d", &M, &N);
    for(i = 0; i < M; ++i){
        for(j = 0; j < N; ++j){
            scanf("%d", &val);
            arr[i][j] = val;
        }
    }
    int flipCnt;
    bool ok;
    for(i = 0; i < (1<<N); ++i){   //输出字典序最小
        flipCnt = 0;
        ok = 1;
        memset(flip, 0, sizeof(flip));
        for(j = 0; j < N; ++j){
            flip[0][N-1-j] = (i>>j) & 1;
            flipCnt += flip[0][N-1-j];   // 注意这里一定要加上
        }
        for(j = 1; j < M; ++j){
            for(k = 0; k < N; ++k){
                flip[j][k] = get(j-1, k);
                flipCnt += flip[j][k];
            }
        }
        for(k = 0; k < N; ++k){
            if(get(M-1, k)){
                ok = 0; break;
            }
        }
        //if(ok || i==0)
        /*)if(ok)
        for(j = 0; j < M; ++j){
            for(k = 0; k < N; ++k){
                printf("%d ", flip[j][k]);
            }
            printf("\n");
        }
        printf("flipCnt=%d\n", flipCnt);*/
        if(ok && flipCnt < minFlip){
            minFlip = flipCnt;
            memcpy(res, flip, sizeof(flip));
        }
    }
    if(minFlip < 225){
        for(i = 0; i < M; ++i){
            for(j = 0; j < N; ++j){
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
