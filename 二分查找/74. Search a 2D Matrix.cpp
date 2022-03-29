//
// Created by Jolen on 2022/3/28.
//

bool searchMatrix(vector <vector<int>> &matrix, int target) {
    int lo = 0, hi = matrix.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (matrix[mid][0] == target) {
            return true;
        } else if (matrix[mid][0] < target)
            lo = mid + 1;
        else if (matrix[mid][0] > target)
            hi = mid;
    }

    int row = lo - 1;
    if (row < 0)return false;
    lo = 0, hi = matrix[0].size();

    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            lo = mid + 1;
        else if (matrix[row][mid] > target)
            hi = mid;
    }
    return false;
}



bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int lo =0,hi = m*n;
    while(lo<hi){
        int mid = lo+((hi-lo)>>1);
        int row = mid/n,col = mid%n;
        if(matrix[row][col]==target)
            return true;
        else if(matrix[row][col]<target)
            lo = mid+1;
        else if(matrix[row][col]>target)
            hi = mid;
    }
    return false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int i=0,j=n-1;
    while(i>=0&&i<m&&j>=0&&j<n){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]<target)
            i++;
        else if(matrix[i][j]>target)
            j--;
    }
    return false;
}