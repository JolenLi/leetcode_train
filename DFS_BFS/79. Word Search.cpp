//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>

using namespace std;

//vector<vector<set<int>>> visited;
vector<vector<bool>> used;

bool dfs(vector<vector<char>> &board, string word, int i, int j, int idxWord) {
    if (idxWord == word.size())
        return true;
    int n = board.size(), m = board[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m)return false;
    if (used[i][j])return false;
//    if (visited[i][j].count((idxWord)))return false;
//    visited[i][j].insert(idxWord);
    if (word[idxWord] == board[i][j]) {
        used[i][j] = true;
        bool flag = dfs(board, word, i + 1, j, idxWord + 1) ||
                    dfs(board, word, i - 1, j, idxWord + 1) ||
                    dfs(board, word, i, j + 1, idxWord + 1) ||
                    dfs(board, word, i, j - 1, idxWord + 1);
        used[i][j] = false;
        return flag;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
//    visited = vector<vector<set<int>>>(board.size(), vector<set<int>>(board[0].size()));
    used = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), 0));
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dfs(board, word, i, j, 0))
                return true;
    return false;
}


int main() {

}