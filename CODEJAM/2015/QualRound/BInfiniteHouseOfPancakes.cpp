#include <iostream>
#include <sstream>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

#define INF (1<<29)

long long dp[1001];
void runDP(){
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(int i = 2; i <=1000; ++i ){
        dp[i] = min(max(dp[i/2], dp[i-i/2])+1, (long long) i);
    }
}
void main2(void){
    long long ans = -1;
    int n;
    cin>>n;
    int i;
    int val;
    REP(i, n){
        cin>>val;
        ans = max(ans, dp[val]);
    }
    gout << ans << endl;
}

int main(void){
    int number_of_test_cases,i;
    runDP();
    scanf("%d",&number_of_test_cases);
    REP(i,number_of_test_cases) main2();
    return 0;
}

