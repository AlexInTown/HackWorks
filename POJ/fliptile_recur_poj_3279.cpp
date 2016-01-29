#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int M, N;
int arr[15][15];
void set_board(int x, int y){
    if(x > 0){
        arr[x-1][y] = ! arr[x-1][y];
    }
    if(y > 0){
        arr[x][y-1] = ! arr[x][y-1];
    }
    if(x < M-1){
        arr[x+1][y] = ! arr[x+1][y];
    }
    if(y < N-1){
        arr[x][y+1] = ! arr[x][y+1];
    }
    arr[x][y] = ! arr[x][y];
}
bool flip[15][15];

bool check(){
    int i,j;
    for(i = 0; i < M; ++i)
        for(j = 0; j< N; ++j)
            if(arr[i][j]) return false;
    //printf("check res %d\n", 1);
    return true;
}
bool solve(int x, int y){
    if(y==N){
        y = 0;
        x += 1;
    }
    //printf("x=%d, y=%d\n", x, y);
    /*for(int i = 0; i < M; ++i){
        for(int j = 0;j < N; ++j){
            printf("%d ", flip[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < M; ++i){
        for(int j = 0;j < N; ++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    
    if(x==M){
        return check();
    }
    if(solve(x, y+1))
        return true;
    flip[x][y] = 1;
    set_board(x, y);

    if(solve(x, y+1))
        return true;
    flip[x][y] = 0;
    set_board(x,y);
    return false;
}
int main(){
    int i,j;
    scanf("%d%d", &M, &N);
    for(i = 0; i < M; ++i){
        for(j = 0; j < N; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    memset(flip, 0, sizeof(flip));
    //printf("success=%d\n", solve(0, 0));
    solve(0,0);
    for(i = 0; i < M; ++i){
        for(j = 0; j < N; ++j){
            printf("%d ", flip[i][j]);
        }
        printf("\n");
    }
    return 0;
}
