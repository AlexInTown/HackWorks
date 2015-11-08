#include <iostream>
#include <memory.h>
using namespace std;
/*题意：两个正整数N和M，将N拆分成k个不相等的正整数，这些正整数的乘积是M的倍数。像这样的拆法有多少种？*/
/*先看看有没有子问题，将M拆成多个因子的乘积，子问题不太好拆*/
/* 因为M拆成不同的因子，假如有两部分，对应的两套正整数可能有相等的，这样不符合要求 */
/* 描述成一个搜索问题: 第一种方法，从M的质因子到N；第二种方法，从N的拆分直接尝试能否被M整除 */
/* 第二种方法是最简便直接的，唯一的坑在于 prod 可能越界 10^10超出了范围*/


int N, M;

int count = 0;

void search(int cur, int prevA, long long prod){
    if(cur==0 && prod % M == 0) count ++;
    for(int i = prevA+1; i <= cur; ++i){
        search(cur-i,  i, prod*i);
    }
}

int main()
{
    cin>>N>>M;
    search(N, 0, 1);
    cout<<count<<endl;
    return 0;
}
