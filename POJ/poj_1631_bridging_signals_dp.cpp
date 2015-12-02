#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
class Comp{
public:
    bool operator()(const int &a, const int &b){
        return arr[a] < arr[b];
    }
};
int my_upper_bound(vector<int> & vi, int start, int end, int key){
    
    int mid;
    while(start < end){
        mid = start + (end -start)/2;
        if(!Comp()(key,vi[mid])){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}
//找到第一个小于等于的, 而插入的位置是upper_bound
int LIS(){
    int i;
    vector<int> idx;
    for(i = 0; i < arr.size(); ++i){
        int toInsert = my_upper_bound(idx, 0, idx.size(), i);
        if(toInsert == idx.size()){
            idx.push_back(i);
        }else {
            idx[toInsert] = i;
        }
    }
    return idx.size();
}
int T, N;
int main(){
    cin>>T;
    int temp;
    for(int t = 0; t < T; ++t){
        cin>> N;
        arr.clear();
        for(int i = 0; i < N; ++i){
            cin>>temp;
            arr.push_back(temp);
        }
        cout<<LIS()<<endl;
    }
    return 0;
}
