//
// Created by Jolen on 2021/6/25.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;


bool check(vector<int> &nums, int n) {
    int cnt = 0;
    for (auto &num:nums) {
        if (num >= n)
            cnt++;
    }
    return cnt >= n;
}

int hIndex(vector<int> &citations) {
    int lo = 0, hi = citations.size() + 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (check(citations, mid))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo - 1;
}

//
//int hIndex(vector<int> &citations) {
//    int N = citations.size();
//    vector<int> count(N + 1, 0);
//    for (auto &cite:citations) {
//        if (cite > N) cite = N;
//        count[cite]++;
//    }
//
//    int cnt = 0;
//    for (int i = citations.size(); i >= 0; i--) {
//        cnt += count[i];
//        if (cnt >= i)
//            return i;
//    }
//    return 0;
//}


int main() {
    vector<int> nums = {4, 5, 6, 7, 8};
    cout << hIndex(nums) << endl;
}