#include <iostream>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
int minAB = min(a+b, c);
int minAC = min(b, a+c);
int minBC = min(a, b+c);
cout<<(minAB+minAC+minBC)<<endl;
return 0;
}
