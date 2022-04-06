//
// Created by Jolen on 2022/4/6.
//

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


bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int r=matrix.size(),c=matrix[0].size();
    int lo=0,hi=r*c-1;
    while(lo<=hi){
        int mid = lo+((hi-lo)>>1);
        if(matrix[mid/c][mid%c]==target) return true;
        else if(matrix[mid/c][mid%c]<target) lo = mid+1;
        else hi=mid-1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int x = 0, y = matrix[0].size() - 1;
    while (x < matrix.size() && y >= 0) {
        if (matrix[x][y] == target)     return true;
        else if (matrix[x][y] < target) x++;
        else if (matrix[x][y] > target) y--;
    }
    return false;
}
int main() {

}
