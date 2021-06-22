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
void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for(int i=0;i<size/2;i++)
        for(int j=0;j<size/2.0;j++) {
            int start = matrix[i][j];
            int r=i,c=j;
            for (int x = 0; x < 4; x++) {
                int temp = start;
                start = matrix[c][size -1 - r];
                matrix[c][size -1 - r] = temp;
                temp = r;
                r = c;
                c = size-1-temp;
            }
        }
    cout<<endl;
    for(auto i:matrix)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(auto i:matrix)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    rotate(matrix);

}
