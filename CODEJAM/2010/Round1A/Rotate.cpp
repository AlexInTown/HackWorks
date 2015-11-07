#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;


int T, N, K;
bool check(vector<string> &mat, int x, int y, char c){
    int i,j;
    bool res = false;
    bool temp = true;
    //printf("x=%d y=%d c=%c\n", x, y, c);
    if(x+K <= N){
    for(i = x; i < x+K; i++){
        if(mat[i][y]!=c){
            temp = false;
            break;
        }
    }
    res |= temp;
    }
    if(res) return true;
    temp = true;
    if(y+K<=N){
    for(i = y;  i < y+K; ++i)
        if(mat[x][i] != c){
            temp = false;
            break;
        }
    res |= temp;
    }
    if(res) return true;
    temp = true;
    if(x+K <= N && y+K <= N){
    for(i = 0; i < K; ++i){
        if(mat[x+i][y+i]!=c){
            temp = false;
            break;
        }
    }
    res |= temp;
    }
    if(x-K+1 >= 0 && y+K <=N){
        temp = true;
        for(i = 0; i < K; ++i){
            if(mat[x-i][y+i]!=c){
                temp = false;
                break;
            }
        }
        res |= temp;
    }
    return res;
}
int main(){
    cin >> T;
    vector<string> mat;
    int i,j;
    for(int t = 1; t<= T; ++t){
        cin>> N>> K;
        mat.clear();
        string s;
        for(i = 0; i < N; ++i){
            cin>>s;
            mat.push_back(s);
        }
        for(i = 0; i < N; ++i)
            for(j = i+1; j < N; ++j){
                swap(mat[i][j], mat[j][i]);
            }
        for(i = 0; i < N; ++i)
            for(j = 0; j < N/2; ++j){
                swap(mat[i][j], mat[i][N-1-j]);
            }
        /*for(i = 0; i < N; ++i){
            cout<<mat[i]<<endl;
        }
        cout<<endl;*/

        /*for(i = N-1; i > 0; --i){
            for(j = 0; j < N; ++j){
                if(mat[i][j]=='.' && mat[i-1][j] !='.'){
                    swap(mat[i][j], mat[i-1][j]);
                }
            }
        }*/
        int k;
        for(j = 0; j < N; ++j){
            k = N-1;
            for(i = N-1; i >= 0; --i){
                if(mat[i][j] != '.')
                    mat[k--][j] = mat[i][j];
            }
            for(; k >= 0; --k){
                mat[k][j] = '.';
            }
        }
        /*for(i = 0; i < N; ++i){
            cout<<mat[i]<<endl;
        }
        cout<<endl;*/

        bool red = false, blue = false;
        for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                if(mat[i][j]=='R'){
                    if(!red)
                        red |= check(mat, i, j, mat[i][j]);
                }else if(mat[i][j]=='B'){
                    if(!blue)
                        blue |= check(mat, i, j, mat[i][j]);
                }
                if(red && blue) break;
            }
        }
        if(red && blue){
            printf("Case #%d: Both\n", t);
        }else if(red){
            printf("Case #%d: Red\n", t);
        }else if(blue){
            printf("Case #%d: Blue\n", t);
        }else{
            printf("Case #%d: Neither\n", t);
        }


    }
    
    return 0;
}
