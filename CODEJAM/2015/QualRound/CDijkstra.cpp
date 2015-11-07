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
string ded[10000];
string ded_flag[10000];
int trans[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
bool flag[4][4] = {{1, 1, 1, 1}, {1, 0, 1, 0}, {1, 0, 0, 1}, {1, 1, 0, 0}};
void main2(void){
    int L, X;
    cin>>L>>X;
    string s;
    cin>> s;
    int i,j;
    stringstream ss;
    for(i = 0; i < X; ++i){
        ss<<s;
    }
    s = ss.str();
    //cout<<ss<<endl;
    //cout<<"asdfadsfsad"<<endl;
    for(i = 0; i < L*X; ++i){
        switch(s[i]){
            case '1': s[i] = 0; break;
            case 'i': s[i] = 1; break;
            case 'j': s[i] = 2; break;
            case 'k': s[i] = 3; break;
        }
        //cout<<(int)s[i]<<endl;
    }
    //cout<<s<<endl;
    for(i = 0; i < L*X; ++i){
        ded[i].resize(L*X);
        ded_flag[i].resize(L*X);
        ded[i][i] = s[i];
        ded_flag[i][i] = 1;
        for(j = i+1; j < L*X; ++j){
            ded[i][j] = trans[ded[i][j-1]][s[j]];
            ded_flag[i][j] =!(ded_flag[i][j-1] ^ flag[ded[i][j-1]][s[j]]);
            //if(i==6 && j==L*X-1) cout<<"ded_flag"<<(int)ded[i][j]<<" "<<(int)ded_flag[i][j]<<endl;
            //cout<<(int)ded[i][j];
        }
        //cout<<endl;
    }
    bool res = false;
    if(ded_flag[0][L*X-1] == 0 && ded[0][L*X-1] == 0)
    for(i = 0; i < L*X-1; ++i){
        for(j = i +1; j < L*X-1; ++j){
            //if(i==2&& j==5){
            //cout<<(int)ded[0][i]<<(int)ded[i+1][j]<<(int)ded[j+1][L-1]<<endl;
            //cout<<(int)ded_flag[0][i]<<(int)ded_flag[i+1][j]<<(int)ded_flag[j+1][L-1]<<endl;
            //}
            if(ded[0][i] == 1 && ded_flag[0][i] == 1 &&
            ded[i+1][j] == 2 &&  ded_flag[i+1][j] == 1 &&
            ded[j+1][L*X-1] == 3 && ded_flag[j+1][L*X-1] == 1){
                res = true; break;
            }
        }
    }
    string ans = res? "YES":"NO";
    gout << ans << endl;
}

int main(void){
    int number_of_test_cases,i;
    scanf("%d",&number_of_test_cases);
    REP(i,number_of_test_cases) main2();
    return 0;
}

