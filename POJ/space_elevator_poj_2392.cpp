#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
bool dp[2][40001];
struct Block{
    int h,a,c;
};
struct Comp {
    bool operator()(const Block&b, const Block& c){
        return b.a< c.a;
    }
};
Block blocks[400];
int N;

int main(){
    cin>>N;
    int i, j, k;
    for(i = 0; i < N; ++i){
        cin>>blocks[i].h>>blocks[i].a>>blocks[i].c;
    }
    sort(blocks, blocks+N, Comp());
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    //10 * 400
    bool cur = 1;
    for(i = 0; i < N; ++i){
        for(j = blocks[i].a; j >= 0; j --){
            dp[cur][j] = dp[!cur][j];
            if(dp[cur][j])
            for(k = 1; k <= blocks[i].c 
                && k*blocks[i].h+j <= blocks[i].a; ++k){
                dp[cur][k*blocks[i].h+j] |= dp[cur][j];
            }
        }
        cur = !cur;
    }

    for(i = 40000; i >= 0; --i)
        if(dp[!cur][i]) break;
    cout<<i<<endl;
    return 0;
}
