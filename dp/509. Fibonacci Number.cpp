//
// Created by Jolen on 2021/6/23.
//

//// dp

#include<vector>
#include<iostream>
using namespace std;
vector<int> dp;
int fib(int n) {
    dp.push_back(0);
    dp.push_back(1);
    for(int i=2;i<=n;i++)
        dp.push_back(dp[i-1]+dp[i-2]);
    return dp[n];
}













int main()
{
    cout<<fib(30)<<endl;
}