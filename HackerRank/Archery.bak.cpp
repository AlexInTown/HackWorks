#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
vector<double> rads;
vector<int> counts;
vector<pair<double, double> > segs;
int main() {
    int N, M;
    scanf("%d", &N);
    vector<int> radius(N);
    int i,j, x, y;
    double r;
    for(i = 0; i < N; ++i)
        scanf("%d", & radius[i]);
    scanf("%d", &M);
    pair<double, double> pr;
    for(i = 0; i < M; ++i){
        scanf("%d%d", &x, &y);
        r  = x*x;
        r = sqrt(r+y*y);
        rads.push_back(r);
        pr.first = r;
        scanf("%d%d", &x, &y);
        r  = x*x;
        r = sqrt(r+y*y);
        rads.push_back(r);
        pr.second = r;
        if(pr.first > pr.second) swap(pr.first, pr.second);
        segs.push_back(pr);
    }
    sort(rads.begin(), rads.end());
    rads.resize(unique(rads.begin(), rads.end())- rads.begin());
    counts.resize(rads.size());
    int start, end;
    for(i = 0; i < segs.size(); ++i){
        start = lower_bound(rads.begin(), rads.end(), segs[i].first)-rads.begin();
        end = lower_bound(rads.begin(), rads.end(), segs[i].second)-rads.begin();
        for(j = start; j < end; ++j)
            counts[j]++;
    }
    /*
    for(i = 0; i < counts.size(); ++i)
        printf("%d=%lf ", counts[i], rads[i]);
    printf("\n");
    */
    int ret = 0;
    for(i = 0; i < N; ++i)
    {
        vector<double>::iterator iter = upper_bound(rads.begin(), rads.end(), radius[i]);
        if(iter==rads.begin()) continue;
        int idx = (int)(iter-rads.begin());
        if(rads[idx-1] == radius[i]) continue;
        //printf("%d\n",idx); 
        ret += counts[idx-1];
    }
    printf("%d\n", ret);
    return 0;
}

