#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <vector>
#include <map>

#include <functional>
#include <algorithm>
using namespace std;
//vector<double> vol;
class own_double_less : public std::binary_function<double,double,bool>
{
public:
  own_double_less( double arg_ = 1e-7 ) : epsilon(arg_) {}
    bool operator()( const double &left, const double &right  ) const
      {
        return (fabs(left - right) > epsilon) && (left < right);
    }
    double epsilon;
};
map<double,double,own_double_less> mymap;
typedef map<double,double,own_double_less>::iterator ITER;
int main(){
    int n, i;
    int r, h;
    scanf("%d", &n);
    double res = 0;
    for(i = 0; i < n; ++i){
        scanf("%d%d", &r, &h);
        double vol = 3.141592653589793;
        vol = vol*r*r*h;
        if(i == 0){
            mymap[vol] = vol;
            res = vol;
            continue;
        }
        double val;
        ITER iter = mymap.lower_bound(vol);
        if(iter != mymap.begin()){
            if(iter ->first  == vol){
                iter--;
                val = iter->second + vol;
                if(val > mymap[vol]) mymap[vol] = val;
            }else{
                iter--;
                val = iter->second + vol;
                mymap[vol] = val;
            }
        }else{
            mymap[vol] = vol;
        }
        res = max(res, mymap[vol]);
    }
    printf("%.9f", res);
    return 0;
}
