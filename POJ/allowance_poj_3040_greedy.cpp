#include <iostream>
#include <algorithm>
using namespace std;
struct Coin{
    int val;
    int cnt;
};
struct CoinCmp{
    bool operator()(const Coin &a, const Coin &b){
        return a.val < b.val;
    }
};
Coin coins[20];
// 递归代码改为 循环代码应该效率会高很多，还有cin 输入的问题
bool update(int total, int C, int cur){
    if(total >= C) return true;
    if(cur < 0) return false;
    int mycnt = min((C-total)/coins[cur].val, coins[cur].cnt);
    coins[cur].cnt -= mycnt;
    if(update(total + mycnt * coins[cur].val, C, cur-1))
        return true;
    if(coins[cur].cnt > 0){
        coins[cur].cnt --;
        return true;
    }
    coins[cur].cnt += mycnt;
    return false;
}

int main(){
    int N, C;
    cin>> N>> C;
    int i, j, k;
    for(i = 0; i < N; ++i){
        cin>>coins[i].val>>coins[i].cnt;
    }
    sort(coins, coins + N, CoinCmp());
    int res = 0;
    for(i = N-1; i >= 0; ){
        if(C <= coins[i].val){
            res += coins[i].cnt;
            i--;
            continue;
        }
        if(update(0, C, i)){
            res += 1;
            if(coins[i].cnt == 0) i--; //这个位置已经迭代完
        }else{ // 已经无解了
            break;
        }
    }

    cout<<res<<endl;
    return 0;
}
