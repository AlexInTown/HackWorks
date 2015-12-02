#include <iostream>
#include <memory.h>

using namespace std;
int n, m;
// 多重背包，给出算是否可行，可以使用bool数组
// 可以使用int数组来加快运算
int a[100];
int c[100];

int dp[100001];
//dp[i][j] 用 ai 最多还能剩多少个 
int main(){
    scanf("%d%d", &n, &m);
    int i,j;
    while(n != 0 && m != 0){
        for(i = 0; i < n; ++i)
            scanf("%d",&a[i]);
        for(i = 0; i < n; ++i)
            scanf("%d",&c[i]);
        memset(dp, -1, sizeof(int)*(m+1));
        for(i = 0; i < n; ++i){
            dp[0] = c[i];
            for(j = 1; j <= m; ++j){
                if(dp[j] >= 0) 
                    dp[j] = c[i];
                else if(j >= a[i]) 
                    dp[j] = dp[j-a[i]] - 1;
                //else
                //   dp[cur][j] = -1;
            }
        }
        int res = 0;
        for(i = 1; i <=m; ++i)
            res += dp[i] >=0;
        printf("%d\n", res);
        scanf("%d%d", &n, &m);
    }
    return 0;
}

/*
int dp[2][100001];
//dp[i][j] 用 ai 最多还能剩多少个 
int main(){
    cin>>n>>m;
    int i,j;
    while(n != 0 && m != 0){
        for(i = 0; i < n; ++i)
            cin>>a[i];
        for(i = 0; i < n; ++i)
            cin>>c[i];
        bool cur = 1;
        memset(dp[0], -1, sizeof(int)*(m+1));
        //memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(i = 0; i < n; ++i){
            dp[cur][0] = c[i];
            for(j = 1; j <= m; ++j){
                if(dp[!cur][j] >= 0) 
                    dp[cur][j] = c[i];
                else if(j >= a[i]) 
                    dp[cur][j] = dp[cur][j-a[i]] - 1;
                else
                    dp[cur][j] = -1;
            }
            cur = !cur;
        }
        int res = 0;
        for(i = 1; i <=m; ++i)
            res += dp[!cur][i] >=0;
        cout<<res<<endl;
        cin>>n>>m;
    }
    return 0;
}*/
