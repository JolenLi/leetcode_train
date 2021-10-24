//
// Created by Jolen on 2021/10/24.
//


#include <bits/stdc++.h>

using namespace std;
int canFinish(vector<int>& weight,int days,int maxK){
    int d=1,k=0;
    for(auto w:weight){
        if(k+w>maxK){
            d++;
            k=w;
        }else{
            k+=w;
        }
    }

    return d<=days;
}
int splitArray(vector<int>& nums, int m) {
    int lo=0,hi=0;
    for(const auto &w:nums){
        lo = max(lo,w);
        hi+=w;
    }
    while(lo<=hi){
        int mid=lo+((hi-lo)>>1);
        if(canFinish(nums,m,mid))
            hi=mid-1;
        else
            lo=mid+1;
    }
    return lo;
}
int main() {
    vector<int> piles = {7,2,5,10,8};
    int h = 2;
    cout << splitArray(piles, h) << endl;

}