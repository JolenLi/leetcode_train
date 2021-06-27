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

int uniquePaths(int m, int n) {
    vector<int> memo(n + 1, 1);
    memo[0] = 0;
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++)
            memo[j] += memo[j - 1];
    return memo[n];
}

//int uniquePaths(int m, int n) {
//    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
//    for (int j = 1; j <= n; j++)
//        memo[1][j] = 1;
//    for (int i = 2; i <= m; i++)
//        for (int j = 1; j <= n; j++) {
//            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
//        }
//    return memo[m][n];
//}

int main() {

    cout << uniquePaths(3, 2) << endl;
}

