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


int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, INT_MAX));
    memo[1][1] = grid[0][0];
    for (int j = 2; j <= n; j++)
        memo[1][j] = memo[1][j - 1] + grid[0][j - 1];
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + grid[i - 1][j - 1];
        }
    return memo[m][n];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << minPathSum(grid) << endl;
}

