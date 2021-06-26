//
// Created by Jolen on 2021/6/26.
//


//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int change(int amount, vector<int> &coins) {
    vector<int> memo(amount + 1, 0);
        memo[0] = 1;
    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j)
                memo[j] = memo[j - coins[i - 1]] + memo[j];
        }
    }
    return memo[amount];
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    coins.erase(coins.begin(),coins.begin()+2);
    for(int i:coins)
        cout<<i<<" ";
    cout<<endl;
//    cout << change(amount, coins);
}