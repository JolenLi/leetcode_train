//
// Created by Jolen on 2021/6/20.
//


#include<map>
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int i = 0, j = height.size()-1;
    int maxArea = 0;
    while (i < j) {
        int area = (j-i)*min(height[i],height[j]);
        maxArea = max(maxArea, area);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    cout<<maxArea<<endl;

}