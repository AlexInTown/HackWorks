#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<string, list<string> > questions;
unordered_map<string, list<string> > childs;
/*
struct TrieNode{
    TrieNode * childs[52];
    int count;
    char val;
    TrieNode(char c){
        memset(childs, 0, sizeof(childs));
        count = 0;
        val = c;
    }
    void setNode(char c, TreeNode *node){
        if(c >= 'a' && c < 'z') childs[c-'a'] = node;
        else if(c >= 'A' && c < 'Z') childs[c-'A'+26] = node;
        else {perror("invalid char value!"); exit(-1);}
    }
    TreeNode * getNode(char c){
        if(c >= 'a' && c < 'z') return childs[c-'a'];
        else if(c >= 'A' && c < 'Z') return childs[c-'A'+26];
        else {perror("invalid char value!"); return NULL;}
    }
};
*/

void parseTree(const string &s){
    stack<string>  sstack;
    int i, j;
    int start;
    string last;
    for(i = 0; i < s.size(); ){
        for(j = i; j < s.size() && s[j]==' '; ++j);
        start = j;
        for(; j < s.size() && s[j]!=' '; ++j);
        const string & str = s.substr(start, j-start);
        if(str=="("){
            sstack.push(last);
        }else if(str==")"){
            sstack.pop();
        }else{
            if(!sstack.empty()){
                childs[sstack.top()].push_back(str);
            }
            last = str;
        }
        i = j;
    }
}
void parseQuestion(const string &s){
    int idx = s.find(":");
    const string &node = s.substr(0, idx);
    const string &question = s.substr(idx+2);
    questions[node].push_back(question);
}
typedef list<string>:: iterator ITER;
int findCount(const string &node, const string &prefix){
    list<string> & qs = questions[node];
    int ret = 0; 
    for(ITER iter = qs.begin(); iter != qs.end(); iter++)
        if(iter->compare(0, prefix.length(), prefix)==0) ret++;
    list<string> & chs = childs[node];
    for(ITER iter = chs.begin(); iter != chs.end(); iter ++)
        ret+=findCount(*iter, prefix);
    return ret;
}
int main() {
    int N, M, K;
    cin>>N;
    cin.get();
    string s;
    getline(cin, s);
    //cout<<"before parse tree"<<endl;
    parseTree(s);
    //cout<<"after parse tree"<<endl;

    cin>>M;
    cin.get();
    int i,j;
    for(i = 0; i < M; ++i){
        getline(cin, s);
        parseQuestion(s);
    }
    //cout<<"after parse questions"<<endl;
    cin>>K;
    cin.get();
    for(i = 0; i < K; ++i){
        getline(cin, s);
        //cout<<s<<endl;
        int idx = s.find(" ");
        const string &node = s.substr(0, idx);
        const string &prefix = s.substr(idx+1);
        //cout<<node<<" "<<prefix<<endl;
        cout<<findCount(node, prefix)<<endl;
    }
    return 0;
}

