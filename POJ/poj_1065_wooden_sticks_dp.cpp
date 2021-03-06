#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int T, N;

vector<int> idx;
vector<int> vi; 
struct Comp{
    bool operator()(const int &a, const int &b){
        return vi[a] >= vi[b];
    }
};

int LIS(vector<int> & vi){
    idx.resize(vi.size());
    int res = 0;
    int i;
    for(i = 0; i < vi.size(); ++i){
        int j = upper_bound(idx.begin(), idx.begin()+ res, i,Comp())-idx.begin();
        idx[j] = i;
        if(j == res) res++;
    }
    return res;
}

int main(){
    cin>>T;
    pair<int, int> pii;
    vector<pair<int, int> >  vpii;
    int i;
    for(int t = 0; t < T; ++t){
        cin>>N;
        vpii.clear();
        for(i = 0; i < N; ++i){
            cin>>pii.first>>pii.second;
            vpii.push_back(pii);
        }
        sort(vpii.begin(), vpii.end());
        vi.clear();
        for(i = 0; i < N; ++i){
            vi.push_back(vpii[i].second);
        }
        int res = LIS(vi);
        cout<<res<<endl;
    }
    return 0;
}

