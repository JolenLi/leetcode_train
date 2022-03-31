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

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> row(9,vector<int>(9,0));
    vector<vector<int>> col(9,vector<int>(9,0));
    vector<vector<int>> box(9,vector<int>(9,0));
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board.size();j++)
        {
            int num = board[i][j]-'1';
            if(row[i][num]||col[j][num]||box[(i/3)*3+j/3][num])
                return false;
            row[i][num]=1;
            col[j][num]=1;
            box[(i/3)*3+j/3][num]=1;
        }
    return true;
}

int main() {
    vector<int> nums = {1, 2, 0, 3, 1, 2};
    isValidSudoku(nums);
}
