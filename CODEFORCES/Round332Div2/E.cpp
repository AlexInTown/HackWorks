#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long dp[1<<13][13];
struct LCA{
    int a, b, c;
};
vector<pair<int, int> > edges;
vector<LCA> lcas;
int N, M, Q;

void solve(){
    int i,j,k;
    for(j = 0; j < N; ++j)
        dp[0][j] = 1;
    int left, right;
    for(i = 1; i < (1<<N); ++i){
    	for(j = 0; j < N; ++j){
	    dp[i][j] = 0;
	    if((i>>j) & 1){
	    	dp[i][j] = dp[(i^(1<<j))][j];
		continue;
	    }
	    left = i;
	    do{
	    	bool valid = true;
		right = left ^i;
	    	for(k = 0; k < M&&valid; ++k){
		    if( ((left>>edges[k].first)&1)  &&  ((right>>edges[k].second)&1)
		    ||((right>>edges[k].first)&1)  &&  ((left>>edges[k].second)&1))
		    	valid = false;

		}
		for(k = 0; k < Q&& valid; ++k){
	 	    if(lcas[k].c == lcas[k].a){
		    	
		    }
		    if(j == lcas[k].c){
			if( !((left>>lcas[k].a)&1)  &&  ((right>>lcas[k].b)&1)
		    	||((right>>lcas[k].a)&1)  &&  ((left>>lcas[k].b)&1))
			    valid = false;
		    }
		}
	    	dp[i][j] += dp[left][j] * dp[right][j];
	    	next = (next-1)	& i;
	    }while(next > 0);
	}
    }
}


int main(){
    scanf("%d%d%d", &N, &M, &Q);
    int i,j;
    int a, b, c;
    for(i = 0; i < M; ++i){
    	scanf("%d%d", &a, &b);
	a--; b --;
	edges.push_back(make_pair(a, b));
    }
    LCA lca;
    for(i = 0; i < Q; ++i){
    	scanf("%d%d%d", &a, &b, &c);
	if(a==b && b==c) continue;
	a--; b--; c--;
	if(b == c) swap(a, b);
	lca.a = a; lca.b = b; lca.c = c;
	
	lcas.push_back(lca);
    }

    return 0;
}
