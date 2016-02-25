#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>
using namespace std;
vector<string> board;
int main(){
    int n;
    cin>>n;
    int i, j;
    string s;
    long long res = 0;
    for(i = 0; i < n; ++i){
        cin>>s;
        board.push_back(s);
    }
    long long row, col;
    for(i = 0; i < n; ++i){
        row = 0; col = 0;
        for(j = 0; j < n; ++j){
            if(board[i][j] == 'C'){
                row ++;
            }
            if(board[j][i] == 'C')
                col++;
        }
        res += row * (row - 1) /2;
        res += col * (col -1) /2;
    }
    cout<<res<<endl;
    return 0;
}
