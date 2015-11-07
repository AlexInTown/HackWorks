#include <iostream>
#include <memory.h>
#include <vector>
#include <cstdio>
#include <limits>
//#include <unordered_set>
#include <set>
#include <map>
using namespace std;

set<pair<int,int> > edges;

vector<int> T;
vector<vector<int> > G;
//double dp[100000][100000];
map<pair<int,int>, double> dp;
typedef map<pair<int,int>, double>::iterator ITER;


double getWeightedTime(int a, int b){
    //if(dp[a][b] > 0) return dp[a][b];
    //printf("geting weighted time %d %d\n", a, b);
    ITER iter =  dp.find(make_pair(a,b));
    if(iter!= dp.end()){printf(" %d %d %lf", a, b, iter->second); return iter->second;}
    if(G[b].size()==1) return T[b];
    int i;
    double sum = 0.0;
    printf("%d has: ", b);
    for(i = 0; i < G[b].size(); ++i);
        printf("%d,", G[b][i]); 
    printf("\n");
    for(i = 0; i < G[b].size(); ++i){
        if(G[b][i] == a) continue;
        sum += getWeightedTime(b, G[b][i]);
    }
    //printf("getting weights\n");
    sum /= G[b].size()-1;
    sum += T[b];
    dp.insert(make_pair(make_pair(a,b), sum));
    printf(" %d %d %lf", a, b, sum);
    return sum;
}
void printG(){
    for(int i = 0; i < G.size(); ++i){
        printf("%d: ", i); 
        for(int j = 0; j < G[i].size(); ++j)
            printf("%d ", G[i][j]);
        printf("\n");
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int i,j,k;
    T.resize(N);
    G.resize(N, vector<int>());
    for(i = 0; i < N; ++i)
        scanf("%d", &T[i]);
    int a,b;
    for(i = 0; i < N-1; ++i){
        scanf("%d %d", &a, &b);
        --a;--b;
        edges.insert(make_pair(a,b));
        edges.insert(make_pair(b,a));
        G[a].push_back(b);
        G[b].push_back(a);
        //printf("%d, %d\n", a,b);
    }
    printG();
    int minId = -1;
    double minValue = numeric_limits<double>::max();
    double value,value1, value2;

    for(set<pair<int,int> >::iterator iter = edges.begin(); iter!=edges.end(); ++iter){
        printf("begin calculation\n");
        value2 = getWeightedTime(iter->first, iter->second);
        value1 = getWeightedTime(iter->second, iter->first);
        printf("%d %d %.5f %.5f\n", iter->first, iter->second, value1, value2);
        /*value = value1 / G[iter->second].size() + value2;
        if(value < minValue)
        {
            minValue = value;
            minId = iter->second;
        }*/
        value = value2/G[iter->first].size() + value1;
        if(value <  minValue){
            minValue = value;
            minId = iter->first;
        }
    }
    printf("%d\n", minId+1);
    return 0;
}
