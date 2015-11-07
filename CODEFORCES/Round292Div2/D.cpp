#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <memory.h>
using namespace std;
//priority queue: (degree, index) as the key
//update key: delete and insert new node
set<pair<int,int> > q;
map<int, int> d;
vector<string> g;
vector<pair<int,int> > e;
typedef set<pair<int,int> >::iterator ITER;
int n, m;
int countDegree(int i, int j){
    if(i < 0 || i >= n|| j <0 || j >= m || g[i][j]!='.') return 0;
    int res = 0;
    if(i > 0 && g[i-1][j]=='.'){
       res ++; 
    }
    if(i < n-1 && g[i+1][j]=='.'){
       res ++; 
    }
    if(j > 0 && g[i][j-1]=='.'){
       res ++; 
    }
    if(j < m-1 && g[i][j+1]=='.'){
       res ++; 
    }
    return res;
}
void decDegree(int i, int j){
    if(i < 0 || i >= n || j < 0|| j <=m || g[i][j]!='.') return;
    int degree, id;
    id = i*m+j;
    degree = d[id];
    d[id]--;
    q.erase(make_pair(degree, id));
    --degree;
    if(degree>0){
        q.insert(make_pair(degree, id));
    }
}
void setGraph(int i, int j){
    int degree, id;
    if(i > 0 && g[i-1][j]=='.'){
        g[i-1][j] = '^';
        g[i][j] = 'v';
        id = (i-1)*m+j;
    }else if(i < n-1 && g[i+1][j]=='.'){
        g[i+1][j] = 'v';
        g[i][j] = '^';
        id = (i+1)*m+j;
    }else if(j > 0 && g[i][j-1]=='.'){
        g[i][j-1] = '<';
        g[i][j] = '>';
        id = (i)*m+j-1;
    }else if(j < m-1 && g[i][j+1]=='.'){
        g[i][j+1] = '>';
        g[i][j] = '<';
        id = (i)*m+j+1;
    }
    degree=d[id];
    d[id]--;
    q.erase(make_pair(degree, id));
    decDegree(i-1, j);
    decDegree(i+1, j);
    decDegree(i, j-1);
    decDegree(i, j+1);
}

int main()
{
    cin>>n>>m;
    string s;
    int i,j;
    for(i = 0; i < n; ++i){
        cin>>s;
        g.push_back(s);
    }
    int degree;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            degree = countDegree(i,j);
            if(degree==0) continue;
            q.insert(make_pair(degree,i*m+j));
            d[i*m+j] = degree;
        }
    }
    bool res = true;
    while(!q.empty()){
        ITER iter = q.begin();
        i = iter->second/m;
        j = iter->second%m;
        cout<<"d"<<iter->first<<" i"<<i<<" j"<<j<<endl;

        if(iter->first==1){
            // set the graph
            // update the degree
            setGraph(i,j);
            q.erase(iter);
        }else{
            res = false;
            break;
        }
    }
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j){
            if(g[i][j] == '.') {
                res = false;
                break;
            }
        }
    if(res){
        for(i = 0; i < n; ++i){
            cout<<g[i]<<endl;
        }
    }else{
        cout<<"Not unique"<<endl;
    }

    return 0;
}

