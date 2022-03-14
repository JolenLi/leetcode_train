//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int N = m+n;
    int r1 = m,r2 = n;
    while(r2>0){
        if(r1<=0||nums1[r1-1]<nums2[r2-1]){
            nums1[r1+r2-1] = nums2[r2-1];
            r2--;
        }
        else if(nums1[r1-1]>=nums2[r2-1]){
            nums1[r1+r2-1] = nums1[r1-1];
            r1--;
        }
    }
    return ;
}
int main() {
    vector<int>nums1 = {1,2,3,0,0,0},nums2 = {2,5,6};
    int m = 3,n = 3;
    merge(nums1,3,nums2,3);
    for(auto i:nums1)
        cout<<i<<" ";
    cout<<endl;
}