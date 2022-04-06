//
// Created by Jolen on 2022/4/6.
//

class Solution {
public:

    bool check(vector<vector<int>>& matrix,int i,int j,int target) {
        int x=matrix.size(),y=matrix[0].size();
        if(i>=x||j>=y)return true;
        if(matrix[i][j]!=target)return false;
        return check(matrix,i+1,j+1,target);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            if(!check(matrix,i,0,matrix[i][0]))
                return false;
        }
        for(int j=0;j<matrix[0].size();j++){
            if(!check(matrix,0,j,matrix[0][j]))
                return false;
        }
        return true;
    }
};