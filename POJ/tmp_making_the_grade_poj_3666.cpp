#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
vector<long long> costs;

/*class Comp{
public:
    bool operator()(const int &a, const int &b){
        return arr[a] < arr[b];
    }
};*/

int my_upper_bound(vector<int> & vi, int start, int end, int key){
    int mid;
    while(start < end){
        mid = start + (end -start)/2;
        //if(!Comp()(key,vi[mid])){
        if(arr[vi[mid]] <= arr[key] ){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}


//找到第一个小于等于的, 而插入的位置是upper_bound
int LIS(vector<int> & parent, int &seq_end){
    int i;
    parent.resize(arr.size());
    vector<int> idx;
    for(i = 0; i < arr.size(); ++i){
        int toInsert = my_upper_bound(idx, 0, idx.size(), i);
        if(toInsert == idx.size()){
            idx.push_back(i);
        }else {
            idx[toInsert] = i;
        }
        if(toInsert > 0) parent[i] = idx[toInsert-1];
        else parent[i] = -1;

    }
    seq_end = idx.back();
    return idx.size();
}


/*
 array: 1  3  2  4  5 3 9
parent: -1 -1 1 -1 -1 4 -1

int my_upper_bound2(vector<int> & vi, int start, int end, int key){
    int mid;
    while(start < end){
        mid = start + (end -start)/2;
        if(arr[vi[mid]] >= arr[key] ){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}

int LDS(vector<int> & parent, int &seq_end){
    int i;
    parent.resize(arr.size());
    vector<int> idx;
    for(i = 0; i < arr.size(); ++i){
        int toInsert = my_upper_bound2(idx, 0, idx.size(), i);
        if(toInsert == idx.size()){
            idx.push_back(i);
        }else {
            idx[toInsert] = i;
        }
        if(toInsert > 0) parent[i] = idx[toInsert-1];
        else parent[i] = -1;

    }
    seq_end = idx.back();
    return idx.size();
}*/

int cal_cost(vector<int> & parent, int seq_end){
    vector<bool> inList(arr.size());
    int i = seq_end;
    while( i >= 0){
        //cout<<i<<endl;
        inList[i] = true;
        i = parent[i];
    }
    costs.resize(arr.size());
    long long left_val = -1500000000;
    for(i = 0; i < arr.size(); ++i){
        if(inList[i]){
            left_val = arr[i];
            costs[i] = arr[i];
        }else{
            costs[i] = left_val;
        }
    }
    long long right_val = -1500000000;
    long long res = 0;
    for(i =  arr.size()-1; i >= 0; --i){
        if(inList[i]){
            right_val = arr[i];
        }else{
            res += min(abs(right_val - arr[i]), abs(costs[i] - arr[i]));
        }
    }
    return (int)res;
}
int N;
int main(){
    int temp, seq_end;
    cin>> N;
    arr.clear();
    for(int i = 0; i < N; ++i){
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> parent;
    LIS(parent, seq_end);
    int res = cal_cost(parent, seq_end);
    reverse(arr.begin(), arr.end());
    //LDS(parent, seq_end);
    /*for(int i = 0; i < N; ++i)
        cout<<parent[i]<<" ";
    cout<<endl;
    cout<<seq_end<<endl;*/
    LIS(parent, seq_end);
    res = min(cal_cost(parent, seq_end), res);
    cout<<res<<endl;
    return 0;
}
