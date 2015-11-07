#include <cmath>
#include <memory.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <list>

using namespace std;

int nodeCount = 1;
int queryCount = 0;
unordered_map<string, int> nodeIds;
unordered_map<string, int> queryIds;
unordered_map<int, vector<int> > G;
unordered_map<int, int> father;
map<pair<int,int>, int> resultCache;
set<pair<int,int> > fatherChild;
vector<unordered_map<int, int> > resultCounts;
vector<int> queryNodes;
vector<int> queryToIds;
vector<string> questNodes;
vector<string> questions;


struct TreeNode{
    TreeNode *childs[256];
    int queryId;
    TreeNode(){
        queryId = -1;
        memset(childs, 0, sizeof(childs));
    }
    inline void setNode(char c, TreeNode *node){
        childs[c] = node;
    }
    inline TreeNode * getNode(char c){
        return childs[c];
    }
    
};

inline int getOrInsert(const string &s){
    auto iter = nodeIds.find(s);
    if(iter==nodeIds.end()){
        iter = nodeIds.insert(make_pair(s, nodeCount++)).first;
    }
    return iter->second;
}
inline int getOrQuery(const string &s){
    auto iter = queryIds.find(s);
    if(iter==queryIds.end()){
        iter = queryIds.insert(make_pair(s, queryCount++)).first;
    }
    return iter->second;
}
void parseTree(const string &s){
    stack<int >  sstack;
    int i, j;
    int start;
    int last;
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
            int id = getOrInsert(str);
            if(!sstack.empty()){
                //father[id] = sstack.top();
                G[sstack.top()].push_back(id);
            }
            last = id;
        }
        i = j;
    }
}
void addQuery(TreeNode *root, const string &s){
    TreeNode *node = root,*temp;
    for(int i = 0; i < s.size(); ++i){
        temp = node->getNode(s[i]);
        if(temp==NULL){
            temp = new TreeNode();
            node->setNode(s[i], temp);
        }
        node = temp;
    }
    node->queryId = getOrQuery(s);
}
inline bool isFather(int a, int b){
    while(b>0 && a!=b){
        b = father[b];
    }
    return a==b;
}
void applyQuestion(TreeNode *root,const string & node, const string &quest){
    TreeNode *cur = root;
    int queryId = -1;
    int nodeId = getOrInsert(node);
    for(int i = 0; i < quest.size() && cur; ++i){
        queryId = cur->queryId;
        if(queryId != -1)
            resultCounts[queryId][nodeId]++;
        cur = cur->getNode(quest[i]);
    }
    if(cur && cur->queryId!=-1){
        resultCounts[cur->queryId][nodeId]++;
    }
}

void parseQuestion(const string &s){
    int idx = s.find(":");
    const string &node = s.substr(0, idx);
    const string &question = s.substr(idx+2);
    questNodes.push_back(node);
    questions.push_back(question);
}
int findCount(int nodeId, int queryId, const unordered_map<int, int> & umap){
    pair<int, int> pr = make_pair(nodeId, queryId);
    auto it = resultCache.find(pr);
    if(it != resultCache.end()) return it->second;
    int ret = 0;
    auto iter = umap.find(nodeId);
    if(iter!=umap.end()) ret+= iter->second;
    for(auto i : G[nodeId]){
        ret+=findCount(i, queryId, umap);
    }
    resultCache[pr] = ret;
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
    /*for(auto iter = nodeIds.begin(); iter!=nodeIds.end(); ++iter){
        cout<<iter->first<<" "<<iter->second;
        cout<<" "<<father[iter->second]<<endl;
    }*/

    cin>>M;
    cin.get();
    int i,j;
    TreeNode *root = new TreeNode();
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
        addQuery(root, prefix);
        queryNodes.push_back(getOrInsert(node));
        queryToIds.push_back(getOrQuery(prefix));
        //cout<<prefix<<" "<<queryToIds.back()<<endl;
    }


    resultCounts.resize(K);

    for(i = 0; i < questions.size(); ++i){
        applyQuestion(root, questNodes[i], questions[i]);
    }
    int res;
    for(i = 0; i < K; ++i){
        res = 0;
        int queryNodeId = queryNodes[i];
        const unordered_map<int, int> &umap = resultCounts[queryToIds[i]];
        /*for(auto iter = umap.begin(); iter!=umap.end(); ++iter)
            if(isFather(queryNodeId, iter->first)){
                res += iter->second;
            }
        */
        res = findCount(queryNodeId, queryToIds[i], umap);

        cout<<res<<endl;
    }
    return 0;
}

