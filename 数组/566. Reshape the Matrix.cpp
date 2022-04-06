//
// Created by Jolen on 2021/6/22.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;


vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int x = mat.size(), y = mat[0].size();
    if (x * y != r * c)return mat;
    int n = x * y;
    vector<vector<int>> ans(r, vector<int>(c, 0));
    for (int i = 0; i < n; i++)
        ans[i / c][i % c] = mat[i / y][i % y];
    return ans;
}


int main() {

}
