#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>


using namespace std;
int T, D, I, M, N;
int a[100][256];
int myMin(int a, int b){
    if(a < 0) return b;
    if(b < 0) return a;
    return min(a,b);
}
int main(){
    cin>>T;
    int t,i,j,k;
    for(t = 1; t <= T; ++t){
        cin>> D>>I>>M>>N;
        vector<int> arr(N);
        for(i = 0; i < N; ++i) 
            cin>>arr[i];
        memset(a, -1, sizeof(a));
        for(i = 0; i < 256; ++i)
            a[0][i] = 0;
        /*a[0][arr[0]] = 0;
        j = arr[0];
        for(k = j; k >=0 && j-k <= M; --k){
            a[0][k] = abs(arr[0] - k);
        }
        for(k = j; k < 256 && k-j <= M; ++k){
            a[0][k] = abs(arr[0] - k);
        }*/
        for(i = 0; i < N; ++i){
            for(j = 0; j < 256; ++j){
                if(a[i][j]==-1) continue;
                //Delete
                a[i+1][j] = myMin(a[i][j] + D, a[i+1][j]);

                //Edit 先改变再增加, 所以要多开几个0-255的循环，每个循环里做删除更改添加
                //Case:
                // 255 6 10 3
                // 64 14 54
                // 最优方案 64 54 44 54
                // 

                for(k = j; k >=0 && j-k <= M; --k){
                    a[i+1][k] = myMin(a[i+1][k], a[i][j]+abs(arr[i]-k));
                }
                for(k = j+1; k < 256 && k-j <= M; ++k){
                    a[i+1][k] = myMin(a[i+1][k], a[i][j]+abs(arr[i]-k));
                }
 
                //No change
                if(abs(arr[i]- j) <= M){//这里不能偷懒，必须打上括号
                    if(i > 0) a[i+1][arr[i]] = myMin(a[i][j], a[i+1][arr[i]]);
                    else if(arr[i]==j) a[i+1][arr[i]] = 0;
                    //a[i+1][arr[i]] = myMin(a[i][j], a[i+1][arr[i]]);
                }else if(M > 0){ // add
                    a[i+1][arr[i]] = myMin(a[i][j]+ I*((abs(arr[i]-j)-1)/M), a[i+1][arr[i]]);
                    /*if(arr[i]==50){
                        cout<<a[i+1][arr[i]]<<endl;
                    }*/
                }
           }
        }
        /*for(i = 1; i <= N; ++i){
            for(j = 0; j < 256; ++j)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        int res = -1;
        for(i = 0; i < 256; ++i){
            res = myMin(res, a[N][i]);
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
