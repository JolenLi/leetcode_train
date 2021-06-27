//
// Created by Jolen on 2021/6/27.
//

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

int integerBreak(int n) {
    vector<int> memo(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            memo[i] = max(memo[i], max(memo[i - j],i-j) * j);
        }
    }
    return memo[n];
}

int main() {
    cout << integerBreak(10) << endl;
}

