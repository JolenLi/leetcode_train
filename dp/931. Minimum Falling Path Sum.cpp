//
// Created by Jolen on 2021/6/23.
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

int init = 200000;
int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
int dp(const vector<vector<int>> &matrix, vector<vector<int>> &memo, int row, int col) {
    int n = matrix.size();
    if (row >= n || row < 0 || col >= n || col < 0)
        return INT_MAX;
    if(memo[row][col]!=init)
        return memo[row][col];
    memo[row][col] = matrix[row][col] + min(dp(matrix, memo, row + 1, col - 1), dp(matrix, memo, row + 1, col),
                                            dp(matrix, memo, row + 1, col + 1));

    return memo[row][col];
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    vector<vector<int>> memo(matrix.size(), vector<int>(matrix.size(), init));
    int n = matrix.size();

    for (int i = 0; i < n; i++)
        memo[n-1][i] = matrix[n-1][i];

    for (int i = 0; i < n; i++)
        memo[0][i] = dp(matrix, memo, 0, i);

    int mini = memo[0][0];
    for (int i:memo[0])
        mini = min(i, mini);
    return mini;
}

int main() {
    vector<vector<int>> matrix = {{2, 1, 3},
                                  {6, 5, 4},
                                  {7, 8, 9}};
    cout<<minFallingPathSum(matrix)<<endl;
}