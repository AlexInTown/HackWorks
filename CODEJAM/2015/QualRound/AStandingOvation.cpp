#include <iostream>
#include <sstream>
#include <string>
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

void main2(void){
    int ans = 0;
    int smax;
    string s;
    cin>>smax>>s;
    int i;
    int cur = 0;
    REP(i, s.size()){
        if(cur < i) {
            ans += i - cur;
            cur = i;
        }
        cur += s[i] - '0';
    }
    gout << ans << endl;
}

int main(void){
    int number_of_test_cases,i;
    scanf("%d",&number_of_test_cases);
    REP(i,number_of_test_cases) main2();
    return 0;
}

