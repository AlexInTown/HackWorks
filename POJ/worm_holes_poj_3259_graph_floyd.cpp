#include<iostream>
#include<stdio.h>
using namespace std;
int F, N, M, W;
int arr[500][500];
int main(){
     int f,i,j;
     int s,e,t;
     scanf("%d", &F);
     for(f = 0; f < F; ++f){
          scanf("%d%d%d", &N, &M, &W);
          for(i = 0; i < N; ++i)
          for(j = 0; j < N; ++j)
               if(i==j) arr[i][j] = 0;
               else arr[i][j] = 5000000;
          for(i = 0; i < M; ++i){
               scanf("%d%d%d", &s, &e, &t);
               s--; e--;
               arr[s][e] = min(t, arr[s][e]);
               arr[e][s] = arr[s][e];
          }
          for(i = 0; i <W; ++i){     
               scanf("%d%d%d", &s, &e, &t);
               s--; e--;
               arr[s][e] = -t;
          }     
          for(e = 0; e < N; ++e)
          for(i = 0; i < N; ++i)
          for(j = 0; j < N; ++j)
          {
               if(arr[i][j] > arr[i][e]+arr[e][j]){
                    arr[i][j] = arr[i][e] + arr[e][j];
               }
          }
          bool res = false;
          for(i = 0; i < N; ++i)
               if(arr[i][i]  < 0) {
                    res = true;
                    break;
               }
          if(res){
               printf("YES\n");
          }else{
               printf("NO\n");
          }
     }

     return 0;
}

