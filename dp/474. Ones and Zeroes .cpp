

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

/*     符合条件
  *     memo[i][j][k] = max(memo[i-1][j-m][k-n]+1, memo[i-1][m][n]);
  *     不符合
  *     memo[i][j][k] = memo[i-1][m][n];
  *
  * */
int findMaxForm(vector<string> &strs, int m, int n) {
    //// memo[i][j][k]  前i个数字，在j，k中最大值；

    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

    for (string str:strs) {
        int ans[2] = {0, 0};
        for (char i : str) {
            ans[i - '0']++;
        }
        int mm = ans[0], nn = ans[1];

        for (int j = m; j >= mm; j--)
            for (int k = n; k >= nn; k--)
                memo[j][k] = max(memo[j - mm][k - nn] + 1, memo[j][k]);

    }
    return memo[m][n];
}

int main() {

    vector<string> strs = {"10", "1", "0"};
    int m = 1, n = 1;

    cout << findMaxForm(strs, m, n) << endl;
}