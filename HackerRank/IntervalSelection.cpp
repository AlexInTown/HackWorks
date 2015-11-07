/* Sample program illustrating input and output */

#include<iostream>
#include<vector>
#include <set>
#include <algorithm>
using namespace std;




struct Comp{
    bool operator()(const pair<int,int> &a, const pair<int, int> &b){
        return a.second < b.second || a.second==b.second && a.first < b.first;
    }
};

int main(void){

//Helpers for input and output
   int test;
   cin >> test;
   for(int t=0; t < test; t++){
      int N;
      cin >> N;
   
      vector<pair<int, int> >  intervals;
      pair<int, int> pr;
      for(int i = 0; i < N; i++){
          cin>>pr.first>>pr.second;
          intervals.push_back(pr);
      }
       if(N<=2) {cout<<N<<endl; continue;}
     //排序后保证只出现类似情况
     //[3, 6] [4, 10]  下一个为[5, 7] 重叠两次，应该把[4,10] 丢掉，插入[5, 7]
     //[3, 6] [4, 10]  下一个为[5, 11] 重叠两次，应该把[5,11] 丢掉
     //[3, 4] [6, 10] 直接插入, 出现[5, 7]的不可能
      sort(intervals.begin(), intervals.end());
     
      multiset<pair<int, int> , Comp> mSet;
      mSet.insert(intervals[0]);
      mSet.insert(intervals[1]);
      for(int i = 2; i < N; ++i){
          auto iter = --mSet.end();
          auto iter2 = iter; --iter2;
          if(iter2->second >= intervals[i].first){
              if(iter->second > intervals[i].second){
                  mSet.erase(iter);
                  mSet.insert(intervals[i]);
              }
          }else{
              mSet.insert(intervals[i]);
          }
      }
      cout << mSet.size() << "\n";
   }
   return 0;
}

