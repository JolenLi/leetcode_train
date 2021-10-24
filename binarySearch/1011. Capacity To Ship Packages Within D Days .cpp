//
// Created by Jolen on 2021/10/24.
//

//
// Created by Jolen on 2021/10/24.
//

//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;
int canFinish(vector<int>& weight,int days,int maxK){
    int d=0,k=0;
    for(auto w:weight){
        if(k+w>maxK){
            d++;
            k=w;
        }else{
            k+=w;
        }
    }
    d++;
//    if(k)d++;
    return d<=days;
}
int shipWithinDays(vector<int>& weights, int days) {410. Split Array Largest Sum
    int lo=0,hi=0;
    for(const auto &w:weights){
        lo = max(lo,w);
        hi+=w;
    }
    while(lo<=hi){
        int mid=lo+((hi-lo)>>1);
        if(canFinish(weights,days,mid))
            hi=mid-1;
        else
            lo=mid+1;
    }
    return lo;
}
int main() {
    vector<int> piles = {1,2,3,4,5,6,7,8,9,10};
    int h = 5;
    cout << shipWithinDays(piles, h) << endl;

}