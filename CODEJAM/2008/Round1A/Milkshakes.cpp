#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Comp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second || a.second==b.second && a.first < b.first;
    }
};
int N, M, T;
int main(){
    scanf("%d", &T);
    int t, i, n, j;
    for(t = 1; t <= T; ++t){
        scanf("%d", &N);
        scanf("%d", &M);
        //printf("%d %d\n", N, M);
        vector<int> types(N+1, 0);
        vector<bool> solved(M, false);
        vector<bool> hasOne(M, false);
        vector<vector<pair<int, int> > > favors(M); 
        pair<int, int> temp;
        for(i = 0; i < M; ++i){
            scanf("%d", &n);
            for(j = 0; j < n;++j){
                scanf("%d%d", &temp.first, &temp.second);
                if(temp.second) hasOne[i] = true;
                favors[i].push_back(temp);
            }
            sort(favors[i].begin(), favors[i].end(), Comp());
            //for(j = 0; j < n; ++j){
            //    printf("(%d,%d) ", favors[i][j].first, favors[i][j].second);
            //}
            //printf("\n");
        }

        for(i = 0; i < M; ++i){
            if(favors[i].size()==1&& favors[i][0].second==1){
                solved[i] = true;
                types[favors[i][0].first] = true;
            }
        }
        for(i = 0; i < M; ++i){
            if(solved[i] || !hasOne[i]) continue;
            for(j = 0; j < favors[i].size(); ++j){
                if(types[favors[i][j].first] == favors[i][j].second){
                    solved[i] = true;
                    break;
                }
            }
            if(!solved[i]){
                if(favors[i].back().second == 1){
                    solved[i] = true;
                    types[favors[i].back().first] = true;
                }
            }
        }
        bool result = true;
        for(i = 0; i < M; ++i){
            if(hasOne[i]) continue;
            for(j = 0; j < favors[i].size(); ++j){
                if(types[favors[i][j].first] == favors[i][j].second){
                    solved[i] = true;
                    break;
                }
            }
            if(!solved[i]){
                result = false;
                break;
            }
        }
        if(result){
            printf("Case #%d:", t);
            for(i = 1; i <= N; ++i){
                printf(" %d", types[i]);
            }
            printf("\n");
        }else{
            printf("Case #%d: IMPOSSIBLE\n", t);        
        }
    }
    
    return 0;
}
