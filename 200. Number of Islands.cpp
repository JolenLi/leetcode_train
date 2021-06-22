//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

void findIsland(vector<vector<char>> &grid, int i, int j) {

    queue<pair<int, int>> list;
    int r = grid.size();
    int c = grid[0].size();
    list.push({i, j});
    grid[i][j] = '0';

    while (!list.empty()) {
        auto cur = list.front();
        list.pop();
        int row = cur.first, col = cur.second;

        if (row > 0 && grid[row - 1][col] == '1') {
            list.push({row - 1, col});
            grid[row - 1][col] = '0';
        }

        if (row < r - 1 && grid[row + 1][col] == '1') {
            list.push({row + 1, col});
            grid[row + 1][col] = '0';
        }

        if (col > 0 && grid[row][col - 1] == '1') {
            list.push({row, col - 1});
            grid[row][col - 1] = '0';
        }

        if (col < c - 1 && grid[row][col + 1] == '1') {
            list.push({row, col + 1});
            grid[row][col + 1] = '0';
        }
    }
}
//bfs
//int numIslands(vector<vector<char>> &grid) {
//
//    int nr = grid.size();
//    int nc = grid[0].size();
//
//    int num = 0;
//    for (int i = 0; i < nr; i++) {
//        for (int j = 0; j < nc; j++) {
//            if (grid[i][j] == '1') {
//                findIsland(grid, i, j);
//                num++;
//            }
//        }
//    }
//    return num;
//}


//dfs
void dfs(vector<vector<char>> &grid, int i, int j) {
    int r = grid.size();
    int c = grid[0].size();
    grid[i][j] = 0;
    if (i > 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
    if (i < r - 1 && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
    if (j > 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
    if (j < c - 1 && grid[i][j + 1] == '1') dfs(grid, i, j + 1);

}

int numIslands(vector<vector<char>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    int nums = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                nums++;
                dfs(grid, i, j);
            }
        }
    }
}