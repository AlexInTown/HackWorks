#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, x0, y0;
    cin>>n>>x0>>y0;
    int i;
    vector<double> x(n), y(n);
    map<double, int> counts;
    int verti_count = 0;
    for(i =0; i < n; ++i){
        cin>>x[i]>>y[i];
        x[i] -= x0;
        y[i] -= y0;
        if(x[i] == 0) verti_count++;
        else counts[y[i]/x[i]] ++;
    }
    int res = counts.size();
    if(verti_count > 0) res++;
    cout<<res<<endl;
    return 0;
}
