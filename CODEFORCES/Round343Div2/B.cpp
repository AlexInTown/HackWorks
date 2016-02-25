#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <map>
#include <vector>
using namespace std;
struct Node{
    bool male;
    bool in;
};
map<int, vector<Node> > mm;


int main(){
    int n;
    cin>>n;
    int i;
    char val;
    int start, end;
    Node node;
    for(i = 0; i < n; ++i)
    {
        cin>>val>>start>>end;
        if(val=='M'){
            node.male = 1;
        }else{
            node.male = 0;
        }
        node.in = 1;
        mm[start].push_back(node);
        node.in = 0;
        mm[end+1].push_back(node);
    }
    int mcnt = 0, fcnt = 0;
    int res = 0;
    for(map<int, vector<Node> > :: iterator iter  = mm.begin(); 
        iter  != mm.end(); ++iter){
            vector<Node> & vn = iter->second;
            for(i = 0; i < vn.size() ;++i){
                if(vn[i].in){
                    if(vn[i].male)
                        mcnt ++;
                    else
                        fcnt ++;
                }else{
                    if(vn[i].male)
                        mcnt --;
                    else
                        fcnt --;
                }
            }
            res = max(min(mcnt, fcnt), res);
        }
    cout<<res*2<<endl;

    return 0;
}
