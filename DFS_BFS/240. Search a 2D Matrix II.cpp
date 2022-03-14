//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int i=0,j=n-1;
    while(i<m&&j>=0){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]<target)
            i++;
        else if(matrix[i][j]>target)
            j--;
    }
    return false;
}
int main() {
    vector<vector<int>>m = {{{-1,3}}};
    cout<<searchMatrix(m,3)<<endl;
}