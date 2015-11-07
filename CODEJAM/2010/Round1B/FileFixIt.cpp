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
int N, M;

struct Node{
    map<string, Node *> childs;
};
void countNodes(Node *root, int &cnt){
    cnt+=root->childs.size();
    for(map<string, Node*>::iterator it = root->childs.begin();
        it != root->childs.end(); ++it){
        countNodes(it->second, cnt);
    }
}
void insert(Node *r, const string & s){
    int idx = s.find("/", 1);
    string sub;
    if(idx==string::npos) 
        sub = s.substr(1);
    else 
        sub = s.substr(1, idx-1);
    //cout<<sub<<endl;
    auto it = r->childs.find(sub);
    if(it == r->childs.end()){
        r->childs[sub] = new Node();
    }
    if(idx!=string::npos) insert(r->childs[sub], s.substr(idx));
}
void main2(void){
    cin>>N>>M;
    int i,j;
    string s;
    Node *r = new Node();
    REP(i, N) {
        cin>> s;
        insert(r, s);
    }
    int cnt = 0;
    countNodes(r, cnt);
    REP(i, M){
        cin>> s;
        insert(r, s);
    }
    int newCnt = 0;
    countNodes(r, newCnt);
    
    int ans = newCnt-cnt;
    gout << ans << endl;
}

int main(void){
    int number_of_test_cases,i;
    scanf("%d",&number_of_test_cases);
    REP(i,number_of_test_cases) main2();
    return 0;
}

