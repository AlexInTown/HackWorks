#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> fn;

vector<pair<LL, LL> > res;

void calculate(LL y){
    fn.clear();
    fn.push_back(0);
    LL i = 1, j = y;
    LL v1, v2;
    while(1){
    	v1 = (y + fn.back());
	v2 = ((i*i + i)/2);
    	j =  v1/ v2;
	//printf("i = %d j = %d fn(i)=%ld\n", i, j, fn.back());
	if(i > j){
	    break;
	}

	if( v1 == v2 * j){
	    // a valid result.
	    res.push_back(make_pair(i,j));
	}
	i++;
	v1 = (i-1)/2 * ((i-1)/2+1);
	v1 += (i>>1)*(i>>1);
	fn.push_back(v1+fn.back());
    }
    int k = res.size();
    for(k = k-1; k >= 0; k--){
    	if(res[k].first != res[k].second)
    	    res.push_back(make_pair(res[k].second, res[k].first));
    }
}

int main(){
    LL y;
    scanf("%lld", &y);
    //cin>>y;
    calculate(y);
    printf("%d\n", res.size());
    //cout<<res.size()<<endl;
    for(int i = 0; i < res.size(); ++i){
    	printf("%lld %lld\n", res[i].first, res[i].second);
	//cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;

}

