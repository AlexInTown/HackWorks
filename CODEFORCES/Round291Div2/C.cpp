#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

const int HASH_MOD = 31;
const int NUM_CHAR = 3;

vector<int> nums;
map<int, vector<int> > mhash;

//采用hash
int CalHash(int len, vector<int> & cnt){
    return len%HASH_MOD*pow(HASH_MOD,3)
        + (cnt[0]%HASH_MOD)*HASH_MOD*HASH_MOD
        + cnt[1]%HASH_MOD * HASH_MOD + cnt[2] %HASH_MOD;
}
//遍历可能的情况
void CalDisplay(int len, int id,  int* offset, int cur){
    int i;
    if(cur==NUM_CHAR-1){
        ///printf("off %d %d %d\n", offset[0], offset[1], offset[2]);
        vector<int> temp(nums);

        //printf("temp %d %d %d\n", temp[0], temp[1], temp[2]);
        for(i = 0; i < NUM_CHAR; ++i){
            temp[i] += offset[i];
            if(temp[i] < 0 || temp[i] > len) return;
        }

        //printf("%d %d %d\n", temp[0], temp[1], temp[2]);
        //printf("%d\n", CalHash(len, temp));

        mhash[CalHash(len, temp)].push_back(id);
        return;
    }
    for(i = cur; i < NUM_CHAR; ++i){
        swap(offset[cur], offset[i]);
        CalDisplay(len, id, offset, cur+1);
        swap(offset[cur], offset[i]);
    }
}
//计算查找时的hash值
int CalQueryHash(const string &s){
    int ia,ib,ic;
    ia = 0; ib = 0; ic =0;
    int i;
    for(i = 0; i < s.size(); ++i){
        if(s[i]=='a') ia ++;
        else if(s[i] == 'b') ib++;
        else ic++;
    }
    return s.size()%HASH_MOD*pow(HASH_MOD,3)
        + (ia%HASH_MOD)*HASH_MOD*HASH_MOD
        + ib%HASH_MOD * HASH_MOD + ic %HASH_MOD;
}
//进一步核对
bool check(const string &a, const string &b){
    if(a.size() != b.size()) return false;
    int i;
    int mis_cnt = 0;
    for(i = 0; i < a.size() && mis_cnt < 2; ++i){
        if(a[i]!=b[i]) mis_cnt++;
    }
    return mis_cnt < 2;
}

int main()
{
    int N, M;
    cin>>N>>M;
    int i, j;
    string s;
    vector<string> strs;
    int ia, ib, ic;
    for(i = 0; i < N; ++i){
        cin>>s;
        strs.push_back(s);
        int offset[] = {-1, 0, 1};
        nums.clear();
        nums.resize(NUM_CHAR, 0);
        for(j = 0; j < s.size(); ++j){
            if(s[j]=='a') nums[0]++;
            else if(s[j]=='b') nums[1]++;
            else nums[2]++;
        }
        CalDisplay(s.size(), i, offset, 0); 
    }
    
    for(i = 0; i < M; ++i){
        cin>>s;
        int h = CalQueryHash(s);
        if(mhash.count(h)==0){
            cout<<"NO"<<endl;
        }else{
            vector<int> &ids = mhash[h];
            bool res = false;
            for(j = 0; j < ids.size(); ++j){
                if(check(s, strs[ids[j]])){
                    res = true;
                    break;
                }
            }
            if(res){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }   
        }
    }

    return 0;
}
