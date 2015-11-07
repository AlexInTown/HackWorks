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
#include <queue>

using namespace std;

int BFS(int n, int m){
    queue<int> q;
    int res = 0;
    q.push(n);
    q.push(-1);
    bool visited[10001];
    memset(visited, 0, sizeof(visited));
    while(q.size() > 0){
        int v = q.front();
        if(v==-1){
            res ++;
            if(q.size() > 1){
                q.push(-1);
                q.pop();
                v = q.front();
            }
            else break;
        }
        //cout<<v<<endl;
        visited[v] = true;
        if(v==m){
            return res;
        }
        q.pop();
        if(v-1 > 0 && !visited[v-1]) q.push(v-1);
        if(v*2 <= 10000 && !visited[v<<1]) q.push(v<<1);
    }
    return -1;
}

int main()
{
    int n, m;
    cin>>n>>m;
    cout<<BFS(n, m)<<endl;
    return 0;
}
